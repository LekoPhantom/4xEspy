#include <Arduino.h>
#include "sanity.h"
// Sanity check functions for the ESP32-C3. These are used to verify that the serial communication is working correctly.

void sanity_serial(const char* tag) {
    Serial.begin(115200);
    delay(2000);
    Serial.printf("[%s] serial OK\n", tag);
}

#include "esp_system.h"
#include "esp_chip_info.h"
#include "esp_flash.h"

void sanity_board_info(const char* tag) {
    Serial.begin(115200);
    delay(2000);

    esp_chip_info_t chip;
    esp_chip_info(&chip);

    uint32_t flash_size = 0;
    esp_flash_get_size(NULL, &flash_size);

    Serial.printf("\n[%s] Board Info\n", tag);
    Serial.printf("  Model: ESP32-%s\n", 
        chip.model == CHIP_ESP32 ? "D0WDQ6" :
        chip.model == CHIP_ESP32S3 ? "S3" :
        chip.model == CHIP_ESP32C3 ? "C3" : "Unknown");

    Serial.printf("  Cores: %d\n", chip.cores);
    Serial.printf("  Revision: %d\n", chip.revision);
    Serial.printf("  Flash: %lu MB\n", flash_size / (1024 * 1024));
    Serial.printf("  CPU Freq: %lu MHz\n", getCpuFrequencyMhz());
    Serial.printf("  SDK: %s\n", esp_get_idf_version());

    uint8_t mac[6];
    esp_read_mac(mac, ESP_MAC_WIFI_STA);
    Serial.printf("  MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    Serial.println();
}

#include <esp_now.h>
#include <WiFi.h>
#include "sanity.h"

static void on_receive(const uint8_t* mac, const uint8_t* data, int len) {
    Serial.printf("[espnow] RX from %02X:%02X:%02X:%02X:%02X:%02X: %.*s\n",
        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5],
        len, data);
}

void sanity_espnow(const char* tag) {
    Serial.begin(115200);
    delay(2000);

    Serial.printf("[%s] Initializing ESP-NOW...\n", tag);

    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        Serial.println("ESP-NOW init failed");
        return;
    }

    esp_now_register_recv_cb(on_receive);

    Serial.println("ESP-NOW ready.");
}

