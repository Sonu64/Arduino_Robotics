// Pins
const int LEDPin = 11, buttonPin = 9;
// LED State
bool LEDState = 0;
// Button States
int lastState = 0, currentState;
// Debounce function to avoid switch bouncing during transitions
int debounce(int);

int debounce(int last) {
  int current = digitalRead(buttonPin);
  if (current != last) {
    current = digitalRead(buttonPin);
    delay(50);
  }
  return current;
}

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  // Read current state from debounce function
  currentState = debounce(lastState);

  // Change state of bulb only during 1-->0 Transition, Pull-Down Resistor Added
  if (lastState==1 && currentState==0) {
    if (LEDState == 0) {
      digitalWrite(LEDPin, HIGH);
      LEDState = !LEDState; // 1
    }
    else {
      digitalWrite(LEDPin, LOW);
      LEDState = !LEDState; // 0      
    }
  }

  lastState = currentState;
  //delay(150); Don't need delay here when using seperate debounce function

}
