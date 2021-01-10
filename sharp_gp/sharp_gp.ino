#define SGP_KANAN A4
#define SGP_DEPAN A3
#define SGP_KIRI A2

void setup() {
  Serial.begin( 9600 );
  
  pinMode( SGP_KANAN , INPUT );
  pinMode( SGP_DEPAN , INPUT );
  pinMode( SGP_KIRI , INPUT );
}

void loop() {
  Serial.print( analogRead( SGP_KANAN) ); Serial.print( "  " );
  Serial.print( analogRead( SGP_DEPAN) ); Serial.print( "  " );
  Serial.print( analogRead( SGP_KIRI) ); Serial.println();
  delay( 300 );
}
