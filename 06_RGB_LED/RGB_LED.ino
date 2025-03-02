// C++ code
// Common Cathode RGB LED
const int RLED = 3, GLED = 6, BLED = 5;
const int buttonPin = 8;
int mode = 0; //default off led
int lastState = 0, currentState;

int debounce(int);


int debounce(int last) {
  int current = digitalRead(buttonPin);
  if (current != last) {
    delay(10);
    current = digitalRead(buttonPin);
  }
  return current;
}


void setMode(int mode){
  //RED
  if (mode == 1){
    digitalWrite(RLED, 1);
    digitalWrite(GLED, 0);
    digitalWrite(BLED, 0);
  }
  //GREEN
  else if (mode == 2){
    digitalWrite(RLED, 0);
    digitalWrite(GLED, 1);
    digitalWrite(BLED, 0);
  }
  //BLUE
  else if (mode == 3){
    digitalWrite(RLED, 0);
    digitalWrite(GLED, 0);
    digitalWrite(BLED, 1);
  }
  else if (mode == 4){
    analogWrite(RLED, 127);
    analogWrite(GLED, 255);
    analogWrite(BLED, 127);
  }
  else if (mode == 5){
    analogWrite(RLED, 255);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  }
  else if (mode == 6){
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 255);
  }
  else if (mode == 7){
    analogWrite(RLED, 170);
    analogWrite(GLED, 170);
    analogWrite(BLED, 170);
  }
  //OFF (mode = 0)
  else {
    digitalWrite(RLED, 0);
    digitalWrite(GLED, 0);
    digitalWrite(BLED, 0);
  }
}






void setup() {
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(buttonPin, INPUT);
}





void loop()
{
   // Read current state from debounce function
  currentState = debounce(lastState);

  // Change state of bulb only during 1-->0 Transition, Pull-Down Resistor Added
  if (lastState==1 && currentState==0) {
    if (mode < 7) {
      mode++;
      setMode(mode);
    }
    else {
      mode = 0;      
    }
  }

  lastState = currentState;
  //delay(150); Don't need delay here when using seperate debounce function
}