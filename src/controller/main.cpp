#include <Arduino.h>
#include <sanity.h>
#include <esp_now.h>
#include <WiFi.h>

uint8_t broadcast_addr[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

void setup() {
    sanity_serial("controller");
    sanity_board_info("controller");
    sanity_espnow("controller");

    esp_now_peer_info_t peer{};
    memcpy(peer.peer_addr, broadcast_addr, 6);
    peer.channel = 0;
    peer.encrypt = false;
    esp_now_add_peer(&peer);
}

void loop() {
     const char* msg = "ping";
    esp_now_send(broadcast_addr, (uint8_t*)msg, strlen(msg));
    Serial.println("[controller] sent ping");
    delay(1000);
}
