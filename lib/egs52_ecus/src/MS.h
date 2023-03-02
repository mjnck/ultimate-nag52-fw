
/**
* AUTOGENERATED BY convert.py
* DO NOT EDIT THIS FILE!
*
* IF MODIFICATIONS NEED TO BE MADE, MODIFY can_data.txt!
*
* CAN Defintiion for ECU 'MS'
*/

#ifndef __ECU_MS_H_
#define __ECU_MS_H_

#include <stdint.h>
    
#define MS_210_EGS52_CAN_ID 0x0210
#define MS_212_EGS52_CAN_ID 0x0212
#define MS_268_EGS52_CAN_ID 0x0268
#define MS_2F3_EGS52_CAN_ID 0x02F3
#define MS_308_EGS52_CAN_ID 0x0308
#define MS_312_EGS52_CAN_ID 0x0312
#define AAD_580_EGS52_CAN_ID 0x0580
#define MS_608_EGS52_CAN_ID 0x0608

/** switching line shift MS */
enum class MS_210h_SLV_MS_EGS52 : uint16_t {
	SKL0 = 0, // Shift characteristic "0"
	SKL1 = 1, // Shift characteristic "1"
	SKL2 = 2, // Shift characteristic "2"
	SKL3 = 3, // Shift characteristic "3"
	SKL4 = 4, // Shift characteristic "4"
	SKL5 = 5, // Shift characteristic "5"
	SKL6 = 6, // Shift characteristic "6"
	SKL7 = 7, // Shift characteristic "7"
	SKL8 = 8, // Shift characteristic "8"
	SKL9 = 9, // Shift characteristic "9"
	SKL10 = 10, // Shift characteristic "10"
};

/** Gear, upper limit */
enum class MS_210h_GMAX_MS_EGS52 : uint16_t {
	PASSIVE = 0, // passive value
	G1 = 1, // Gear, upper limit = 1
	G2 = 2, // Gear, upper limit = 2
	G3 = 3, // Gear, upper limit = 3
	G4 = 4, // Gear, upper limit = 4
	G5 = 5, // Gear, upper limit = 5
	G6 = 6, // Gear, upper limit = 6
	G7 = 7, // Gear, upper limit = 7
};

/** Gear, lower limit */
enum class MS_210h_GMIN_MS_EGS52 : uint16_t {
	PASSIVE = 0, // passive value
	G1 = 1, // Gear, lower limit = 1
	G2 = 2, // Gear, lower limit = 2
	G3 = 3, // Gear, lower limit = 3
	G4 = 4, // Gear, lower limit = 4
	G5 = 5, // Gear, lower limit = 5
	G6 = 6, // Gear, lower limit = 6
	G7 = 7, // Gear, lower limit = 7
};

/** Status heating power */
enum class MS_268h_HZL_ST_EGS52 : uint16_t {
	ZU = 0, // Heating shut-off valve is too
	AUF = 1, // Heating shut-off valve is up
	TAKT = 2, // Heating shut-off valve is clocked
	SNV = 3, // signal not available
};

/** Drive Level Switching recommendation "is" */
enum class MS_2F3h_FSC_IST_EGS52 : uint16_t {
	BLANK = 32, // Blank ("")
	EINS = 49, // Driving Level "1"
	ZWEI = 50, // Driving Level "2"
	DREI = 51, // Driving Level "3"
	VIER = 52, // Driving Level "4"
	FUENF = 53, // Driving Level "5"
	SECHS = 54, // Driving Level "6"
	SIEBEN = 55, // Driving stage "7"
	A = 65, // Driving stage "A"
	D = 68, // speed "D"
	F = 70, // Error Mark "F"
	N = 78, // Driving "N"
	P = 80, // Driving Level "P"
	R = 82, // Driving "R"
	SNV = 255, // passive value
};

