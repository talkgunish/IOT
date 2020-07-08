/*
 * Task - 05
 * Alarm sound using Piezo buzzer
 */
int buzzerPin = 8;
unsigned int buzzerFrequency = 700;
unsigned long buzzerDuration = 100;

void setup() {

}

void loop() {
  tone(buzzerPin, buzzerFrequency, buzzerDuration);
  delay(500);
  tone(buzzerPin, buzzerFrequency, buzzerDuration);
  delay(1000);
  noTone(buzzerPin);

}
