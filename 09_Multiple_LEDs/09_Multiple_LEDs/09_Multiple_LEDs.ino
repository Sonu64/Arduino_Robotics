int redPin = 11;
int greenPin = 9;
int bluePin = 6;
int baudRate = 9600;
String prompt = "Type LED color to Lit: ";
String chosenColor;
void setup()
{
  Serial.begin(baudRate);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  Serial.println(prompt);
  while(Serial.available()==0) {
  }
  chosenColor = Serial.readString();
  chosenColor.toLowerCase();
  chosenColor.trim();
  //Serial.println(chosenColor);
  
  while(!chosenColor.equals("red") && !chosenColor.equals("green") && !chosenColor.equals("blue")) {
  	Serial.println("Please Enter a Valid Color ! :");
    while(Serial.available() == 0){
    }
    chosenColor = Serial.readString();
    chosenColor.toLowerCase();
    chosenColor.trim();
  }
  

  analogWrite(redPin, LOW);
  analogWrite(greenPin, LOW);
  analogWrite(bluePin, LOW);
  
  if(chosenColor == "red")
    analogWrite(redPin, 255);
  if(chosenColor == "green")
    analogWrite(greenPin, 255);
  if(chosenColor == "blue")
    analogWrite(bluePin, 255);
}