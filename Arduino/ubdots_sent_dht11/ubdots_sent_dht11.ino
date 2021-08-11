#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include "Ubidots.h"

/****************************************
* Define Instances and Constants
****************************************/   
 
const char* UBIDOTS_TOKEN = "BBFF-XJNKbcuknuXnr7vWDdkmVY5EPdJ8Po";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Codermaker";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "babi1pal";      // Put here your Wi-Fi password 
#include <DHT.h>;

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);
DHT dht;
//int val;
//int tempPin = A0;
WiFiClient client;

/****************************************
* Auxiliar Functions
****************************************/

// Put here your auxiliar functions

/****************************************
* Main Functions
****************************************/  

void setup() {                       
   dht.setup(D3);
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug  messages                     
}

void loop() {
//val = analogRead(tempPin);
  //float mv = ( val / 1024.0) * 3300;
  //float cel = mv / 10;
float h = dht.getHumidity();/* Get humidity value */
float t = dht.getTemperature();/* Get temperature value */
Serial.println(t);
Serial.println(h);
  //Serial.println(cel);
  
  
  ubidots.add("xyz", h);// Change for your variable name  
  ubidots.add("abc", t);// Change for your variable name 
  
  
  bool bufferSent = false;
  bufferSent = ubidots.send(); // Will send data to a device label that matches the device Id

  if (bufferSent) {
  // Do something if values were sent properly
   Serial.println("Values sent by the device");
  }
  delay(5000);
}
