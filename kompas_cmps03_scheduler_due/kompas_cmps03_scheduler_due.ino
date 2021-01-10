#include <Scheduler.h>
#include <Wire.h>
#define ADDRESS 0x60

int sudutKompas;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Scheduler.startLoop(loop2);
}

void loop() {
  Serial.println(sudutKompas);

  delay(100);
}

void loop2() {
  byte highByte;
  byte lowByte;

  Wire.beginTransmission(ADDRESS); //starts communication with cmps03
  Wire.write(2);                   //Sends the register we wish to read
  Wire.endTransmission();

  Wire.requestFrom(ADDRESS, 2); //requests high byte
  while (Wire.available() < 2)
    ;                     //while there is a byte to receive
  highByte = Wire.read(); //reads the byte as an integer
  lowByte = Wire.read();
  sudutKompas = ((highByte << 8) + lowByte) / 10;

  yield();
}
