
/**
* AUTOGENERATED BY convert.py
* DO NOT EDIT THIS FILE!
*
* IF MODIFICATIONS NEED TO BE MADE, MODIFY can_data.txt!
*
* CAN Defintiion for ECU 'KOMBI'
*/

#ifdef EGS52_MODE

#ifndef __ECU_KOMBI_H_
#define __ECU_KOMBI_H_

#include <stdint.h>
    
#define KOMBI_408_CAN_ID 0x0408
#define KOMBI_412_CAN_ID 0x0412

/** Winter tire maximum speed with 4 bits */
enum class KOMBI_408h_WRC {
	UBG = 0, // Unlimited
	BG210 = 1, // 210 km / h
	BG190 = 2, // 190 km / h
	BG160 = 3, // 160 km / h
	BG240 = 4, // 240 km / h
	BG230 = 5, // 230 km / h
	BG220 = 6, // 220 km / h
	BG200 = 7, // 200 km / h
	BG180 = 128, // 180 km / h
	BG170 = 129, // 170 km / h
	BG150 = 130, // 150 km / h
	BG140 = 131, // 140 km / h
	BG130 = 132, // 130 km / h
	BG120 = 133, // 120 km / h
	BG110 = 134, // 110 km / h
	BG100 = 135, // 100 km / h
};

/** set distance */
enum class KOMBI_412h_IST_ABST {
	SEHR_KLEIN = 0, // very small
	KLEIN = 1, // small
	MITTEL = 2, // medium
	GROSS = 3, // big
	SEHR_GROSS = 4, // very big
	UNKNOWN_1 = 5, // not defined
	UNKNOWN_2 = 6, // not defined
	UNKNOWN_3 = 7, // not defined
};

/** wheel direction of rotation to V_ANZ */
enum class KOMBI_412h_DRTGANZ {
	PASSIV = 0, // No rotation detection
	VOR = 1, // direction of rotation forward
	RUECK = 2, // direction of rotation backwards
	SNV = 3, // signal not available
};

/** Request PlatRollwarner */
enum class KOMBI_412h_PRW_ANF {
	IDLE = 0, // No change
	AUS = 1, // switch off PRW
	EIN = 2, // re-enable PRW
	SNV = 3, // signal not available
};



