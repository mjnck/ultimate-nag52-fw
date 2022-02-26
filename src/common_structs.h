#ifndef COMMON_STRUCTS_H__
#define COMMON_STRUCTS_H__

#include <stdint.h>
#include "solenoids/solenoids.h"

typedef int16_t pressure_map[11];

/**
 * @brief Gearbox sensor data
 * This structure gets passed between a lot of the gearbox
 * code and is used for decision making about pressures and gear
 * change behaviour
 * 
 */
typedef struct {
    /// Gearbox input RPM
    int input_rpm;
    /// Engine RPM
    int engine_rpm;
    /// Output shaft RPM
    int output_rpm;
    /// TCM voltage
    uint16_t voltage;
    /// Accelerator pedal position. 0-255
    uint8_t pedal_pos;
    /// Transmission oil temperature in Celcius
    int atf_temp;
    /// Current 'static' torque of the engine in Nm
    int static_torque;
    /// Engine torque limit maximum in Nm
    int max_torque;
    /// Engine torque limit minimum in Nm
    int min_torque;
    /// Torque converter slip RPM (Calculated)
    int tcc_slip_rpm;
    /// Last time the gearbox changed gear (in milliseconds)
    uint64_t last_shift_time;
    /// Current clock time in milliseconds
    uint64_t current_timestamp_ms;
    /// Is the brake pedal depressed?
    bool is_braking;
} SensorData;

/**
 * @brief A gearchange that a AbstractProfile can request
 * 
 */
enum class ProfileGearChange {
    /// Gear 1 to gear 2
    ONE_TWO,
    /// Gear 2 to gear 3
    TWO_THREE,
    /// Gear 3 to gear 4
    THREE_FOUR,
    /// Gear 4 to gear 5
    FOUR_FIVE,
    /// Gear 5 down to gear 4
    FIVE_FOUR,
    /// Gear 4 down to gear 3
    FOUR_THREE,
    /// Gear 3 down to gear 2
    THREE_TWO,
    /// Gear 2 down to gear 1
    TWO_ONE,
};

/**
 * @brief Shift data request structure
 * 
 */
typedef struct {
    /// The initial SPC PWM value to start the shift off. This should be the 'biting point' of the clutch packs
    uint16_t initial_spc_pwm;
    /// The intial MPC PWM value to start the shift off. This should allow for easy SPC movement, but not
    /// too little otherwise the gearbox will slip too much
    uint16_t mpc_pwm;
    /// Target time in milliseconds for the shift to complete
    uint16_t targ_ms;
    // Shift firmness feel. Valid range = 1 - 10 (Auto clamped if value is outside this range) - Higher = firmer shift
    float shift_firmness;
    // Shift speed factor. Valid range = 1 - 10 (Auto clamped if value is outside this range) - Higher = faster shift
    float shift_speed;
    /// The shift solenoid required to change gears
    Solenoid* shift_solenoid;
    /// Current gear the gearbox is in as an integer
    uint8_t targ_g;
    /// The requested gear the gearbox will change into as an integer
    uint8_t curr_g;
} ShiftData;

#pragma GCC diagnostic ignored "-Wmissing-field-initializers" // This is ALWAYS correctly initialized in pressure_manager.cpp
const ShiftData DEFAULT_SHIFT_DATA = { .initial_spc_pwm = 100, .mpc_pwm = 100, .targ_ms = 500, .shift_firmness = 1.0, .shift_speed = 5.0};

typedef struct {
    /**
     * @brief Did the gearbox change gears OK?
     * 
     */
    bool shifted;
    /**
     * @brief Ensures we were able to measure the output shaft speed.
     * When stationary, we assume the car shifted after 1000ms
     * 
     */
    bool measure_ok;
    /**
     * @brief Actual time taken to shift gears, as reported by shift_thread
     * 
     */
    int shift_time_ms;
    int targ_shift_time_ms;

    /**
     * @brief Flared? In upshifting, this is when input RPM jumps before falling back
     * in line. When downshifting, this is seen as input RPM falling before rising back
     * in line.
     */
    bool flared;

    /**
     * @brief Delta in output RPM during the gearchange
     * This defines if we were accelerating or decelerating
     */
    int d_output_rpm;

    bool torque_cut;

} ShiftResponse;

typedef struct {
    uint16_t target_shift_time_ms;
    // Valid range = 1 - 10 (Auto clamped if value is outside this range) - Higher = firmer shift
    float shift_firmness;
    // Valid range =  1 - 10 (Auto clamped if value is outside this range) - Higher = faster shift
    float shift_speed;
} ShiftCharacteristics;

#endif