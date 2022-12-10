#include "eeprom_config.h"
#include "esp_log.h"
#include "scn.h"
#include "speaker.h"
#include <string.h>
#include "profiles.h"
#include "efuse/efuse.h"
#include "esp_efuse.h"

bool EEPROM::read_nvs_map_data(const char* map_name, int16_t* dest, const int16_t* default_map, size_t map_element_count) {
    size_t byte_count = map_element_count*sizeof(int16_t);
    esp_err_t e = nvs_get_blob(MAP_NVS_HANDLE, map_name, dest, &byte_count);
    if (e == ESP_ERR_NVS_NOT_FOUND && default_map != nullptr) {
        ESP_LOG_LEVEL(ESP_LOG_WARN, "EEPROM", "Map %s not found in NVS. Setting to default map from prog flash", map_name);
        // Set default map data
        if (write_nvs_map_data(map_name, default_map, map_element_count)) {
            ESP_LOG_LEVEL(ESP_LOG_INFO, "EEPROM", "Map %s copied OK to NVS!", map_name);
        } else {
            ESP_LOG_LEVEL(ESP_LOG_WARN, "EEPROM", "Map %s not copied to NVS! Using flash default map", map_name);
        }
    }
    if(e != ESP_OK) {
        if (default_map != nullptr) {
            memcpy(dest, default_map, byte_count);
        } else {
            return false;
        }
    } else {
        ESP_LOG_LEVEL(ESP_LOG_INFO, "EEPROM", "Map %s loaded OK from NVS!", map_name);
    }
    return true;
}

bool EEPROM::write_nvs_map_data(const char* map_name, const int16_t* to_write, size_t map_element_count) {
    esp_err_t e = nvs_set_blob(MAP_NVS_HANDLE, map_name, to_write, map_element_count*sizeof(int16_t));
    if (e != ESP_OK) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error setting value for %s (%s)", map_name, esp_err_to_name(e));
        return false;
    }
    e = nvs_commit(MAP_NVS_HANDLE);
    if (e != ESP_OK) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error calling nvs_commit: %s", esp_err_to_name(e));
        return false;
    }
    return true;
}

// bool read_nvs_gear_adaptation(nvs_handle_t handle, const char* key, pressure_map* map, size_t store_size) {
//     esp_err_t e = nvs_get_blob(handle, key, map, &store_size);
//     if (e == ESP_ERR_NVS_NOT_FOUND) {
//         ESP_LOG_LEVEL(ESP_LOG_WARN, "EEPROM", "Adaptation %s map not found. Creating a new one", key);
//         pressure_map new_map = {0,0,0,0,0,0,0,0,0,0,0};
//         e = nvs_set_blob(handle, key, &new_map, sizeof(new_map));
//         if (e != ESP_OK) {
//             ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error initializing default adaptation map map data (%s)", esp_err_to_name(e));
//             return false;
//         }
//         e = nvs_commit(handle);
//         if (e != ESP_OK) {
//             ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error calling nvs_commit: %s", esp_err_to_name(e));
//             return false;
//         }
//         ESP_LOG_LEVEL(ESP_LOG_INFO, "EEPROM", "New TCC map creation OK!");
//         memcpy(map, new_map, sizeof(new_map));
//         return true;
//     }
//     return (e == ESP_OK);
// }

bool EEPROM::init_eeprom() {
    // Called on startup

    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "EEPROM init failed! %s", esp_err_to_name(err));
        // Don't erase flash. User has to do this manually. Just POST beep!
        return false;
    }
    nvs_handle_t config_handle;    
    err = nvs_open(NVS_PARTITION_USER_CFG, NVS_READWRITE, &config_handle);
    if (err != ESP_OK) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "EEPROM NVS handle failed! %s", esp_err_to_name(err));
        return false;
    }
    MAP_NVS_HANDLE = config_handle;
    bool res = read_core_config(&VEHICLE_CONFIG);
    if (!res) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "EEPROM SCN config read failed! %s", esp_err_to_name(err));
        return false;
    }
    return true;
}