/** Drive Level Switching recommendation "should" */
enum class MS_2F3h_FSC_SOLL_EGS52 : uint16_t {
	HOCH = 1, // "upshift" / arrow
	RUNTER = 2, // "downshift" / arrow
	BLANK_OR_PAS = 32, // blank ("") / passive
	EINS = 49, // Driving Level "1"
	ZWEI = 50, // Driving Level "2"
	DREI = 51, // Driving Level "3"
	VIER = 52, // Driving Level "4"
	FUENF = 53, // Driving Level "5"
	SECHS = 54, // Driving Level "6"
	SIEBEN = 55, // Driving stage "7"
	A = 65, // Driving stage "A"
	D = 68, // speed "D"
	F = 70, // Error Mark "F"
	N = 78, // Driving "N"
	P = 80, // Driving Level "P"
	R = 82, // Driving "R"
	SNV = 255, // passive value
};

/** Vehicle code body */
enum class MS_608h_FCOD_KAR_EGS52 : uint16_t {
	W = 0, // W - Limousine (or G short BM1 / 3 at BR 463, G at 461)
	V = 1, // V - Limousine long (or VF at BR 210/211, G Lang BM6 at BR 463)
	C = 2, // C - Coupé (or VV at BR 210/211/220)
	S = 3, // S - T model (or special protection B4 at BR W240, T at BR 245)
	A = 4, // A - Cabrio (or X at BR 164)
	R = 5, // R - Roadster (or special protection B4 at BR 210 / 211/220 / V240)
	SS = 6, // SS - Special protection B6 / 7 (or CL at BR 203)
	SNV = 7, // Code not available
};

/** Vehicle code series */
enum class MS_608h_FCOD_BR_EGS52 : uint16_t {
	BR221 = 0, // BR 221 Od. BR 140
	BR129 = 1, // BR 129
	BR210 = 2, // BR 210 Od. BR 212
	BR202 = 3, // BR 202 Od. BR 204
	BR220 = 4, // BR 220
	BR170 = 5, // BR 170
	BR203 = 6, // BR 203
	BR168 = 7, // BR 168
	BR163 = 8, // BR 163
	BR208 = 9, // BR 208
	BR463 = 10, // BR 463
	BR215 = 11, // BR 215
	BR230 = 12, // BR 230
	BR211 = 13, // BR 211
	BR209 = 14, // BR 209
	BR461 = 15, // BR 461
	BR240 = 16, // BR 240
	BR251 = 17, // BR 251
	BR171 = 18, // BR 171
	BR164 = 19, // BR 164
	BR169 = 20, // BR 169 Od. BR 245
	BR199 = 21, // BR 199
	BR216 = 22, // BR 216
	BR219 = 23, // BR 219
	BR454 = 24, // BR 454 (Z-CAR)
	NCV2 = 25, // NCV2
	VITO = 26, // V-Class / Vito
	SPRINTER = 27, // Sprinter
	NCV3 = 28, // NCV3
	NCV1 = 29, // NCV1
	REST = 30, // All other BR
	SNV = 31, // Code not available
};

