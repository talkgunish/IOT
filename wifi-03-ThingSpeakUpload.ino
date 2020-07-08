/*
 * Wifi-02 
 * Upload LDR sensor data to ThingSpeak
 */
#include<SoftwareSerial.h>

#define SSID "D-Link_DIR-600M"
#define PASSWORD "kuttappan"

int lightSensorPin = A0;
int lightSensorValue = 0;

SoftwareSerial esp8266(2,3);

void setup() {
  Serial.begin(115200);
  esp8266.begin(115200);
  initEsp();
}

void loop() {

  lightSensorValue = analogRead(lightSensorPin);
  Serial.println(lightSensorValue);
  delay(100);

  int length = 42;
  if(lightSensorValue < 10) {
    length ++;
  } else if (lightSensorValue < 100) {
    length += 2;
  } else {
    length += 3;
  }
  
  
  String result;
  esp8266.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80");
  result = recvString("OK",3000);
  printString(result);
  esp8266.print("AT+CIPSEND=");
  esp8266.println(length);
  result = recvString("OK",3000);
  printString(result);
  esp8266.print("GET /update?key=YUNRMJ464OIE6RIE&field1=");
  esp8266.println(lightSensorValue);
  result = recvString("OK",3000);
  printString(result);
}

void initEsp() {
  esp8266.println("AT");
  delay(1000);
  while(esp8266.available())
  {
    char c = esp8266.read();
    Serial.write(c);
  }

  esp8266.println("AT+CWMODE=1");
  delay(1000);
  while(esp8266.available())
  {
    char c = esp8266.read();
    Serial.write(c);
  }

  esp8266.println("AT+CWMODE=1");
  delay(1000);
  String result;
  result = recvString("OK",10000);
  printString(result);

  esp8266.print("AT+CWJAP=\"");
  esp8266.print(SSID);
  //esp8266.print("\",\"");
  //esp8266.print(PASSWORD);
  esp8266.println("\"");
  result = recvString("OK",10000);
  printString(result);
}

void printString(String str)
{
  int l = str.length();
  for(int i=0;i<l;i++)
  {
    Serial.write(str.charAt(i));
  }
}

String recvString(String target, uint32_t timeout)
{
    String data;
    char a;
    unsigned long start = millis();
    while (millis() - start < timeout) {
        while(esp8266.available() > 0) {
            a = esp8266.read();
      if(a == '\0') continue;
            data += a;
        }
        if (data.indexOf(target) != -1) {
            break;
        }   
    }
    return data;
}

