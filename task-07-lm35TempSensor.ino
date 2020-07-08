/*
 * Task -07
 * Read LM35 Temperature sensor
 */

int tempSensorPin = A1;
int tempSensorValue = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  tempSensorValue = analogRead(tempSensorPin);
  float mv = (tempSensorValue/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  Serial.print("Temperature : ");
  Serial.print(cel);
  Serial.print(" degree celsius");
  Serial.print(farh);
  Serial.print(" degree farenheit");
  Serial.println();
  delay(1000); 
}
