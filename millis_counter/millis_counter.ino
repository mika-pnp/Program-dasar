#include <Scheduler.h>

void setup() {
  Serial.begin(9600);

  Scheduler.startLoop(loop2);
}

int first = millis();
void loop() {
  if(millis() - first >= 300) {
    Serial.println(now);
    first = now;
  }

//  delay(100);
  yield();
}

int first2 = millis();
void loop2() {
  if(millis() - first2 >= 1000) {
    Serial.print("   ");
    Serial.println(now1);
    first2 = now1;
  }

//  delay(100);
  yield();
}
