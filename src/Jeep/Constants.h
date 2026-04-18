// Universal constants for the Jeep project.
// Pin assignments, message formats, timing intervals, etc.

// =======================
// Motor Pins (H-Bridge)
// =======================
// Front motor uses two GPIOs for direction control.
// IO8 and IO7 are safe, non-strapping, non-flash pins.
const int motorA = 8;   // IN1 (front motor)
const int motorB = 7;   // IN2 (front motor)

// =======================
// Steering Servo
// =======================
// IO5 is a clean PWM-capable pin on the ESP32-C3.
const int steeringPin = 5;

// =======================
// NeoPixels
// =======================
// IO10 is safe for RMT-driven NeoPixels.
const int pixelPin = 10;
const int numPixels = 2;