/** FZGCOD.Motor 7Bit, bit0-5 (bit6 -> signal fcod_mot6) */
enum class MS_608h_FCOD_MOT_EGS52 : uint16_t {
	M272E35 = 0, // M272 E35
	M271E18ML105 = 1, // M271 E18 ml Red. (105 kW)
	M271E18ML120 = 2, // M271 E18 ml (120 kW)
	M112E37 = 3, // M112 E37
	M272E25 = 4, // M272 E25
	M272E30 = 5, // M272 E30
	M112E28 = 7, // M112 E28
	M112E32 = 8, // M112 E32
	M273E46 = 10, // M273 E46
	M273E55 = 11, // M273 E55
	M112E26 = 12, // M112 E26
	M113E43 = 13, // M113 E43
	M113E50 = 14, // M113 E50
	M271E18ML140 = 18, // M271 E18 ML / 1 (140 kW)
	M271DE18ML105 = 19, // M271 DE18 ml Red. (105 kW)
	M271DE18ML125 = 20, // M271 DE18 ML (125 kW)
	M111E_E23ML = 22, // M111E E23 ML
	M111E_E20 = 23, // M111E E20
	M111E_E20ML = 24, // M111E E20 ml
	M112E32_140 = 25, // M112 E32 RED. (140 kW)
	M266E20ATL = 26, // M266 E20 ATL
	M266E15 = 27, // M266 E15
	M266E17 = 28, // M266 E17
	M266E20 = 29, // M266 E20
	M275E55 = 30, // M275 E55 Od. M285 E55
	M137E58 = 31, // M137 E58
	OM640DE20LA60 = 32, // OM 640 DE20 LA (60 kW)
	OM640DE20LA80 = 34, // OM 640 DE20 LA (80 kW)
	OM642DE30LA160 = 35, // OM642 DE30 LA (155/160 kW)
	OM640DE20LA100 = 36, // OM 640 DE20 LA (100 kW)
	OM613DE32LA = 37, // OM613 DE32 La od. OM648 DE32 LA
	OM628DE40LA = 39, // OM628 DE40 LA
	OM642DE30LA140 = 40, // OM642 DE30 LA (140 kW)
	OM612DE27LA = 43, // OM612 DE27 LA od. OM647 DE27 LA (120/130 kW)
	OM611DE22LA100 = 44, // OM611 DE22 LA (105/100 kW) Od. OM646 DE22 LA (100/105/110 kW)
	OM611DE22LA85 = 45, // OM611 DE22 LA (85 kW) Od. OM646 DE22 LA (90 kW)
	OM611DE22LA75 = 46, // OM611 DE22 LA (75 kW) Od. OM646 DE22 LA (75 kW)
	M134E11 = 64, // M134 E11 (3A91)
	M135E13 = 65, // M135 E13 (4A90)
	M135E15 = 66, // M135 E15 (4A91)
	M135E15ATL = 67, // M135 E15 ATL
	M272DE25 = 68, // M272 DE25
	M272DE30 = 69, // M272 DE30
	M272DE35 = 70, // M272 DE35
	M273DE46 = 71, // M273 DE46
	M273DE55 = 72, // M273 DE55
	M271E18MLATTR115 = 79, // M271 E18 ml Attr. (115kW)
	M271E18MLATTR141 = 80, // M271 E18 ml Attr. (141kW)
	OM629DE40LA = 96, // OM629 DE40 LA
	OM642DE30LARED140 = 99, // OM642 DE30 LA RED. (140kW)
};

