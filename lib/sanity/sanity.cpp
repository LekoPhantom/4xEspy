#include <Arduino.h>
#include "sanity.h"

void sanity_serial(const char* tag) {
    Serial.begin(115200);
    delay(2000);
    Serial.printf("[%s] serial OK\n", tag);
}
