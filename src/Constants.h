// This document is where you can put universal constants that are used across multiple files in the project. For example, you might want to define the broadcast address for ESP-NOW communication here, so that it can be easily updated in one place if needed. You can also include any other constants that are relevant to your project, such as pin numbers, message formats, or timing intervals.


//Motors: Each motor needs two pins if using the H bridge, but for simplicity we will assume one pin per motor for forward motion and the other pin will be used for reverse motion. Adjust as necessary based on your specific motor driver and wiring.
const int motorA = 9;
const int motorB = 10;

//Servo
const int steeringPin = 5;
