#pragma once
#include <Arduino.h>
#include <ESP32Servo.h>

class JeepMotion {
public:
    JeepMotion(int steeringPin, int motorA, int motorB);

    void begin();
    void centerSteering();
    void autoDriveForward(uint32_t durationMs);

private:
    Servo steering;
    int steeringPin;
    int motorA;
    int motorB;
};
