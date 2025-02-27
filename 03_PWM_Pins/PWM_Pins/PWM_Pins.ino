// C++ code
//
const int LEDPin = 11;
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDPin, OUTPUT); // PWM Pin will have analog outputs
}

void loop()
{
  for (int i=0; i<=255; i+=50) {
    analogWrite(LEDPin, i);
    delay(10);
  }
  for (int i=255; i>=0; i-=50) {
    analogWrite(LEDPin, i);
    delay(10);
  }
}