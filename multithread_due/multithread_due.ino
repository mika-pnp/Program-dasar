#include <Scheduler.h>

unsigned int value = 10;

void setup() {
    Serial.begin(9600);

    Scheduler.startLoop(loop1);
}

int first = millis();
void loop() {
    int now = millis();

    if(now - first >= 1000) {
        Serial.print(now); Serial.println("  ");
        Serial.println(value);

        first = now;
    }

    yield();
}

void loop1() {
    value++; delay(10);

    yield();
}