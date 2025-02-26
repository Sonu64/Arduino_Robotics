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
  for (int i=0; i<=255; i++) {
    analogWrite(LEDPin, i);
    delay(3000);
  }
  for (int i=255; i>=0; i--) {
    analogWrite(LEDPin, i);
    delay(3000);
  }
}