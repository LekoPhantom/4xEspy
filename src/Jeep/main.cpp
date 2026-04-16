#include <Arduino.h>
#include <sanity.h>

void setup() {
    sanity_serial("jeep");
    sanity_board_info("jeep");
    sanity_espnow("jeep");
}

void loop() {
    delay(1000);
}
