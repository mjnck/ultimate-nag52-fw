
/**
* AUTOGENERATED BY convert.py
* DO NOT EDIT THIS FILE!
*
* IF MODIFICATIONS NEED TO BE MADE, MODIFY can_data.txt!
*
* CAN Defintiion for ECU 'MRM'
*/

#ifdef EGS52_MODE

#ifndef __ECU_MRM_H_
#define __ECU_MRM_H_

#include <stdint.h>
    
#define LRW_236_CAN_ID 0x0236
#define MRM_238_CAN_ID 0x0238

/** Identification steering wheel angle sensor */
enum class LRW_236h_LRWS_ID {
	INIT_PSBL = 0, // LRW sensor is initializable
	INIT_SELF = 1, // LRW sensor initializes itself
	INIT_MUST = 2, // (LRW sensor must be initialized)
	SNV = 3, // signal not available
};

/** Status steering wheel angle sensor */
enum class LRW_236h_LRWS_ST {
	OK = 0, // Steering wheel angle sensor I.o.
	INI = 1, // Steering wheel angle sensor not initialized
	ERR = 2, // steering wheel angle sensor faulty
	ERR_INI = 3, // steering wheel angle sensor faulty and not initialized
};



typedef union {
	uint64_t raw;

	/** Gets CAN ID of LRW_236 */
	uint32_t get_canid(){ return LRW_236_CAN_ID; }
    /** Sets Steering wheel angle */
    void set_LRW(uint16_t value){ raw = (raw & 0xc000ffffffffffff) | ((uint64_t)value & 0x3fff) << 48; }

    /** Gets Steering wheel angle */
    uint16_t get_LRW() { return (uint16_t)(raw >> 48 & 0x3fff); }
        
    /** Sets steering wheel angular velocity */
    void set_VLRW(uint16_t value){ raw = (raw & 0xffffc000ffffffff) | ((uint64_t)value & 0x3fff) << 32; }

    /** Gets steering wheel angular velocity */
    uint16_t get_VLRW() { return (uint16_t)(raw >> 32 & 0x3fff); }
        
    /** Sets Message counter */
    void set_BZ236h(uint8_t value){ raw = (raw & 0xffffffff0fffffff) | ((uint64_t)value & 0xf) << 28; }

    /** Gets Message counter */
    uint8_t get_BZ236h() { return (uint8_t)(raw >> 28 & 0xf); }
        
    /** Sets Identification steering wheel angle sensor */
    void set_LRWS_ID(LRW_236h_LRWS_ID value){ raw = (raw & 0xfffffffff3ffffff) | ((uint64_t)value & 0x3) << 26; }

    /** Gets Identification steering wheel angle sensor */
    LRW_236h_LRWS_ID get_LRWS_ID() { return (LRW_236h_LRWS_ID)(raw >> 26 & 0x3); }
        
    /** Sets Status steering wheel angle sensor */
    void set_LRWS_ST(LRW_236h_LRWS_ST value){ raw = (raw & 0xfffffffffcffffff) | ((uint64_t)value & 0x3) << 24; }

    /** Gets Status steering wheel angle sensor */
    LRW_236h_LRWS_ST get_LRWS_ST() { return (LRW_236h_LRWS_ST)(raw >> 24 & 0x3); }
        
    /** Sets CRC checksum byte 1 - 7 to SAE J1850 */
    void set_CRC236h(uint8_t value){ raw = (raw & 0xffffffffffffff00) | ((uint64_t)value & 0xff) << 0; }

    /** Gets CRC checksum byte 1 - 7 to SAE J1850 */
    uint8_t get_CRC236h() { return (uint8_t)(raw >> 0 & 0xff); }
        
} LRW_236;