/** Particle filter warning */
enum class MS_608h_PFW_EGS52 : uint16_t {
	OK = 0, // No warning
	PFW1 = 1, // Warning filters too, level 1
	PFW2 = 2, // Warning filters too, level 2
	SNV = 3, // signal not available
};



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		/** Set maximum or cruise control speed **/
		uint8_t V_MAX_TM: 8;
		/** factor for altitude value. d. max. Mom with remo.. A.druck **/
		uint8_t FMMOTMAX: 8;
		/** Geschw.begrenzer- / cruise control display a **/
		bool V_DSPL_EIN: 1;
		/** display flashes **/
		bool V_DSPL_BL: 1;
		/** "Error" indicator on the display **/
		bool V_DSPL_ERR: 1;
		/** Display "limit?" on display **/
		bool V_DSPL_LIM: 1;
		/** Speed ​​controls **/
		bool V_MAX_REG: 1;
		/** activated cruise control **/
		bool TM_EIN: 1;
		/** "achieved winter tires limitation" Indicated on display **/
		bool V_DSPL_PGB: 1;
		/** FBStart Error **/
		bool FBS_SE: 1;
		/** Warning buzzer **/
		bool V_MAX_SUM: 1;
		/** emergency operation **/
		bool NOTL: 1;
		/** Kick Down (changeover scenario open!) **/
		bool KD_MS: 1;
		/** activated speed limit **/
		bool V_MAX_EIN: 1;
		/** cruise control regulates **/
		bool TM_REG: 1;
		/** beg. "Slip" lock-up clutch **/
		bool KUEB_S_A: 1;
		/** idle **/
		bool LL: 1;
		/** error pedal sensor **/
		bool PWG_ERR: 1;
		/** Crash signal from motor control **/
		bool CRASH_MS: 1;
		/** turn air compressor:: S acceleration **/
		bool KOMP_BAUS: 1;
		/** engine start / stop system active **/
		bool MSS_AKT: 1;
		/** engine start / stop system warning **/
		bool MSS_KL: 1;
		/** Engine Start / Stop system is defective **/
		bool MSS_DEF: 1;
		/** Vorglühstatus **/
		bool VGL_ST: 1;
		/** idle is stable **/
		bool LL_STBL: 1;
		/** retrigger minimum display time in the display: S **/
		bool V_DSPL_NEU: 1;
		/** pedal **/
		uint8_t PW: 8;
		/** Gear, lower limit **/
		MS_210h_GMIN_MS_EGS52 GMIN_MS: 3;
		/** Gear, upper limit **/
		MS_210h_GMAX_MS_EGS52 GMAX_MS: 3;
		/** Turn off heater **/
		bool ZH_AUS_MS: 1;
		/** MS-wish: "Active downshift" **/
		bool AKT_R_MS: 1;
		/** MS-wish: "Approach 1.Gang" **/
		bool ANF1: 1;
		/** Switch KSG-creep **/
		bool KRIECH_AUS: 1;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		bool __PADDING1__: 1;
		/** switching line shift MS **/
		MS_210h_SLV_MS_EGS52 SLV_MS: 4;
		/** Air compressor Emergency Shutdown **/
		bool KOMP_NOTAUS: 1;
	} __attribute__((packed));
	/** Gets CAN ID of MS_210_EGS52 **/
	uint32_t get_canid(){ return MS_210_EGS52_CAN_ID; }
} MS_210_EGS52;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		/** default torque ESP **/
		uint16_t M_ESPV: 13;
		/** Enable torque requirement EGS **/
		bool M_EGS_E: 1;
		/** acknowledgment torque requirement EGS **/
		bool M_EGS_Q: 1;
		/** Transfer Calid / CVN Enable **/
		bool CALID_CVN_E: 1;
		/** replacement feed torque driver **/
		uint16_t M_FEV: 13;
		/** Enable torque requirement ESP **/
		bool M_ESP_E: 1;
		/** ENABLE Fast torque setting **/
		bool SME_E: 1;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		bool __PADDING1__: 1;
		/** default torque driver **/
		uint16_t M_FV: 13;
		/** Enable torque requirement type **/
		bool M_ART_E: 1;
		/** Serial mpomat is variant encoded **/
		bool TM_MS: 1;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		bool __PADDING2__: 1;
		/** Motorley roll speed **/
		uint16_t NMOTS: 16;
	} __attribute__((packed));
	/** Gets CAN ID of MS_212_EGS52 **/
	uint32_t get_canid(){ return MS_212_EGS52_CAN_ID; }
} MS_212_EGS52;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint16_t __PADDING1__: 16;
		/** pedal value driver (only 169) **/
		uint8_t PW_F: 8;
		/** Max. Climate compressor torque **/
		uint8_t M_KOMP_MAX: 8;
		/** Generator utilization (LIN generators only!) **/
		uint8_t LAST_GEN: 6;
		/** Mode air control system **/
		bool LRS_MODE: 1;
		/** Request for power-free in "D" (FCVT) **/
		bool KID_MS: 1;
		/** Status heating power **/
		MS_268h_HZL_ST_EGS52 HZL_ST: 2;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint8_t __PADDING2__: 3;
		/** shut-off valve cooling circuit M266 ATL **/
		bool ASV_KKL_169: 1;
		/** Oil Info, reserved M266 **/
		bool OEL_INFO_169: 1;
		/** Terminal 61 **/
		bool KL_61_EIN: 1;
		/** Target Translation, Upper Border (FCVT) **/
		uint8_t IMAX_MS: 8;
		/** target translation, lower border (FCVT) **/
		uint8_t IMIN_MS: 8;
	} __attribute__((packed));
	/** Gets CAN ID of MS_268_EGS52 **/
	uint32_t get_canid(){ return MS_268_EGS52_CAN_ID; }
} MS_268_EGS52;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint16_t __PADDING1__: 16;
		/** Drive Level Switching recommendation "should" **/
		MS_2F3h_FSC_SOLL_EGS52 FSC_SOLL: 8;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint32_t __PADDING2__: 32;
		/** Drive Level Switching recommendation "is" **/
		MS_2F3h_FSC_IST_EGS52 FSC_IST: 8;
	} __attribute__((packed));
	/** Gets CAN ID of MS_2F3_EGS52 **/
	uint32_t get_canid(){ return MS_2F3_EGS52_CAN_ID; }
} MS_2F3_EGS52;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		/** oil quality **/
		uint8_t OEL_QUAL: 8;
		/** oil level **/
		uint8_t OEL_FS: 8;
		/** Oil temperature **/
		uint8_t T_OEL: 8;
		/** cooling water temperature too high **/
		bool TEMP_KL: 1;
		/** Speed limitation for display active (0 at CR) **/
		bool DBAA: 1;
		/** Motor Heater Defective Control Lamp **/
		bool LUEFT_MOT_KL: 1;
		/** starter is running **/
		bool ANL_LFT: 1;
		/** ADR defective control lamp (NFZ only) **/
		bool ADR_DEF_KL: 1;
		/** ADR check lamp (NFZ only) **/
		bool ADR_KL: 1;
		/** Cylinder shutdown **/
		bool ZAS: 1;
		/** Engine oil temperature too high (overheating) **/
		bool UEHITZ: 1;
		/** Tank lid open check lamp **/
		bool TANK_KL: 1;
		/** Diagnosis Control Lamp (OBD II) **/
		bool DIAG_KL: 1;
		/** oil level / oil pressure control lamp **/
		bool OEL_KL: 1;
		/** pre-glow control lamp **/
		bool VGL_KL: 1;
		/** Air filter dirty warning lamp (only diesel) **/
		bool LUFI_KL: 1;
		/** Ethanol operation detected **/
		bool EOH: 1;
		/** Warning message ECO steering helping pump **/
		bool ELHP_WARN: 1;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		bool __PADDING1__: 1;
		/** engine speed **/
		uint16_t NMOT: 16;
		/** Cylinder shutdown conditions fulfilled **/
		bool ZASBED: 1;
		/** Water in the fuel control lamp (CR2 US only) **/
		bool WKS_KL: 1;
		/** Fuel filter clogs control lamp (CR2 US only) **/
		bool KSF_KL: 1;
		/** push shutdown full **/
		bool SASV: 1;
		/** Partinal shutdown **/
		bool SAST: 1;
		/** Speed limiting function active **/
		bool N_MAX_BG: 1;
		/** start.Convertible bridging clutch "Open" **/
		bool KUEB_O_A: 1;
		/** clutch kicked **/
		bool KPL: 1;
	} __attribute__((packed));
	/** Gets CAN ID of MS_308_EGS52 **/
	uint32_t get_canid(){ return MS_308_EGS52_CAN_ID; }
} MS_308_EGS52;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		/** Motor torque minimal **/
		uint16_t M_MIN: 13;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint8_t __PADDING1__: 3;
		/** Motor torque maximum **/
		uint16_t M_MAX: 13;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint8_t __PADDING2__: 3;
		/** Motor Torque Maximum incl. DYN.Turbocharger **/
		uint16_t M_MAX_ATL: 13;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint8_t __PADDING3__: 3;
		/** Motor torque static **/
		uint16_t M_STA: 13;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint8_t __PADDING4__: 3;
	} __attribute__((packed));
	/** Gets CAN ID of MS_312_EGS52 **/
	uint32_t get_canid(){ return MS_312_EGS52_CAN_ID; }
} MS_312_EGS52;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		/** nervousness **/
		uint8_t AADNT: 8;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint8_t __PADDING1__: 7;
		/** Spontaneous dynamic requirement **/
		bool AADKBDYN: 1;
		/** Continuous driver watching **/
		uint8_t AADKB: 8;
		/** Max. Diff.Pedal angle value per maneuver **/
		uint8_t FTK_DPW: 8;
		 /** BITFIELD PADDING. DO NOT CHANGE **/
		uint8_t __PADDING2__: 8;
		/** code number brake type (> 100: dynamic) **/
		uint8_t FTK_VMI: 8;
		/** Code of the transverse acceleration type (> 100: dynamic) **/
		uint8_t FTK_LMI: 8;
		/** indicator acceleration type (> 100: dynamic) **/
		uint8_t FTK_BMI: 8;
	} __attribute__((packed));
	/** Gets CAN ID of AAD_580_EGS52 **/
	uint32_t get_canid(){ return AAD_580_EGS52_CAN_ID; }
} AAD_580_EGS52;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];
	struct {
		/** Particle Filter Correction Offset FMMOTMAX **/
		uint8_t PFKO: 4;
		/** Switch on additional consumers **/
		bool ZVB_EIN_MS: 1;
		/** Particle filter warning **/
		MS_608h_PFW_EGS52 PFW: 2;
		/** Turn on auxiliary water pump **/
		bool ZWP_EIN_MS: 1;
		/** consumption **/
		uint16_t VB: 16;
		/** Fixed maximum speed **/
		uint8_t V_MAX_FIX: 8;
		/** !!MASKED SIGNAL!! Use get_FCOD_MOT() and set_FCOD_MOT() to use this data! **/
		uint8_t FCOD_MOT: 6;
		/** Transmission control not available **/
		bool GS_NVH: 1;
		/** Vehicle code engine with 7 bit, bit 6 **/
		bool FCOD_MOT6: 1;
		/** Vehicle code series **/
		MS_608h_FCOD_BR_EGS52 FCOD_BR: 5;
		/** Vehicle code body **/
		MS_608h_FCOD_KAR_EGS52 FCOD_KAR: 3;
		/** intake air temperature **/
		uint8_t T_LUFT: 8;
		/** engine coolant temperature **/
		uint8_t T_MOT: 8;
	} __attribute__((packed));
	/** Gets CAN ID of MS_608_EGS52 **/
	uint32_t get_canid(){ return MS_608_EGS52_CAN_ID; }
	/** Gets FZGCOD.Motor 7Bit, bit0-5 (bit6 -> signal fcod_mot6) **/
	MS_608h_FCOD_MOT_EGS52 get_FCOD_MOT(){ return (MS_608h_FCOD_MOT_EGS52)(raw >> 32 & 10111111); }
	/** Sets FZGCOD.Motor 7Bit, bit0-5 (bit6 -> signal fcod_mot6) **/
	void set_FCOD_MOT(MS_608h_FCOD_MOT_EGS52 v){ raw = (raw & 0xffffff40ffffffff) | ((uint64_t)v & 0b10111111) << 32; }
} MS_608_EGS52;



