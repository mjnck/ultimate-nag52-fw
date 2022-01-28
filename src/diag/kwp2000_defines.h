#ifndef _KWP_DEFINES_H__
#define _KWP_DEFINES_H__

/// KWP 2000 Definitions (The standard)

// For EGS52/53 compatibility reasons, we adopt their timing standards
// and CAN IDs
#define KWP_TP_TIMEOUT_MS 2500
#define KWP_CAN_ST_MIN 20 // ISO-TP CAN Sep time min ms
#define KWP_CAN_BS 8 // ISO-TP CAN block size
#define KWP_ECU_TX_ID 0x07E9 // ECU Sends on this ID
#define KWP_ECU_RX_ID 0x07E1 // Tester requests on this ID

/*
KWP2000 SERVICE IDENTIFIERS
*/
#define SID_START_DIAGNOSTIC_SESSION 0x10
#define SID_ECU_RESET 0x11
#define SID_CLEAR_DIAGNOSTIC_INFORMATION 0x14
#define SID_READ_STATUS_OF_DTCS 0x17
#define SID_READ_DTCS_BY_STATUS 0x18
#define SID_READ_ECU_IDENT 0x1A
#define SID_READ_DATA_LOCAL_IDENT 0x21
#define SID_READ_DATA_IDENT 0x22
#define SID_READ_MEM_BY_ADDRESS 0x23
#define SID_SECURITY_ACCESS 0x27
#define SID_DISABLE_NORMAL_MSG_TRANSMISSION 0x28
#define SID_ENABLE_NORMAL_MSG_TRANSMISSION 0x29
#define SID_DYNAMICALLY_DEFINE_LOCAL_IDENT 0x2C
#define SID_WRITE_DATA_BY_IDENT 0x2E
#define SID_IOCTL_BY_LOCAL_IDENT 0x30
#define SID_START_ROUTINE_BY_LOCAL_IDENT 0x31
#define SID_STOP_ROUTINE_BY_LOCAL_IDENT 0x32
#define SID_REQUEST_ROUTINE_RESULTS_BY_LOCAL_IDENT 0x33
#define SID_REQ_DOWNLOAD 0x34
#define SID_REQ_UPLOAD 0x35
#define SID_TRANSFER_DATA 0x36
#define SID_TRANSFER_EXIT 0x37
#define SID_WRITE_DATA_BY_LOCAL_IDENT 0x3B
#define SID_WRITE_MEM_BY_ADDRESS 0x3D
#define SID_TESTER_PRESENT 0x3E
#define SID_CONTROL_DTC_SETTING 0x85
#define SID_RESPONSE_ON_EVENT 0x86

/*
KWP2000 Negative response codes
*/
#define NRC_GENERAL_REJECT 0X10
#define NRC_SERVICE_NOT_SUPPORTED 0x11
#define NRC_SUB_FUNC_NOT_SUPPORTED_INVALID_FORMAT 0x12
#define NRC_BUSY_REPEAT_REQUEST 0x21
#define NRC_CONDITIONS_NOT_CORRECT_REQ_SEQ_ERROR 0x22
#define NRC_ROUTINE_NOT_COMPLETE 0x23
#define NRC_REQUEST_OUT_OF_RANGE 0x31
#define NRC_SECURITY_ACCESS_DENIED 0x33
#define NRC_INVALID_KEY 0x35
#define NRC_EXCEED_NUMBER_OF_ATTEMPTS 0x36
#define NRC_REQUIRED_TIME_DELAY_NOT_EXPIRED 0x37
#define NRC_DOWNLOAD_NOT_ACCEPTED 0x40
#define NRC_UPLOAD_NOT_ACCEPTED 0x50
#define NRC_TRANSFER_SUSPENDED 0x71
#define NRC_RESPONSE_PENDING 0x78
#define NRC_SERVICE_NOT_SUPPORTED_IN_ACTIVE_DIAG_SESSION 0x80
#define NRC_DATA_DECOMPRESSION_FAILED 0x9A
#define NRC_DATA_DECRYPTION_FAILED 0x9B
#define NRC_ECU_NOT_RESPONDING 0xA0

/*
KWP Response types (Used by multiple SID parameters)
*/
#define KWP_CMD_RESPONSE_REQUIRED 0x01
#define KWP_CMD_NO_RESPONSE_REQUIRED 0x02

/*
KWP2000 diagnostic session modes
Used by SID_START_DIAGNOSTIC_SESSION
*/
#define SESSION_DEFAULT 0x81
#define SESSION_REPROGRAMMING 0x85
#define SESSION_STANDBY 0x89
#define SESSION_PASSIVE 0x90
#define SESSION_EXTENDED 0x92
#define SESSION_CUSTOM_UN52 0x93 // Custom for UN52. This lets me do a few extra things

/*
ECU Reset modes
Used by SID_ECU_RESET
*/
#define ECU_RESET_POWER_ON 0x01
#define ECU_RESET_NON_VOLATILE 0x82

