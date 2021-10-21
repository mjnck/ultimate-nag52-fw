#include "scn.h"
#include "solenoids/solenoids.h"
#include "esp_log.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp32/ulp.h>
#include "speaker.h"
#include "sensors.h"
#include "canbus/can_egs52.h"
#include "gearbox.h"

#define NUM_PROFILES 5 // A, C, W, M, S

Gearbox* gearbox;

AgilityProfile* agility;
ComfortProfile* comfort;
WinterProfile* winter;
ManualProfile* manual;
StandardProfile* standard;

uint8_t profile_id = 0;
AbstractProfile* profiles[NUM_PROFILES];

bool setup_tcm()
{
    egs_can_hal = new Egs52Can("EGS52", 20);
    if (!egs_can_hal->begin_tasks()) {
        return false;
    }
    if (!Sensors::init_sensors()) {
        return false;
    }
    if(!init_all_solenoids()) {
        return false;
    }

    agility = new AgilityProfile();
    comfort = new ComfortProfile();
    winter = new WinterProfile();
    manual = new ManualProfile();
    standard = new StandardProfile();

    profiles[0] = standard;
    profiles[1] = comfort;
    profiles[2] = manual;
    profiles[3] = agility;
    profiles[4] = winter;


    gearbox = new Gearbox();
    if (!gearbox->start_controller()) {
        return false;
    }
    gearbox->set_profile(profiles[0]);
    return true;
}

void printer(void*) {
    spkr.send_note(500, 200, 250);
    spkr.send_note(1000, 200, 200);
    int atf_temp;
    int vbatt;
    bool parking;
    uint32_t n2;
    uint32_t n3;
    while(1) {
        uint64_t start = esp_timer_get_time();
        Sensors::read_atf_temp(&atf_temp);
        Sensors::read_vbatt(&vbatt);
        Sensors::parking_lock_engaged(&parking);
        n2 = Sensors::read_n2_rpm();
        n3 = Sensors::read_n3_rpm();
        uint32_t taken = (uint32_t)(esp_timer_get_time() - start);
        ESP_LOGI(
            "MAIN", 
            "Y3: %d mA, Y4: %d mA, Y5: %d mA, MPC: %d mA, SPC: %d mA, TCC: %d mA. Vbatt: %d mV, ATF: %d *C, Parking lock: %d. N2/N3: (%u/%u) RPM. TIME: %u",
            sol_y3->get_current_estimate(),
            sol_y4->get_current_estimate(),
            sol_y5->get_current_estimate(),
            sol_mpc->get_current_estimate(),
            sol_spc->get_current_estimate(),
            sol_tcc->get_current_estimate(),
            vbatt,
            atf_temp,
            parking,
            n2, n3,
            taken
        );
        vTaskDelay(1000);
    }
}

void input_manager(void*) {
    bool pressed = false;
    while(1) {
        bool down = egs_can_hal->get_profile_btn_press();
        if (down) {
            pressed = true;
        } else { // Released
            if (pressed) {
                pressed = false; // Released, do thing now
                if (egs_can_hal->get_shifter_position_ewm() == ShifterPosition::PLUS) {
                    gearbox->inc_subprofile();
                } else {
                    gearbox->set_profile(profiles[profile_id]);
                    profile_id++;
                    if (profile_id == NUM_PROFILES) {
                        profile_id = 0;
                    }
                }
            }
        }
        vTaskDelay(20);
    }
}

extern "C" void app_main(void)
{
    if (setup_tcm() == false) { // An error ocurred setting up the gearbox!
        // Activate limp!
        egs_can_hal->set_drive_profile(GearboxProfile::Failure);
        egs_can_hal->set_display_msg(GearboxMessage::VisitWorkshop);
    }
    xTaskCreate(input_manager, "INPUT_MANAGER", 8192, nullptr, 5, nullptr);
    xTaskCreate(printer, "PRINTER", 4096, nullptr, 2, nullptr);
}