class ECU_MS {
	public:
        /**
         * @brief Imports the CAN frame given the CAN ID, CAN Contents, and current timestamp
         *
         * Returns true if the frame was imported successfully, and false if import failed (Due to non-matching CAN ID).
         *
         * NOTE: The endianness of the value cannot be guaranteed. It is up to the caller to correct the byte order!
         */
        bool import_frames(uint64_t value, uint32_t can_id, uint64_t timestamp_now) {
            uint8_t idx = 0;
            bool add = true;
            switch(can_id) {
                case MS_210_EGS52_CAN_ID:
                    idx = 0;
                    break;
                case MS_212_EGS52_CAN_ID:
                    idx = 1;
                    break;
                case MS_268_EGS52_CAN_ID:
                    idx = 2;
                    break;
                case MS_2F3_EGS52_CAN_ID:
                    idx = 3;
                    break;
                case MS_308_EGS52_CAN_ID:
                    idx = 4;
                    break;
                case MS_312_EGS52_CAN_ID:
                    idx = 5;
                    break;
                case AAD_580_EGS52_CAN_ID:
                    idx = 6;
                    break;
                case MS_608_EGS52_CAN_ID:
                    idx = 7;
                    break;
                default:
                    add = false;
                    break;
            }
            if (add) {
                LAST_FRAME_TIMES[idx] = timestamp_now;
                FRAME_DATA[idx] = value;
            }
            return add;
        }
        
