/*
 * WiFi Task -01
 * AT Communication
 */
#include <SoftwareSerial.h>
 
SoftwareSerial esp8266(2,3); //ESP TX line to pin 2, ESP RX to pin 3

void setup()
{
  Serial.begin(115200);
  esp8266.begin(115200);
}
 
void loop()
{
  if(esp8266.available()) // check if the esp is sending a message 
  {
    while(esp8266.available())
    {
      // The esp has data so display its output to the serial window 
      char c = esp8266.read(); // read the next character.
      Serial.write(c);
    }  
  }

  if(Serial.available())
  {
    delay(1000); 
    String command="";
    
    while(Serial.available()) // read the command character by character
    {
        // read one character
      command+=(char)Serial.read();
    }
    esp8266.println(command); // send the read character to the esp8266
  }
}
 
