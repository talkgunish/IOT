/*
 * Task -06
 * Read LDR light sensor
 */

int lightSensorPin = A7;
int lightSensorValue = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  lightSensorValue = analogRead(lightSensorPin);
  Serial.println(lightSensorValue);
  delay(100);
}
