#include <Scheduler.h>

#define trigger 52
#define echo    53
float jarak;

void setup() {
    Serial.begin(9600);

    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    Scheduler.startLoop(loop1);
}

int first = millis();
void loop() {
    int now = millis();

    if(now - first >= 300) {
        Serial.print(now - first);
        Serial.print("    ");
        Serial.println(jarak);
        first = now;
    }

    // digitalWrite(trigger, HIGH); delayMicroseconds(10); digitalWrite(trigger, LOW);
    // jarak = ( pulseIn(echo, HIGH) / 2 ) / 29.1;

    // Serial.println(jarak);

    yield();
}

void loop1() {
    digitalWrite(trigger, HIGH); delayMicroseconds(10); digitalWrite(trigger, LOW);
    jarak = ( pulseIn(echo, HIGH) / 2 ) / 29.1;

    yield();
}