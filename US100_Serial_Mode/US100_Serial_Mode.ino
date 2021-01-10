 #include <SoftwareSerial.h>;
 
const int US100_TX = 2;
const int US100_RX = 3;
 
SoftwareSerial US100(US100_RX, US100_TX);
 
unsigned int MSByteDist = 0;
unsigned int LSByteDist = 0;
unsigned int mmDist = 0;
int temp = 0;
 
void setup() {
    Serial.begin(9600);
    US100.begin(9600);
}
 
void loop() {
  //Read temperature
    US100.flush();  US100.write(0x55);  delay(100);
    if(US100.available() >= 2) {
        MSByteDist = US100.read();
        LSByteDist  = US100.read();
        mmDist  = MSByteDist * 256 + LSByteDist;
        if((mmDist > 1) && (mmDist < 10000)) {
            Serial.print("Distance : ");
            Serial.print(mmDist, DEC);
            Serial.println(" mm");
        }
    }
 
    US100.flush();  US100.write(0x50);  delay(100);
    if(US100.available() >= 1) {
        temp = US100.read();
        if((temp > 1) && (temp < 130)) {
            temp -= 45; // corrige offset de 45º
            Serial.print("Temperature : ");
            Serial.print(temp, DEC);
            Serial.println(" ºC");
        }
    }
 
//    delay(500);
}
