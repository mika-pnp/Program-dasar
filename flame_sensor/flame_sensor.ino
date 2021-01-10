#define SENSOR_API_1 A8
#define SENSOR_API_2 A9
#define SENSOR_API_3 A10
#define SENSOR_API_4 A11
#define SENSOR_API_5 A12

void setup() {
  Serial.begin(9600);

  pinMode( SENSOR_API_1 , INPUT);
  pinMode( SENSOR_API_2 , INPUT);
  pinMode( SENSOR_API_3 , INPUT);
  pinMode( SENSOR_API_4 , INPUT);
  pinMode( SENSOR_API_5 , INPUT);
}

void loop() {
  Serial.print( digitalRead(SENSOR_API_1) ); Serial.print("  ");
  Serial.print( digitalRead(SENSOR_API_2) ); Serial.print("  ");
  Serial.print( digitalRead(SENSOR_API_3) ); Serial.print("  ");
  Serial.print( digitalRead(SENSOR_API_4) ); Serial.print("  ");
  Serial.print( digitalRead(SENSOR_API_5) ); Serial.println();

}
