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
  int i;
  for(i=2000; i>=0; i-=500) {
  	digitalWrite(LEDPin, HIGH);
    delay(i);
    digitalWrite(LEDPin, LOW);
    delay(i);
  }
}