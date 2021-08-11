#include <WiFiClient.h>;
#include <ESP8266WiFi.h>;

#include <DHTesp.h>;
#include <stdlib.h>;

 
#define DHTpin D3
  
  DHTesp dht;
  WiFiClient  client;

void setup()
{
  Serial.begin(115200);
  dht.setup(DHTpin,DHTesp::DHT11);
 
}
 
void loop()
{
  
  float h = dht.getHumidity();
  float t = dht.getTemperature();
 
// set the fields with the values
 
 
 delay(1000);
 Serial.println(h);
 Serial.println(t);


  delay(20000); // Wait 20 seconds to update the channel again
 
}
