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
#include <Arduino.h>
#include <sanity.h>
#include "JeepMotion.h"

// Pin definitions (adjust to your wiring)
constexpr int STEER_PIN = 5;
constexpr int MOTOR_A   = 9;
constexpr int MOTOR_B   = 10;

JeepMotion jeep(STEER_PIN, MOTOR_A, MOTOR_B);

void setup() {
    sanity_serial("jeep");
    sanity_board_info("jeep");

    jeep.begin();
    jeep.centerSteering();

    delay(2000); // let you align the wheels

    jeep.autoDriveForward(5000); // 5 seconds
}

void loop() {
    // idle
}
