const int LEDPin = 11;
const int ButtonPin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(ButtonPin));
  if (digitalRead(ButtonPin) == 1) 
    digitalWrite(LEDPin, 1);
  else 
    digitalWrite(LEDPin, 0);
}
