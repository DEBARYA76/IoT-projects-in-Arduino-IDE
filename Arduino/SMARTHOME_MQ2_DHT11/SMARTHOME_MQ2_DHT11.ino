#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#include <DHTesp.h>;
#define DHTpin D3
const char* ssid = "Codermaker";
const char* password = "babi1pal";
 DHTesp dht;
WiFiClient client;
unsigned long myChannelNumber = 1390638;
const char * myWriteAPIKey = "88VUS0D23MA6Y5QO";
const char * myReadAPIKey = "MZOTFGG6Q1UDB5MZ";
int mq_val;
int t;
int h;
int hum;               
int tem;

int led = D1;
int mq = A0;
int val =0;
int statusCode;
void setup() {
  Serial.begin(115200);
  dht.setup(DHTpin,DHTesp::DHT11);
  delay(100);
    pinMode(led,OUTPUT);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}
void loop() {
  float h = dht.getHumidity();/* Get humidity value */
float t = dht.getTemperature();/* Get temperature value */
Serial.println(t);
Serial.println(h);
val = analogRead(mq);
Serial.println(val);
ThingSpeak.setField(1, t);
ThingSpeak.setField(2, h);
ThingSpeak.setField(3, val);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

//ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey);
//ThingSpeak.writeField(myChannelNumber, 2,h, myWriteAPIKey);    
//ThingSpeak.writeField(myChannelNumber, 3,val, myWriteAPIKey);
tem = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
hum = ThingSpeak.readIntField(myChannelNumber, 2, myReadAPIKey);
mq_val = ThingSpeak.readIntField(myChannelNumber, 3, myReadAPIKey);

if(mq_val>400 & hum>25 & tem>25)
{
digitalWrite(led,HIGH);
}
else
{
digitalWrite(led,LOW);
}
  delay(15000);
}
