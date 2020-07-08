/*
 * Wifi-02 
 * Read LDR sensor data from ThingSpeak
 */
#include<SoftwareSerial.h>

#define SSID "D-Link_DIR-600M"
#define PASSWORD "kuttappan"

SoftwareSerial esp8266(2,3);

void setup() {
  Serial.begin(115200);
  esp8266.begin(115200);
  initEsp();
}

void loop() {
 
  
  String result;
  esp8266.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80");
  result = recvString("OK",3000);
  //printString(result);
  esp8266.println("AT+CIPSEND=66");
  result = recvString("OK",3000);
  //printString(result);
  esp8266.println("GET https://api.thingspeak.com/channels/401476/fields/1/last.txt");
  result = recvString("OK",3000);
  //printString(result);
  delay(2000);
  int index = result.indexOf("+IPD");
  Serial.print("------------------------------------Index : ");
  Serial.println(index);
  if(index != -1) {
    String s = result.substring(index+5,index+6);
    int value = s.toInt();
    Serial.print("------------------------------------Converted length value : ");
    Serial.println(value);
    String s2 = result.substring(index+7,index+7+value);
    value = s2.toInt();
    Serial.print("------------------------------------Converted sensor value : ");
    Serial.println(value);
  }
  
  
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
  esp8266.print("\",\"");
  esp8266.print(PASSWORD);
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

