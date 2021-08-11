#include <WiFiClient.h>;
#include <ESP8266WiFi.h>;
#include <ThingSpeak.h>;
const char ssid[] = "Codermaker";   // your network SSID (name) 
const char pass[] = "babi1pal";   // your network password
  int val;
  int tempPin=A0;
  
  WiFiClient  client;
unsigned long myChannelNumber = 1381052;
const char * myWriteAPIKey = "WXMICDRT4OZWJ7U3";
 
void setup()
{
  WiFi.begin(ssid,pass); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}
 
void loop()
{
  val=analogRead(tempPin);
  float mV=(val/1024.0)*3300;
  float cel=mV/10;
  
 
// set the fields with the values
 
 Serial.println(cel);
 delay(1000);

 ThingSpeak.setField(1,cel);
 
  
 
 
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  
  
 
}
