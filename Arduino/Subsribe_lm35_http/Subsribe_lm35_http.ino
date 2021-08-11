
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
  // ubidots.setDebug(true); //Uncomment this line for printing debug messages
}

void loop() {
  /* Obtain last value from a variable as float using HTTP */
  float value = ubidots.get("e8db84c553d4", "abcd");

  // Evaluates the results obtained
  if (value != ERROR_VALUE) {
    Serial.print("Value:");
    Serial.println(value);
  }
  delay(5000);
}
