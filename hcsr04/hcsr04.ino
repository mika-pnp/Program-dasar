//----------------------------------------------------------------------------------
//HC-SR04

#define TRIGGER_1 22
#define TRIGGER_2 26
#define TRIGGER_3 30
#define TRIGGER_4 34
#define TRIGGER_5 38
#define TRIGGER_6 42
#define TRIGGER_7 46

#define ECHO_1 24
#define ECHO_2 28
#define ECHO_3 32
#define ECHO_4 36
#define ECHO_5 40
#define ECHO_6 44
#define ECHO_7 48
//----------------------------------------------------------------------------------

long BacaJarak(float trigger, float echo) {
// Trigger - Output : Echo - Input
  digitalWrite(trigger, HIGH); delay(5); digitalWrite(trigger, LOW);
  
  return ( pulseIn(echo, HIGH) / 2 ) / 29.1;
}

void setup() {
  Serial.begin(9600);
  
  //insisial hcsr
  pinMode(22, OUTPUT); digitalWrite(22, LOW); pinMode(26, OUTPUT); digitalWrite(26, LOW);
  pinMode(30, OUTPUT); digitalWrite(30, LOW); pinMode(34, OUTPUT); digitalWrite(34, LOW);
  pinMode(38, OUTPUT); digitalWrite(38, LOW); pinMode(42, OUTPUT); digitalWrite(42, LOW);
  pinMode(46, OUTPUT); digitalWrite(46, LOW);

  pinMode(24, INPUT); pinMode(28, INPUT); pinMode(32, INPUT); pinMode(36, INPUT);
  pinMode(40, INPUT); pinMode(44, INPUT); pinMode(48, INPUT);
}

void loop() {
  Serial.print( BacaJarak( TRIGGER_1, ECHO_1 ) ); Serial.print("  ");
  Serial.print( BacaJarak( TRIGGER_2, ECHO_2 ) ); Serial.print("  ");
  Serial.print( BacaJarak( TRIGGER_3, ECHO_3 ) ); Serial.print("  ");
  Serial.print( BacaJarak( TRIGGER_4, ECHO_4 ) ); Serial.print("  ");
  Serial.print( BacaJarak( TRIGGER_5, ECHO_5 ) ); Serial.print("  ");
  Serial.print( BacaJarak( TRIGGER_6, ECHO_6 ) ); Serial.print("  ");
  Serial.print( BacaJarak( TRIGGER_7, ECHO_7 ) );
  Serial.println();
}
