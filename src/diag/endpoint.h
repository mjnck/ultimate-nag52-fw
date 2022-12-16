#ifndef DIAG_ENDPOINT_H
#define DIAG_ENDPOINT_H

#include <stdint.h>
#include <driver/uart.h>
#include "esp_log.h"
#include "string.h"
#include "canbus/can_hal.h"
#include "esp_core_dump.h"
#include "tcu_maths.h"
#include "driver/twai.h"

// #define DIAG_CAN_MAX_SIZE 4095 // ISO-TP Maximum
static const uint16_t DIAG_CAN_MAX_SIZE = 4095u; // ISO-TP Maximum

struct DiagMessage
{
    uint16_t id;
    uint16_t data_size;
    uint8_t data[DIAG_CAN_MAX_SIZE]; // 512B messages max (EGS52/3 is always max 256 bytes)
};

struct CanEndpointMsg
{
    uint8_t data[DIAG_CAN_MAX_SIZE];
    uint16_t curr_pos;
    uint16_t max_pos;
};

/**
 * @brief Abstract endpoint
 *
 */
class AbstractEndpoint
{
public:
    AbstractEndpoint(void){};
    virtual void send_data(DiagMessage *msg); // Blocking operation
    virtual bool read_data(DiagMessage *dest);
};

/**
 * @brief Endpoint for USB communication with ultimate-nag52 custom USB util
 *
 */
#define UART_NUM

const static size_t UART_MSG_SIZE = 6 + (2 * DIAG_CAN_MAX_SIZE);

class UsbEndpoint : public AbstractEndpoint
{
public:
    const char HEX_DEF[17] = "0123456789ABCDEF";
    explicit UsbEndpoint(bool can_use_spiram) : AbstractEndpoint()
    {
        data_size = 0;
        line_idx = 0;
        max_bytes_left = 0;
        to_read = 0;
        length = 0;
        esp_err_t e;
        this->allocation_psram = can_use_spiram;
        e = uart_driver_install(0, UART_MSG_SIZE / 2u, UART_MSG_SIZE / 2u, 0, nullptr, 0);
        if (e == ESP_OK)
        {
            if (this->allocation_psram)
            {
                this->read_buffer = static_cast<char *>(heap_caps_malloc(UART_MSG_SIZE, MALLOC_CAP_SPIRAM));
                this->write_buffer = static_cast<char *>(heap_caps_malloc(UART_MSG_SIZE, MALLOC_CAP_SPIRAM));
            }
            else
            {
                // TODO: can_use_spiram is always true, since UsbEndpoint is only called with "true"; it should thus be considered to remove the parameter; MISRA-C proposes not to use malloc()
                this->read_buffer = static_cast<char *>(malloc(UART_MSG_SIZE));
                this->write_buffer = static_cast<char *>(malloc(UART_MSG_SIZE));
            }
            if (nullptr != this->read_buffer)
            {
                uart_flush(0);
                this->read_pos = 0;
            }
        }
        else
        {
            ESP_LOG_LEVEL(ESP_LOG_ERROR, "USBEndpoint", "Error installing UART driver: %s", esp_err_to_name(e));
        }
    }

    void send_data(DiagMessage *msg) override
    {
        this->write_buffer[0] = '#';
        this->write_buffer[1] = HEX_DEF[(msg->id >> 12) & 0x0F];
        this->write_buffer[2] = HEX_DEF[(msg->id >> 8) & 0x0F];
        this->write_buffer[3] = HEX_DEF[(msg->id >> 4) & 0x0F];
        this->write_buffer[4] = HEX_DEF[msg->id & 0x0F];
        for (uint16_t i = 0; i < msg->data_size; i++)
        {
            this->write_buffer[5 + (i * 2)] = HEX_DEF[(msg->data[i] >> 4) & 0x0F];
            this->write_buffer[6 + (i * 2)] = HEX_DEF[msg->data[i] & 0x0F];
        }
        this->write_buffer[(msg->data_size * 2) + 5] = '\n';
        uart_write_bytes(0, &this->write_buffer[0], (msg->data_size * 2) + 6);
    }

    bool read_data(DiagMessage *dest) override
    {
        this->length = 0;
        uart_get_buffered_data_len(0, &length);
        if (length != 0)
        {
            max_bytes_left = UART_MSG_SIZE - this->read_pos;
            to_read = MIN(length, max_bytes_left);
            uart_read_bytes(0, &this->read_buffer[this->read_pos], to_read, 0);
            this->read_pos += length;
            return false;
        }
        else if (this->read_pos != 0)
        {
            if (this->read_pos < 5)
            {
                ESP_LOG_LEVEL(ESP_LOG_ERROR, "USBEndpoint", "Corrupt incoming msg. Less than 5 bytes");
                this->read_pos = 0;
                return false;
            }
            else
            {
                uint16_t read_size = (this->read_buffer[0] << 8) | this->read_buffer[1];
                if (read_size != this->read_pos - 2)
                {
                    ESP_LOG_LEVEL(ESP_LOG_ERROR, "USBEndpoint", "Corrupt incoming msg. Msg size is %d bytes, buffer has %d bytes", read_size, this->read_pos - 2);
                    this->read_pos = 0;
                    return false;
                }
                else
                {
                    // Valid msg!
                    dest->id = (this->read_buffer[2] << 8) | this->read_buffer[3];
                    dest->data_size = read_size - 2;
                    memcpy(dest->data, &this->read_buffer[4], dest->data_size);
                    this->read_pos = 0;
                    return true;
                }
            }
        }
        return false;
    }

private:
    // NOTE TO SELF
    // Every USB MSG:
    // {ID: 0x07E0, Data: [0x00, 0x11, 0x22, 0x33]} = '#07E100112233\n'
    // Read msg size: 6 bytes: USB message size: 14 = (Read size *2) + 2
    char *read_buffer;
    char *write_buffer;
    uint16_t read_pos;
    bool clear_to_send = false;
    bool allocation_psram = false;
    int data_size;
    int line_idx;
    int max_bytes_left;
    int to_read;
    size_t length;
};

/**
 * @brief Endpoint for ISO-TP communication with OBD readers
 *
 */
class CanEndpoint : public AbstractEndpoint
{
public:
    explicit CanEndpoint(EgsBaseCan *can_layer);
    void send_data(DiagMessage *msg) override;
    bool read_data(DiagMessage *dest) override;
    static void start_iso_tp(void *_this)
    {
        static_cast<CanEndpoint *>(_this)->iso_tp_server_loop();
    }

private:
    void process_single_frame(DiagCanMessage msg);
    void process_start_frame(DiagCanMessage msg);
    void process_multi_frame(DiagCanMessage msg);
    void process_flow_control(DiagCanMessage msg);

    [[noreturn]] void iso_tp_server_loop();
    EgsBaseCan *can;
    QueueHandle_t rx_queue;
    // QueueHandle_t tx_queue;
    CanEndpointMsg tx_msg;
    CanEndpointMsg rx_msg;
    QueueHandle_t read_msg_queue;
    QueueHandle_t send_msg_queue;
    CanEndpointMsg tmp;
    bool is_sending;
    bool clear_to_send;
    bool is_receiving;
    uint8_t rx_bs;
    uint8_t tx_pci = 0x20;
    uint64_t last_rx_time;
    uint64_t last_tx_time;
    uint8_t tx_bs = 8;
    uint8_t tx_stmin = 20;
    uint8_t frames_received = 0;
    twai_message_t tx_can;
    uint8_t tx_count = 0;

    bool send_to_twai(DiagCanMessage msg);
};

#endif