typedef union {
	uint64_t raw;

	/** Gets CAN ID of KOMBI_408 */
	uint32_t get_canid(){ return KOMBI_408_CAN_ID; }
    /** Sets Tank level */
    void set_TANK_FS(uint8_t value){ raw = (raw & 0x00ffffffffffffff) | ((uint64_t)value & 0xff) << 56; }

    /** Gets Tank level */
    uint8_t get_TANK_FS() { return (uint8_t)(raw >> 56 & 0xff); }
        
    /** Sets driver's door */
    void set_TF_AUF(bool value){ raw = (raw & 0xff7fffffffffffff) | ((uint64_t)value & 0x1) << 55; }

    /** Gets driver's door */
    bool get_TF_AUF() { return (bool)(raw >> 55 & 0x1); }
        
    /** Sets Speed Limit / Tempose Display Not possible */
    void set_V_DSPL_AUS(bool value){ raw = (raw & 0xffbfffffffffffff) | ((uint64_t)value & 0x1) << 54; }

    /** Gets Speed Limit / Tempose Display Not possible */
    bool get_V_DSPL_AUS() { return (bool)(raw >> 54 & 0x1); }
        
    /** Sets Tacho oak */
    void set_TACHO_SYM(bool value){ raw = (raw & 0xffdfffffffffffff) | ((uint64_t)value & 0x1) << 53; }

    /** Gets Tacho oak */
    bool get_TACHO_SYM() { return (bool)(raw >> 53 & 0x1); }
        
    /** Sets MPH instead of km / h (variable speed bends) */
    void set_V_MPH(bool value){ raw = (raw & 0xffefffffffffffff) | ((uint64_t)value & 0x1) << 52; }

    /** Gets MPH instead of km / h (variable speed bends) */
    bool get_V_MPH() { return (bool)(raw >> 52 & 0x1); }
        
    /** Sets Air conditioning available */
    void set_KLA_VH(bool value){ raw = (raw & 0xfff7ffffffffffff) | ((uint64_t)value & 0x1) << 51; }

    /** Gets Air conditioning available */
    bool get_KLA_VH() { return (bool)(raw >> 51 & 0x1); }
        
    /** Sets pre-glow control lamp defective */
    void set_VGL_KL_DEF(bool value){ raw = (raw & 0xfffbffffffffffff) | ((uint64_t)value & 0x1) << 50; }

    /** Gets pre-glow control lamp defective */
    bool get_VGL_KL_DEF() { return (bool)(raw >> 50 & 0x1); }
        
    /** Sets Tank level minimum */
    void set_TFSM(bool value){ raw = (raw & 0xfffdffffffffffff) | ((uint64_t)value & 0x1) << 49; }

    /** Gets Tank level minimum */
    bool get_TFSM() { return (bool)(raw >> 49 & 0x1); }
        
    /** Sets Clamp 61 decoupled */
    void set_KL_61E(bool value){ raw = (raw & 0xfffeffffffffffff) | ((uint64_t)value & 0x1) << 48; }

    /** Gets Clamp 61 decoupled */
    bool get_KL_61E() { return (bool)(raw >> 48 & 0x1); }
        
    /** Sets Outdoor air temperature raw value */
    void set_T_AUSSEN(uint8_t value){ raw = (raw & 0xffff00ffffffffff) | ((uint64_t)value & 0xff) << 40; }

    /** Gets Outdoor air temperature raw value */
    uint8_t get_T_AUSSEN() { return (uint8_t)(raw >> 40 & 0xff); }
        
    /** Sets Terminal 58 dimmed */
    void set_KL_58D(uint8_t value){ raw = (raw & 0xffffff00ffffffff) | ((uint64_t)value & 0xff) << 32; }

    /** Gets Terminal 58 dimmed */
    uint8_t get_KL_58D() { return (uint8_t)(raw >> 32 & 0xff); }
        
    /** Sets Motor setting time (will be sent from Kl.15) */
    void set_MAZ(uint8_t value){ raw = (raw & 0xffffffff00ffffff) | ((uint64_t)value & 0xff) << 24; }

    /** Gets Motor setting time (will be sent from Kl.15) */
    uint8_t get_MAZ() { return (uint8_t)(raw >> 24 & 0xff); }
        
    /** Sets mileage */
    void set_KM16(uint16_t value){ raw = (raw & 0xffffffffff0000ff) | ((uint64_t)value & 0xffff) << 8; }

    /** Gets mileage */
    uint16_t get_KM16() { return (uint16_t)(raw >> 8 & 0xffff); }
        
    /** Sets Winter Tire Top Speed Bit 3 */
    void set_WRC3(bool value){ raw = (raw & 0xffffffffffffff7f) | ((uint64_t)value & 0x1) << 7; }

    /** Gets Winter Tire Top Speed Bit 3 */
    bool get_WRC3() { return (bool)(raw >> 7 & 0x1); }
        
    /** Sets Speed Limit / Tempomat Display Active */
    void set_V_DSPL_AKT(bool value){ raw = (raw & 0xffffffffffffffbf) | ((uint64_t)value & 0x1) << 6; }

    /** Gets Speed Limit / Tempomat Display Active */
    bool get_V_DSPL_AKT() { return (bool)(raw >> 6 & 0x1); }
        
    /** Sets Segment tacho available */
    void set_SGT_VH(bool value){ raw = (raw & 0xffffffffffffffdf) | ((uint64_t)value & 0x1) << 5; }

    /** Gets Segment tacho available */
    bool get_SGT_VH() { return (bool)(raw >> 5 & 0x1); }
        
    /** Sets Release Heaters */
    void set_ZH_FREIG(bool value){ raw = (raw & 0xffffffffffffffef) | ((uint64_t)value & 0x1) << 4; }

    /** Gets Release Heaters */
    bool get_ZH_FREIG() { return (bool)(raw >> 4 & 0x1); }
        
    /** Sets Switch on Roll Test Mode ESP */
    void set_RT_EIN(bool value){ raw = (raw & 0xfffffffffffffff7) | ((uint64_t)value & 0x1) << 3; }

    /** Gets Switch on Roll Test Mode ESP */
    bool get_RT_EIN() { return (bool)(raw >> 3 & 0x1); }
        
    /** Sets Winter tire maximum speed with 4 bits */
    void set_WRC(KOMBI_408h_WRC value){ raw = (raw & 0xfffffffffffffff8) | ((uint64_t)value & 0x7) << 0; }

    /** Gets Winter tire maximum speed with 4 bits */
    KOMBI_408h_WRC get_WRC() { return (KOMBI_408h_WRC)(raw >> 0 & 0x7); }
        
} KOMBI_408;



