#include "JeepMotion.h"

JeepMotion::JeepMotion(int steeringPin, int motorA, int motorB)
    : steeringPin(steeringPin), motorA(motorA), motorB(motorB) {}

void JeepMotion::begin() {
    // Steering
    steering.attach(steeringPin);
    delay(300);

    // Motor pins
    pinMode(motorA, OUTPUT);
    pinMode(motorB, OUTPUT);

    // Default to stopped
    digitalWrite(motorA, LOW);
    digitalWrite(motorB, LOW);
}

void JeepMotion::centerSteering() {
    steering.writeMicroseconds(1500);  // neutral
}

void JeepMotion::autoDriveForward(uint32_t durationMs) {
    // Forward
    digitalWrite(motorA, HIGH);
    digitalWrite(motorB, LOW);

    delay(durationMs);

    // Stop
    digitalWrite(motorA, LOW);
    digitalWrite(motorB, LOW);
}
