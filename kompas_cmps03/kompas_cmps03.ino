#include <Wire.h>
#define ADDRESS 0x60

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
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
  int sudutKompas = ((highByte << 8) + lowByte) / 10;

  Serial.println(sudutKompas);
}
