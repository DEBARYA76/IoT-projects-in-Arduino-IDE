#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
const char* ssid = "Codermaker";
const char* password = "babi1pal";
WiFiClient client;

unsigned long myChannelNumber =1387827;
const char * myReadAPIKey ="BJRO60CVB2IMWXPK";
float a,b;

void setup() {
Serial.begin(115200);
WiFi.begin(ssid, password);
ThingSpeak.begin(client);
}
void loop() {
a = ThingSpeak.readFloatField(myChannelNumber,1,myReadAPIKey);
Serial.println("Humidity");
Serial.println(a);
b = ThingSpeak.readFloatField(myChannelNumber,2,myReadAPIKey);
Serial.println("Temparature");
Serial.println(b);
Serial.println("+++++");
delay(100);
}
