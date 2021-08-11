#include <WiFiClient.h>;
#include <ESP8266WiFi.h>;
#include <ThingSpeak.h>;
#include <DHTesp.h>;
#include <stdlib.h>;

 
#define DHTpin D3
const char ssid[] = "Codermaker";   // your network SSID (name) 
const char pass[] = "babi1pal";   // your network password
  
  DHTesp dht;
  WiFiClient  client;
unsigned long myChannelNumber =1387827;
const char * myWriteAPIKey = "2QVR2FRX38758GN3";
 
void setup()
{
  Serial.begin(115200);
  dht.setup(DHTpin,DHTesp::DHT11);
  WiFi.begin(ssid,pass); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}
 
void loop()
{
 
  float h = dht.getHumidity();
  float t = dht.getTemperature();
 
// set the fields with the values
 
 
 Serial.println(h);
 Serial.println(t);
 
  ThingSpeak.setField(1, h);
  ThingSpeak.setField(2, t);
  
 
 
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  
  delay(20000); // Wait 20 seconds to update the channel again
 
}
