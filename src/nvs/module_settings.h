#ifndef __MODULE_SETTINGS_H
#define __MODULE_SETTINGS_H

#include <stdint.h>
#include <tcu_maths.h>
#include <esp_err.h>

// TCC Settings

#define TCC_SETTINGS_NVS_KEY "TCC_A2"
typedef struct {
    bool adapt_enable;
    bool enable_d1;
    bool enable_d2;
    bool enable_d3;
    bool enable_d4;
    bool enable_d5;
    uint16_t prefill_pressure;
    uint16_t lock_rpm_threshold;
    uint16_t min_locking_rpm;
    uint16_t adjust_interval_ms;
    uint16_t tcc_stall_speed;
    uint16_t min_torque_adapt;
    uint16_t max_torque_adapt;
    uint16_t prefill_min_engine_rpm;
    uint16_t base_pressure_offset_start_ramp;
    LinearInterpSetting pressure_increase_ramp_settings;
    uint8_t adapt_pressure_inc;
    uint16_t adapt_lock_detect_time;
    uint16_t pulling_slip_rpm_low_threshold;
    uint16_t pulling_slip_rpm_high_threhold;
    float reaction_torque_multiplier;
    uint16_t trq_consider_coasting;
    LinearInterpSetting load_dampening;
    LinearInterpSetting pressure_multiplier_output_rpm; 
    uint16_t max_allowed_bite_pressure;
    uint16_t max_allowed_pressure_longterm;
} __attribute__ ((packed)) TCC_MODULE_SETTINGS;

const TCC_MODULE_SETTINGS TCC_DEFAULT_SETTINGS = {
    .adapt_enable = true,
    .enable_d1 = true,
    .enable_d2 = true,
    .enable_d3 = true,
    .enable_d4 = true,
    .enable_d5 = true,
    .prefill_pressure = 500,
    .lock_rpm_threshold = 50,
    .min_locking_rpm = 1100,
    .adjust_interval_ms = 500,
    .tcc_stall_speed = 2500,
    .min_torque_adapt = 50,
    .max_torque_adapt = 110,
    .prefill_min_engine_rpm = 900,
    .base_pressure_offset_start_ramp = 300,
    .pressure_increase_ramp_settings = {
        .new_min = 1,
        .new_max = 5,
        .raw_min = 100,
        .raw_max = 1000,
    },
    .adapt_pressure_inc = 10,
    .adapt_lock_detect_time = 2000,
    .pulling_slip_rpm_low_threshold = 20,
    .pulling_slip_rpm_high_threhold = 100,
    .reaction_torque_multiplier = 1.5,
    .trq_consider_coasting = 40,
    .load_dampening = {
        .new_min = 100,
        .new_max = 50,
        .raw_min = -40,
        .raw_max = 40,
    },
    .pressure_multiplier_output_rpm = {
        .new_min = 1.00,
        .new_max = 1.25,
        .raw_min = 1500,
        .raw_max = 2500,
    },
    .max_allowed_bite_pressure = 1800,
    .max_allowed_pressure_longterm = 7000,
};

#define SOL_SETTINGS_NVS_KEY "SOL_A0"

typedef struct {
    uint16_t min_batt_power_on_test;
    uint16_t current_threshold_error;
    uint16_t cc_vref_solenoid;
    float cc_temp_coefficient_wires;
    float cc_reference_resistance;
    float cc_reference_temp;
    float cc_max_adjust_per_step;
} __attribute__ ((packed)) SOL_MODULE_SETTINGS;

const SOL_MODULE_SETTINGS SOL_DEFAULT_SETTINGS = {
    .min_batt_power_on_test = 11000,
    .current_threshold_error = 500,
    .cc_vref_solenoid = 12000,
    .cc_temp_coefficient_wires = 0.393,
    .cc_reference_resistance = 5.3,
    .cc_reference_temp = 25,
    .cc_max_adjust_per_step = 2
};

#define SBS_SETTINGS_NVS_KEY "SBS_A0"

typedef struct {
    uint16_t shift_solenoid_pwm_reduction_time;
    uint16_t delta_rpm_flare_detect;
    bool f_shown_if_flare;
    bool torque_request_upshift;
    bool torque_request_downshift;
    bool upshift_use_driver_torque_as_input;
    bool downshift_use_driver_torque_as_input;
    uint16_t torque_request_downramp_percent;
    uint16_t torque_request_hold_percent;
    LinearInterpSetting torque_reduction_factor_input_torque;
    LinearInterpSetting torque_reduction_factor_shift_speed;
    uint16_t min_spc_delta_mpc;
    uint16_t stationary_shift_hold_time;
    uint16_t shift_timeout_pulling;
    uint16_t shift_timeout_coasting;
} __attribute__ ((packed)) SBS_MODULE_SETTINGS;

const SBS_MODULE_SETTINGS SBS_DEFAULT_SETTINGS = {
    .shift_solenoid_pwm_reduction_time = 1000,
    .delta_rpm_flare_detect = 20,
    .f_shown_if_flare = false,
    .torque_request_upshift = true,
    .torque_request_downshift = false,
    .upshift_use_driver_torque_as_input = false,
    .downshift_use_driver_torque_as_input = false,
    .torque_request_downramp_percent = 25,
    .torque_request_hold_percent = 50,
    .torque_reduction_factor_input_torque = {
        .new_min = 0.3,
        .new_max = 0.2,
        .raw_min = 100,
        .raw_max = 400,
    },
    .torque_reduction_factor_shift_speed = {
        .new_min = 1.3,
        .new_max = 1.0,
        .raw_min = 100,
        .raw_max = 1000,
    },
    .min_spc_delta_mpc = 100,
    .stationary_shift_hold_time = 1000,
    .shift_timeout_pulling = 3000,
    .shift_timeout_coasting = 5000,
};

