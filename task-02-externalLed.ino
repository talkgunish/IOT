int ledOutputPin = 9;

void setup() {
  pinMode(ledOutputPin,OUTPUT);
}

void loop() {
  digitalWrite(ledOutputPin,HIGH);
  delay(1000);
  digitalWrite(ledOutputPin,LOW);
  delay(1000);
}
