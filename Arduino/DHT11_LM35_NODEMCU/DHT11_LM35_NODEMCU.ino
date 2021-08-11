#include <WiFiClient.h>;
#include <ESP8266WiFi.h>;
#include <ThingSpeak.h>;
#include <DHTesp.h>;
#include <stdlib.h>;

 
#define DHTpin D3
const char ssid[] = "Codermaker";   // your network SSID (name) 
const char pass[] = "babi1pal";   // your network password
  int val;
  int tempPin=A0;
  DHTesp dht;
  WiFiClient  client;
unsigned long myChannelNumber =1390638;
const char * myWriteAPIKey = "88VUS0D23MA6Y5QO";
 
void setup()
{
  Serial.begin(115200);
  dht.setup(DHTpin,DHTesp::DHT11);
  WiFi.begin(ssid,pass); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}
 
void loop()
{
  val=analogRead(tempPin);
  float mV=(val/1024.0)*3300;
  float cel=mV/10;
  
  float h = dht.getHumidity();
  float t = dht.getTemperature();
 
// set the fields with the values
 
 Serial.println(cel);
 delay(1000);
 Serial.println(h);
 Serial.println(t);
 ThingSpeak.setField(1,cel);
  ThingSpeak.setField(2, h);
  ThingSpeak.setField(3, t);
  
 
 
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  
  delay(20000); // Wait 20 seconds to update the channel again
 
}