        /** Sets data in pointer to MS_210
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MS_210(uint64_t now, uint64_t max_expire_time, MS_210_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[0] <= now && now - LAST_FRAME_TIMES[0] < max_expire_time) {
                dest->raw = FRAME_DATA[0];
                ret = true;
            }
            return ret;
        }
            
        /** Sets data in pointer to MS_212
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MS_212(uint64_t now, uint64_t max_expire_time, MS_212_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[1] <= now && now - LAST_FRAME_TIMES[1] < max_expire_time) {
                dest->raw = FRAME_DATA[1];
                ret = true;
            }
            return ret;
        }
            
        /** Sets data in pointer to MS_268
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MS_268(uint64_t now, uint64_t max_expire_time, MS_268_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[2] <= now && now - LAST_FRAME_TIMES[2] < max_expire_time) {
                dest->raw = FRAME_DATA[2];
                ret = true;
            }
            return ret;
        }
            
        /** Sets data in pointer to MS_2F3
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MS_2F3(uint64_t now, uint64_t max_expire_time, MS_2F3_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[3] <= now && now - LAST_FRAME_TIMES[3] < max_expire_time) {
                dest->raw = FRAME_DATA[3];
                ret = true;
            }
            return ret;
        }
            
        /** Sets data in pointer to MS_308
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MS_308(uint64_t now, uint64_t max_expire_time, MS_308_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[4] <= now && now - LAST_FRAME_TIMES[4] < max_expire_time) {
                dest->raw = FRAME_DATA[4];
                ret = true;
            }
            return ret;
        }
            
        /** Sets data in pointer to MS_312
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MS_312(uint64_t now, uint64_t max_expire_time, MS_312_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[5] <= now && now - LAST_FRAME_TIMES[5] < max_expire_time) {
                dest->raw = FRAME_DATA[5];
                ret = true;
            }
            return ret;
        }
            
        /** Sets data in pointer to AAD_580
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_AAD_580(uint64_t now, uint64_t max_expire_time, AAD_580_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[6] <= now && now - LAST_FRAME_TIMES[6] < max_expire_time) {
                dest->raw = FRAME_DATA[6];
                ret = true;
            }
            return ret;
        }
            
        /** Sets data in pointer to MS_608
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_MS_608(uint64_t now, uint64_t max_expire_time, MS_608_EGS52* dest) const {
            bool ret = false;
            if (dest != nullptr && LAST_FRAME_TIMES[7] <= now && now - LAST_FRAME_TIMES[7] < max_expire_time) {
                dest->raw = FRAME_DATA[7];
                ret = true;
            }
            return ret;
        }
            
	private:
		uint64_t FRAME_DATA[8];
		uint64_t LAST_FRAME_TIMES[8];
};
#endif // __ECU_MS_H_