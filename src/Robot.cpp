#pragma once   // This file defines the Robot class, which is the main entry point for the robot code.

#include "subsystems/Drive.h"
//#include "subsystems/Arm.h"
#include "subsystems/LEDs.h"
#include "io/Controller.h"

class Robot {
public:
    void robotInit();
    void robotPeriodic();

private:
    Drive drive;
    //Arm arm;
    LEDs leds;
    Controller controller;
};
