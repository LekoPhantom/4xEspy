#include <Arduino.h>
#include <sanity.h>
#include <ESP32Servo.h>
#include "Constants.h"

Servo steering;



void setup() {
    sanity_serial("jeep");
    sanity_board_info("jeep");

    // Steering
    steering.attach(5);
    delay(500);
    steering.writeMicroseconds(1500);
    Serial.println("[jeep] Steering centered");
    delay(1000);

    // Motor pins
    pinMode(motorA, OUTPUT);
    pinMode(motorB, OUTPUT);

    Serial.println("[jeep] Auto-drive starting...");
    digitalWrite(motorA, HIGH);
    digitalWrite(motorB, LOW);

    delay(5000);  // 5 seconds of forward motion

    Serial.println("[jeep] Auto-drive complete. Stopping.");
    digitalWrite(motorA, LOW);
    digitalWrite(motorB, LOW);
}

void loop() {
    // stay idle
}