typedef union {
	uint64_t raw;

	/** Gets CAN ID of MRM_238 */
	uint32_t get_canid(){ return MRM_238_CAN_ID; }
    /** Sets Tempomat selector lever unplausible */
    void set_WH_UP(bool value){ raw = (raw & 0xdfffffffffffffff) | ((uint64_t)value & 0x1) << 61; }

    /** Gets Tempomat selector lever unplausible */
    bool get_WH_UP() { return (bool)(raw >> 61 & 0x1); }
        
    /** Sets Operation variable speed limitation */
    void set_VMAX_AKT(bool value){ raw = (raw & 0xefffffffffffffff) | ((uint64_t)value & 0x1) << 60; }

    /** Gets Operation variable speed limitation */
    bool get_VMAX_AKT() { return (bool)(raw >> 60 & 0x1); }
        
    /** Sets Tempomatwatch Lever: "Setting and delaying Levo0" */
    void set_S_MINUS_B(bool value){ raw = (raw & 0xf7ffffffffffffff) | ((uint64_t)value & 0x1) << 59; }

    /** Gets Tempomatwatch Lever: "Setting and delaying Levo0" */
    bool get_S_MINUS_B() { return (bool)(raw >> 59 & 0x1); }
        
    /** Sets Tempomat selector lever: "Setting and Accelerating Level0" */
    void set_S_PLUS_B(bool value){ raw = (raw & 0xfbffffffffffffff) | ((uint64_t)value & 0x1) << 58; }

    /** Gets Tempomat selector lever: "Setting and Accelerating Level0" */
    bool get_S_PLUS_B() { return (bool)(raw >> 58 & 0x1); }
        
    /** Sets Cruise control lever: "Recovery" */
    void set_WA(bool value){ raw = (raw & 0xfdffffffffffffff) | ((uint64_t)value & 0x1) << 57; }

    /** Gets Cruise control lever: "Recovery" */
    bool get_WA() { return (bool)(raw >> 57 & 0x1); }
        
    /** Sets Tempomat selector lever: "Switch off" */
    void set_AUS(bool value){ raw = (raw & 0xfeffffffffffffff) | ((uint64_t)value & 0x1) << 56; }

    /** Gets Tempomat selector lever: "Switch off" */
    bool get_AUS() { return (bool)(raw >> 56 & 0x1); }
        
    /** Sets directional flashing right */
    void set_BLI_RE(bool value){ raw = (raw & 0xff7fffffffffffff) | ((uint64_t)value & 0x1) << 55; }

    /** Gets directional flashing right */
    bool get_BLI_RE() { return (bool)(raw >> 55 & 0x1); }
        
    /** Sets direction flash left */
    void set_BLI_LI(bool value){ raw = (raw & 0xffbfffffffffffff) | ((uint64_t)value & 0x1) << 54; }

    /** Gets direction flash left */
    bool get_BLI_LI() { return (bool)(raw >> 54 & 0x1); }
        
    /** Sets Tempomat selector lever Parity (straight parity) */
    void set_WH_PA(bool value){ raw = (raw & 0xffefffffffffffff) | ((uint64_t)value & 0x1) << 52; }

    /** Gets Tempomat selector lever Parity (straight parity) */
    bool get_WH_PA() { return (bool)(raw >> 52 & 0x1); }
        
    /** Sets Message counter */
    void set_BZ238h(uint8_t value){ raw = (raw & 0xfff0ffffffffffff) | ((uint64_t)value & 0xf) << 48; }

    /** Gets Message counter */
    uint8_t get_BZ238h() { return (uint8_t)(raw >> 48 & 0xf); }
        
    /** Sets Steering angle parity (straight parity) */
    void set_LW_PA(bool value){ raw = (raw & 0xffff7fffffffffff) | ((uint64_t)value & 0x1) << 47; }

    /** Gets Steering angle parity (straight parity) */
    bool get_LW_PA() { return (bool)(raw >> 47 & 0x1); }
        
    /** Sets Steering angle sensor: overflow */
    void set_LW_OV(bool value){ raw = (raw & 0xffffbfffffffffff) | ((uint64_t)value & 0x1) << 46; }

    /** Gets Steering angle sensor: overflow */
    bool get_LW_OV() { return (bool)(raw >> 46 & 0x1); }
        
    /** Sets Steering angle sensor: Code error */
    void set_LW_CF(bool value){ raw = (raw & 0xffffdfffffffffff) | ((uint64_t)value & 0x1) << 45; }

    /** Gets Steering angle sensor: Code error */
    bool get_LW_CF() { return (bool)(raw >> 45 & 0x1); }
        
    /** Sets Steering angle sensor: not initialized */
    void set_LW_INI(bool value){ raw = (raw & 0xffffefffffffffff) | ((uint64_t)value & 0x1) << 44; }

    /** Gets Steering angle sensor: not initialized */
    bool get_LW_INI() { return (bool)(raw >> 44 & 0x1); }
        
    /** Sets Steering angle sign */
    void set_LW_VZ(bool value){ raw = (raw & 0xfffff7ffffffffff) | ((uint64_t)value & 0x1) << 43; }

    /** Gets Steering angle sign */
    bool get_LW_VZ() { return (bool)(raw >> 43 & 0x1); }
        
    /** Sets steering angle */
    void set_LW(uint16_t value){ raw = (raw & 0xfffff800ffffffff) | ((uint64_t)value & 0x7ff) << 32; }

    /** Gets steering angle */
    uint16_t get_LW() { return (uint16_t)(raw >> 32 & 0x7ff); }
        
} MRM_238;



class ECU_MRM {
	public:
        /**
         * @brief Imports the CAN frame given the CAN ID, CAN Contents, and current timestamp
         *
         * Returns true if the frame was imported successfully, and false if import failed (Due to non-matching CAN ID).
         *
         * NOTE: The endianness of the value cannot be guaranteed. It is up to the caller to correct the byte order!
         */
        bool import_frames(uint64_t value, uint32_t can_id, uint64_t timestamp_now) {
            switch(can_id) {
                case LRW_236_CAN_ID:
                    LAST_FRAME_TIMES[0] = timestamp_now;
                    FRAME_DATA[0] = value;
                    return true;
                case MRM_238_CAN_ID:
                    LAST_FRAME_TIMES[1] = timestamp_now;
                    FRAME_DATA[1] = value;
                    return true;
                default:
                    return false;
            }
        }
        
        /** Sets data in pointer to LRW_236
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_LRW_236(uint64_t now, uint64_t max_expire_time, LRW_236* dest) {
            if (LAST_FRAME_TIMES[0] == 0 || dest == nullptr) { // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            } else if (now - LAST_FRAME_TIMES[0] > max_expire_time) { // CAN Frame has not refreshed in valid interval
                return false;
            } else { // CAN Frame is valid! return it
                return dest->raw = FRAME_DATA[0];
            }
        }
            
        /** Sets data in pointer to MRM_238
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MRM_238(uint64_t now, uint64_t max_expire_time, MRM_238* dest) {
            if (LAST_FRAME_TIMES[1] == 0 || dest == nullptr) { // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            } else if (now - LAST_FRAME_TIMES[1] > max_expire_time) { // CAN Frame has not refreshed in valid interval
                return false;
            } else { // CAN Frame is valid! return it
                return dest->raw = FRAME_DATA[1];
            }
        }
            
	private:
		uint64_t FRAME_DATA[2];
		uint64_t LAST_FRAME_TIMES[2];
};
#endif // __ECU_MRM_H_

#endif // EGS52_MODE