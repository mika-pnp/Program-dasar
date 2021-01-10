// Constants
#define SPEED_OF_SOUND               0.0344 // cm/us

// Channel aliases
#define TRIG_PIN_IDX                 52
#define ECHO_PIN_IDX                 53  // has to be an interrupt pin             

volatile uint32_t echoInitialTime = 0;
volatile double distanceCm = 0.0;

void handleEcho(void)
{
  bool risingEdge = digitalRead(ECHO_PIN_IDX);
  if (risingEdge) handleEchoRisingEdge();
  else handleEchoFallingEdge();
}

void handleEchoRisingEdge(void)
{
  echoInitialTime = micros();
}

void handleEchoFallingEdge(void)
{
  uint32_t timeOfFlightRoundTrip = micros() - echoInitialTime;
  distanceCm = (0.0344 * timeOfFlightRoundTrip) / 2.0;
}

void configureTimer1Pwm(void)
{
  // put your setup code here, to run once:
  pinMode(TRIG_PIN_IDX, OUTPUT);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) |_BV(WGM10) | _BV(WGM11);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS11);
  OCR1A = 47903;
  OCR1B = 19;
}

void setup()
{
  cli(); // disable interrupts
  Serial.begin(9600);
  pinMode(ECHO_PIN_IDX, INPUT);
  configureTimer1Pwm();
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN_IDX), handleEcho, CHANGE);
  sei(); // enable interrupts
}

void loop(){
  Serial.println(distanceCm);
}
