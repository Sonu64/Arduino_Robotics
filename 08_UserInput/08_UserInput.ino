int baudRate = 9600;
int myInt;
float myFloat;
String myName;
String prompt = "Please Enter Your Name: ";

void setup() {
  Serial.begin(baudRate);
}

void loop() {
  Serial.println(prompt);
  while(Serial.available() == 0) {}
  myName = Serial.readString();
  Serial.println("Enter an Integer: ");
  myInt = Serial.parseInt();
  Serial.println("Enter a Float: ");
  myFloat = Serial.parseFloat();
  Serial.print("Nice to meet you ");
  Serial.print(myName);
  Serial.print(". Your Integer is ");
  Serial.print(myInt);
  Serial.print(" and your Float is ");
  Serial.print(myFloat);
  Serial.println(" ! ");
}
