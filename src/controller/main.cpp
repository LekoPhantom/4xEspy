#include <Arduino.h>
#include <sanity.h>

void setup() {
    sanity_serial("controller");
}

void loop() {
    delay(1000);
}
