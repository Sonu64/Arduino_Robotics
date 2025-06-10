// C++ code
//
const int LEDPin = 8;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop()
{
  digitalWrite(LEDPin, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDPin, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}