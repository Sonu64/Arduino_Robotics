// Reading quantized digital Voltage Levels from Analog Input from Potentiometer.
/* Arduino UNO R3 uses 10-bit Analog to Digital Convertor (ADC), so 2^10 quantizations of the analog signal is possible. 
Higher the bits, more is the quantization accuracy.**/
// Use ADC Pins to read Analog Inputs always.
const int potPin = 5;
int voltage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop() {
  voltage = analogRead(potPin);
  Serial.println(voltage);
  delay(500);
}