/*
Status type of DTC request
Used by SID_READ_DTCS_BY_STATUS
*/
#define DTC_STATUS_IDENTIFIED_SAE_J2012 0x00
#define DTC_STATUS_SUPPORTED_SAE_J2012 0x01
#define DTC_STATUS__IDENTIFIED_2_BYTE_HEX 0x02
#define DTC_STATUS_SUPPORTED_2_BYTE_HEX 0x03
#define DTC_STATUS_MOST_RECENT_DTC 0x04
#define DTC_STATUS_EXTENDED_SUPPORTED_DTC 0xE0

/*
ECU Identification type
Used by SID_READ_ECU_IDENT
*/
#define ECU_IDENT_DAIMLER 0x86
#define ECU_IDENT_MITSUBISHI 0x87
#define ECU_IDENT_VIN_ORIGINAL 0x88
#define ECU_IDENT_DIAG_VAR_CODE 0x89
#define ECU_IDENT_VIN_CURRENT 0x90
#define ECU_IDENT_CALIBRATION_ID 0x96 // Calibration identifier
#define ECU_IDENT_CALIBRATION_VN 0x97 // Calibration verification number
#define ECU_IDENT_CODE_FINGERPRINT 0x9A
#define ECU_IDENT_DATA_FINGERPRINT 0x9B
#define ECU_IDENT_CODE_SW_IDENT 0x9C
#define ECU_IDENT_DATA_SW_IDENT 0x9D
#define ECU_IDENT_BOOT_SW_IDENT 0x9E
#define ECU_IDENT_BOOT_FINGERPRINT 0x9F


/*
Local identifiers
Used by SID_READ_DATA_BY_LOCAL_IDENT and SID_WRITE_DATA_BY_LOCAL_IDENT
*/
#define LOCAL_IDENT_DEV_DATA 0xE0
#define LOCAL_IDENT_ECU_SERIAL_NUMBER 0xE1
#define LOCAL_IDENT_DBCOM_DATA 0xE2
#define LOCAL_IDENT_OS_VERSION 0xE3
#define LOCAL_IDENT_ECU_REPROGRAMMING_ID 0xE4
#define LOCAL_IDENT_VEHICLE_INFO 0xE5
#define LOCAL_IDENT_FLASH_INFO_1 0xE6
#define LOCAL_IDENT_FLASH_INFO_2 0xE7
#define LOCAL_IDENT_SYS_DIAG_GENERAL_PARAM_DATA 0xE8
#define LOCAL_IDENT_SYS_DIAG_GLOBAL_PARAM_DATA 0xE9
#define LOCAL_IDENT_ECU_CONFIG 0xEA
#define LOCAL_IDENT_DIAG_PROTOCOL_VERSION 0xEB


/* IOCTL Control params
Used by SID_IOCTL_BY_LOCAL_IDENT
*/

#define IOCTL_PARAM_RETURN_CONTROL_TO_ECU 0x00
#define IOCTL_PARAM_REPORT_CURRENT_STATE 0x01
#define IOCTL_PARAM_RESET_TO_DEFAULT 0x04
#define IOCTL_PARAM_FREEZE_CURRENT_DATA 0x05
#define IOCTL_PARAM_SHORT_TERM_ADJ 0x07
#define IOCTL_PARAM_LONG_TERM_ADJ 0x08

/*
Routine identifiers
Used by SID_START_ROUTINE_BY_LOCAL_IDENT, SID_STOP_ROUTINE_BY_LOCAL_IDENT and SID_REQUEST_ROUTINE_RESULTS_BY_LOCAL_IDENT
*/
#define ROUTINE_FLASH_ERASE 0xE0
#define ROUTINE_FLASH_CHECK 0xE1
#define ROUTINE_REQUEST_DTCS_FROM_SHADOW_ERR_MEM 0xE3
#define ROUTINE_REQUEST_ENV_DATA_FROM_SHADOW_ERR_MEM 0xE4
#define ROUTINE_REQUEST_EVENT_INFORMATION 0xE5
#define ROUTINE_REQUEST_EVENT_ENV_DATA 0xE6
#define ROUTINE_REQUEST_SW_MODULE_VERSION 0xE7
#define ROUTINE_CLEAR_TELL_TALE_RETENTION_STACK 0xE8


/*
Event window time
Used by SID_RESPONSE_ON_EVENT
*/
#define EVENT_WINDOW_TESTER_PRESENT_REQUIRED 0x01
#define EVENT_WINDOW_INFINITE_TIME 0x02
#define EVENT_WINDOW_NONE 0x80

/*
Event type
Used by SID_RESPONSE_ON_EVENT
*/
#define EVENT_TYPE_REPORT_ACTIVATED_EVENTS 0x80
#define EVENT_TYPE_STOP_RESPONSE_ON_EVENT 0x81
#define EVENT_TYPE_ON_NEW_DTC 0x82
#define EVENT_TYPE_ON_TIMER_INTERRUPT 0x83
#define EVENT_TYPE_ON_CHANGE_OF_RECORD_VALUE 0x84
#define EVENT_TYPE_ON_COMPARISON_OF_VALUES 0xA0

#endif