// C++ code
//
const int LEDPin = 11;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDPin, OUTPUT); // PWM Pin will have analog outputs
}

void loop()
{
  for (int i=0; i<=255; i+=5) {
    analogWrite(LEDPin, i);
    delay(1000);
  }
  for (int i=255; i>=0; i-=5) {
    analogWrite(LEDPin, i);
    delay(1000);
  }
}