#define NAG_SETTINGS_NVS_KEY "NAG_A0"

typedef struct {
    uint16_t max_torque;
    float ratio_1;
    float ratio_2;
    float ratio_3;
    float ratio_4;
    float ratio_5;
    float ratio_r1;
    float ratio_r2;
    uint8_t power_loss_1;
    uint8_t power_loss_2;
    uint8_t power_loss_3;
    uint8_t power_loss_4;
    uint8_t power_loss_5;
    uint8_t power_loss_r1;
    uint8_t power_loss_r2;
} __attribute__ ((packed)) NAG_SETTINGS;

typedef struct {
    uint8_t max_drift_1;
    uint8_t max_drift_2;
    uint8_t max_drift_3;
    uint8_t max_drift_4;
    uint8_t max_drift_5;
    uint8_t max_drift_r1;
    uint8_t max_drift_r2;
    NAG_SETTINGS small_nag;
    NAG_SETTINGS large_nag;
} __attribute__ ((packed)) NAG_MODULE_SETTINGS;

const NAG_MODULE_SETTINGS NAG_DEFAULT_SETTINGS = {
    .max_drift_1 = 10,
    .max_drift_2 = 10,
    .max_drift_3 = 9,
    .max_drift_4 = 8,
    .max_drift_5 = 5,
    .max_drift_r1 = 10,
    .max_drift_r2 = 10,
    .small_nag = {
        .max_torque = 330,
        .ratio_1 = 3.951,
        .ratio_2 = 2.423,
        .ratio_3 = 1.486,
        .ratio_4 = 1.000,
        .ratio_5 = 0.833,
        .ratio_r1 = -3.147,
        .ratio_r2 = -1.930,
        .power_loss_1 = 10,
        .power_loss_2 = 10,
        .power_loss_3 = 10,
        .power_loss_4 = 10,
        .power_loss_5 = 10,
        .power_loss_r1 = 10,
        .power_loss_r2 = 10,
    },
    .large_nag = {
        .max_torque = 580,
        .ratio_1 = 3.595,
        .ratio_2 = 2.186,
        .ratio_3 = 1.405,
        .ratio_4 = 1.000,
        .ratio_5 = 0.831,
        .ratio_r1 = -3.167,
        .ratio_r2 = -1.926,
        .power_loss_1 = 10,
        .power_loss_2 = 10,
        .power_loss_3 = 10,
        .power_loss_4 = 10,
        .power_loss_5 = 10,
        .power_loss_r1 = 10,
        .power_loss_r2 = 10,
    }
};

#define PRM_SETTINGS_NVS_KEY "PRM_A0"

typedef struct {
    uint16_t max_spc_pressure;
    uint16_t max_mpc_pressure;
    uint16_t max_line_pressure;
    LinearInterpSetting engine_rpm_pressure_multi;
    float k1_pressure_multi;
    
} __attribute__ ((packed)) PRM_MODULE_SETTINGS;

const PRM_MODULE_SETTINGS PRM_DEFAULT_SETTINGS = {
    .max_spc_pressure = 7000,
    .max_mpc_pressure = 7000,
    .max_line_pressure = 15000,
    .engine_rpm_pressure_multi = {
        .new_min = 1.0,
        .new_max = 1.5,
        .raw_min = 1000,
        .raw_max = 6000,
    },
    .k1_pressure_multi = 2.0
};

#define ADP_SETTINGS_NVS_KEY "ADP_A0"

typedef struct {
    int16_t min_atf_temp;
    int16_t max_atf_temp;
    uint16_t max_engine_rpm;
    //bool enable_d1_2;
    //bool enable_d2_3;
    //bool enable_d3_4;
    //bool enable_d4_5;
    //bool enable_d5_4;
    //bool enable_d4_3;
    
} __attribute__ ((packed)) ADP_MODULE_SETTINGS;

const ADP_MODULE_SETTINGS ADP_DEFAULT_SETTINGS = {
    .min_atf_temp = 60,
    .max_atf_temp = 110,
    .max_engine_rpm = 3000,
    //bool enable_d1_2;
    //bool enable_d2_3;
    //bool enable_d3_4;
    //bool enable_d4_5;
    //bool enable_d5_4;
    //bool enable_d4_3;
};

// module settings
extern TCC_MODULE_SETTINGS TCC_CURRENT_SETTINGS;
extern SOL_MODULE_SETTINGS SOL_CURRENT_SETTINGS;
extern SBS_MODULE_SETTINGS SBS_CURRENT_SETTINGS;
extern NAG_MODULE_SETTINGS NAG_CURRENT_SETTINGS;
extern PRM_MODULE_SETTINGS PRM_CURRENT_SETTINGS;
extern ADP_MODULE_SETTINGS ADP_CURRENT_SETTINGS;

// Setting IDx
#define TCC_MODULE_SETTINGS_SCN_ID 0x01
#define SOL_MODULE_SETTINGS_SCN_ID 0x02
#define SBS_MODULE_SETTINGS_SCN_ID 0x03
#define NAG_MODULE_SETTINGS_SCN_ID 0x04
#define PRM_MODULE_SETTINGS_SCN_ID 0x05
#define ADP_MODULE_SETTINGS_SCN_ID 0x06

namespace ModuleConfiguration {
    esp_err_t load_all_settings();
    esp_err_t reset_settings(uint8_t idx);
    esp_err_t write_settings(uint8_t module_id, uint16_t buffer_len, uint8_t* buffer);
    esp_err_t read_settings(uint8_t module_id, uint16_t* buffer_len, uint8_t** buffer);
}

#endif