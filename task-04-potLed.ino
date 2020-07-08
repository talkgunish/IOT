/*
 * Taask - 04
 * Potentiometer to control LED brightness
 * 3,5,6,9,10,11
 */
int potPin = 2;    // select the input pin for the potentiometer
int ledPin = 6;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
int mappedVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
}

void loop() {
  val = analogRead(potPin);    // read the value from the potentiometer
  Serial.println(val);  //Print the pot value in Serial monitor / plotter
  mappedVal = ((val*255)/1024);
  analogWrite(ledPin,mappedVal);
}
