#include <Arduino.h>

#include "Robot.h"

Robot robot;

void setup() {
    robot.robotInit();
}

void loop() {
    robot.robotPeriodic();
}