bool EEPROM::read_core_config(TCM_CORE_CONFIG* dest) {
    nvs_handle_t handle;
    nvs_open(NVS_PARTITION_USER_CFG, NVS_READWRITE, &handle); // Must succeed as we have already opened it!
    size_t s = sizeof(TCM_CORE_CONFIG);
    esp_err_t e = nvs_get_blob(handle, NVS_KEY_SCN_CONFIG, dest, &s);
    if (e == ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOG_LEVEL(ESP_LOG_WARN, "EEPROM", "SCN Config not found. Creating a new one");
        TCM_CORE_CONFIG c = {
            .is_large_nag = 0,
            .diff_ratio = 1000,
            .wheel_circumference = 2850,
            .is_four_matic = 0,
            .transfer_case_high_ratio = 1000,
            .transfer_case_low_ratio = 1000,
            .default_profile = 0, // Standard
            .red_line_rpm_diesel = 4500, // Safe for diesels, petrol-heads can change this!
            .red_line_rpm_petrol = 6000,
            .engine_type = 0,
            .egs_can_type = 0,
            .shifter_style = 0,
            .io_0_usage = 0,
            .input_sensor_pulses_per_rev = 1,
            .output_pulse_width_per_kmh = 1,
            .gen_mosfet_purpose = 0,
        };
        e = nvs_set_blob(handle, NVS_KEY_SCN_CONFIG, &c, sizeof(c));
        if (e != ESP_OK) {
            ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error initializing default SCN config (%s)", esp_err_to_name(e));
            return false;
        }
        e = nvs_commit(handle);
        if (e != ESP_OK) {
            ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error calling nvs_commit: %s", esp_err_to_name(e));
            return false;
        }
        ESP_LOG_LEVEL(ESP_LOG_INFO, "EEPROM", "New SCN  creation OK!");
        memcpy(dest, &s, sizeof(s));
        return true;
    } else if (e != ESP_OK) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Could not read SCN config: %s", esp_err_to_name(e));
    }
    return (e == ESP_OK);
}

bool EEPROM::save_core_config(TCM_CORE_CONFIG* write) {
    nvs_handle_t handle;
    esp_err_t e;
    size_t s = sizeof(TCM_CORE_CONFIG);
    nvs_open(NVS_PARTITION_USER_CFG, NVS_READWRITE, &handle); // Must succeed as we have already opened it!
    e = nvs_set_blob(handle, NVS_KEY_SCN_CONFIG, write, s);
    if (e != ESP_OK) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error Saving SCN config (%s)", esp_err_to_name(e));
        return false;
    }
    e = nvs_commit(handle);
    if (e != ESP_OK) {
        ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error calling nvs_commit: %s", esp_err_to_name(e));
        return false;
    }
    return true;
}

bool EEPROM::read_efuse_config(TCM_EFUSE_CONFIG* dest) {
    if (dest == nullptr) {
        return false;
    }
    esp_efuse_read_field_blob(ESP_EFUSE_BOARD_VER, &dest->board_ver, 8);
    esp_efuse_read_field_blob(ESP_EFUSE_M_DAY, &dest->manufacture_day, 8);
    esp_efuse_read_field_blob(ESP_EFUSE_M_WEEK, &dest->manufacture_week, 8);
    esp_efuse_read_field_blob(ESP_EFUSE_M_MONTH, &dest->manufacture_month, 8);
    esp_efuse_read_field_blob(ESP_EFUSE_M_YEAR, &dest->manufacture_year, 8);
    ESP_LOG_LEVEL(ESP_LOG_INFO, "READ EFUSE", "CONFIG:Board Ver: V1.%d, Week %d (%02d/%02d/%02d)", dest->board_ver, dest->manufacture_week, dest->manufacture_day, dest->manufacture_month, dest->manufacture_year);
    return true;
}

bool EEPROM::write_efuse_config(TCM_EFUSE_CONFIG* dest) {
    if (dest == nullptr) {
        return false;
    }
    if (dest->manufacture_month > 12 || dest->manufacture_month == 0) {
        return false;
    }
    if (dest->manufacture_day > 31 || dest->manufacture_day == 0) {
        return false;
    }
    if (dest->manufacture_week > 52 || dest->manufacture_week == 0) {
        return false;
    }
    if (dest->manufacture_year < 22) {
        return false;
    }
    if (dest->board_ver == 0 || dest->board_ver > 3) {
        return false;
    }
    if (esp_efuse_write_field_blob(ESP_EFUSE_BOARD_VER, &dest->board_ver, 8) != ESP_OK) {
        return false;
    }
    if (esp_efuse_write_field_blob(ESP_EFUSE_M_DAY, &dest->manufacture_day, 8) != ESP_OK) {
        return false;
    }
    if (esp_efuse_write_field_blob(ESP_EFUSE_M_WEEK, &dest->manufacture_week, 8) != ESP_OK) {
        return false;
    }
    if (esp_efuse_write_field_blob(ESP_EFUSE_M_MONTH, &dest->manufacture_month, 8) != ESP_OK) {
        return false;
    }
    if (esp_efuse_write_field_blob(ESP_EFUSE_M_YEAR, &dest->manufacture_year, 8) != ESP_OK) {
        return false;
    }
    return true;
    
}

TCM_CORE_CONFIG VEHICLE_CONFIG = {};
TCM_EFUSE_CONFIG BOARD_CONFIG = {};
nvs_handle_t MAP_NVS_HANDLE = {};