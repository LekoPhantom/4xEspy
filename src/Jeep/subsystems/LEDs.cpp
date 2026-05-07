#include "LEDs.h"

#define LED_PIN   10      // change if needed
#define NUM_LEDS  2

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void LEDs::init() {
    strip.begin();
    strip.setBrightness(255);

    // Initial test colors
    strip.setPixelColor(0, strip.Color(255, 0, 0));   // Red
    strip.setPixelColor(1, strip.Color(0, 0, 255));   // Blue
    strip.show();
}

void LEDs::update() {
    static uint8_t hue = 0;

    // Simple hue cycle
    uint32_t c1 = strip.ColorHSV(hue * 256);
    uint32_t c2 = strip.ColorHSV((hue + 64) * 256);

    strip.setPixelColor(0, c1);
    strip.setPixelColor(1, c2);

    hue++;
    strip.show();
}
