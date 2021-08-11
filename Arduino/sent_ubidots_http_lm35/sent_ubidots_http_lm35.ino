
#include <Ubidots.h>

#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include "Ubidots.h"

/****************************************
* Define Instances and Constants
****************************************/   
 
const char* UBIDOTS_TOKEN = "BBFF-XJNKbcuknuXnr7vWDdkmVY5EPdJ8Po";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Codermaker";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "babi1pal";      // Put here your Wi-Fi password 

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

int val;
int tempPin = A0;
WiFiClient client;

/****************************************
* Auxiliar Functions
****************************************/

// Put here your auxiliar functions

/****************************************
* Main Functions
****************************************/  

void setup() {                       

  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug  messages                     
}

void loop() {
val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 3300;
  float cel = mv / 10;

  Serial.println(cel);
  
  //float value1 = random(0, 9) * 10;
  //float value2 = random(0, 9) * 100;
  //float value3 = random(0, 9) * 1000;
 ubidots.add("abcd", cel);// Change for your variable name  
// client.add("abcd", cel);
//  client.ubidotsPublish("choto");
  //ubidots.add("Variable_Name_Two", value2);
  //ubidots.add("Variable_Name_Three", value3);
  
  bool bufferSent = false;
  bufferSent = ubidots.send(); // Will send data to a device label that matches the device Id

  if (bufferSent) {
  // Do something if values were sent properly
   Serial.println("Values sent by the device");
  }
  delay(5000);
}