typedef union {
	uint64_t raw;

	/** Gets CAN ID of KOMBI_412 */
	uint32_t get_canid(){ return KOMBI_412_CAN_ID; }
    /** Sets Acoustic warning out */
    void set_AKU_WARN_AUS(bool value){ raw = (raw & 0x7fffffffffffffff) | ((uint64_t)value & 0x1) << 63; }

    /** Gets Acoustic warning out */
    bool get_AKU_WARN_AUS() { return (bool)(raw >> 63 & 0x1); }
        
    /** Sets Optical warning out */
    void set_OPT_WARN_AUS(bool value){ raw = (raw & 0xbfffffffffffffff) | ((uint64_t)value & 0x1) << 62; }

    /** Gets Optical warning out */
    bool get_OPT_WARN_AUS() { return (bool)(raw >> 62 & 0x1); }
        
    /** Sets Status Eco Warning */
    void set_ECO_WARN_ST(bool value){ raw = (raw & 0xf7ffffffffffffff) | ((uint64_t)value & 0x1) << 59; }

    /** Gets Status Eco Warning */
    bool get_ECO_WARN_ST() { return (bool)(raw >> 59 & 0x1); }
        
    /** Sets distance unit */
    void set_ABST_S(bool value){ raw = (raw & 0xff7fffffffffffff) | ((uint64_t)value & 0x1) << 55; }

    /** Gets distance unit */
    bool get_ABST_S() { return (bool)(raw >> 55 & 0x1); }
        
    /** Sets set distance */
    void set_IST_ABST(KOMBI_412h_IST_ABST value){ raw = (raw & 0xff8fffffffffffff) | ((uint64_t)value & 0x7) << 52; }

    /** Gets set distance */
    KOMBI_412h_IST_ABST get_IST_ABST() { return (KOMBI_412h_IST_ABST)(raw >> 52 & 0x7); }
        
    /** Sets Speed displayed */
    void set_V_ANZ(uint16_t value){ raw = (raw & 0xfff000ffffffffff) | ((uint64_t)value & 0xfff) << 40; }

    /** Gets Speed displayed */
    uint16_t get_V_ANZ() { return (uint16_t)(raw >> 40 & 0xfff); }
        
    /** Sets wheel direction of rotation to V_ANZ */
    void set_DRTGANZ(KOMBI_412h_DRTGANZ value){ raw = (raw & 0xffffff3fffffffff) | ((uint64_t)value & 0x3) << 38; }

    /** Gets wheel direction of rotation to V_ANZ */
    KOMBI_412h_DRTGANZ get_DRTGANZ() { return (KOMBI_412h_DRTGANZ)(raw >> 38 & 0x3); }
        
    /** Sets wheel speed calculated from V_ANZ */
    void set_DANZ(uint16_t value){ raw = (raw & 0xffffffc000ffffff) | ((uint64_t)value & 0x3fff) << 24; }

    /** Gets wheel speed calculated from V_ANZ */
    uint16_t get_DANZ() { return (uint16_t)(raw >> 24 & 0x3fff); }
        
    /** Sets Activation ECO in the combined menu */
    void set_ECO_AKT(bool value){ raw = (raw & 0xfffffffffff7ffff) | ((uint64_t)value & 0x1) << 19; }

    /** Gets Activation ECO in the combined menu */
    bool get_ECO_AKT() { return (bool)(raw >> 19 & 0x1); }
        
    /** Sets Request PlatRollwarner */
    void set_PRW_ANF(KOMBI_412h_PRW_ANF value){ raw = (raw & 0xfffffffffffcffff) | ((uint64_t)value & 0x3) << 16; }

    /** Gets Request PlatRollwarner */
    KOMBI_412h_PRW_ANF get_PRW_ANF() { return (KOMBI_412h_PRW_ANF)(raw >> 16 & 0x3); }
        
    /** Sets Motor setting time */
    void set_MAZ_NEU(uint16_t value){ raw = (raw & 0xfffffffffffff000) | ((uint64_t)value & 0xfff) << 0; }

    /** Gets Motor setting time */
    uint16_t get_MAZ_NEU() { return (uint16_t)(raw >> 0 & 0xfff); }
        
} KOMBI_412;



class ECU_KOMBI {
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
                case KOMBI_408_CAN_ID:
                    LAST_FRAME_TIMES[0] = timestamp_now;
                    FRAME_DATA[0] = value;
                    return true;
                case KOMBI_412_CAN_ID:
                    LAST_FRAME_TIMES[1] = timestamp_now;
                    FRAME_DATA[1] = value;
                    return true;
                default:
                    return false;
            }
        }
        
        /** Sets data in pointer to KOMBI_408
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_KOMBI_408(uint64_t now, uint64_t max_expire_time, KOMBI_408* dest) {
            if (LAST_FRAME_TIMES[0] == 0 || dest == nullptr) { // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            } else if (now - LAST_FRAME_TIMES[0] > max_expire_time) { // CAN Frame has not refreshed in valid interval
                return false;
            } else { // CAN Frame is valid! return it
                return dest->raw = FRAME_DATA[0];
            }
        }
            
        /** Sets data in pointer to KOMBI_412
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_KOMBI_412(uint64_t now, uint64_t max_expire_time, KOMBI_412* dest) {
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
#endif // __ECU_KOMBI_H_

#endif // EGS52_MODE