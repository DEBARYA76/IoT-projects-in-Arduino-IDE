#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include "UbidotsESPMQTT.h"
int val;
int tempPin = A0;
/****************************************
* Define Instances and Constants
****************************************/   
#define TOKEN "BBFF-XJNKbcuknuXnr7vWDdkmVY5EPdJ8Po" // Your Ubidots TOKEN
#define WIFINAME "Codermaker" //Your SSID
#define WIFIPASS "babi1pal" // Your Wifi Pass


Ubidots client(TOKEN);

/****************************************
 * Auxiliar Functions
 ****************************************/

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

/****************************************
 * Main Functions
 ****************************************/

void setup() {

  // put your setup code here, to run once:
  //client.ubidotsSetBroker("industrial.api.ubidots.com"); // Sets the broker properly for the industrial account
  client.setDebug(true); // Pass a true or false bool value to activate debug messages
  Serial.begin(115200);
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
  }

void loop() {
  // put your main code here, to run repeatedly:
  if(!client.connected()){
      client.reconnect();
      }
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 3300;
  float cel = mv / 10;
  //float value1 = analogRead(A0);
  client.add("abcd", cel);
  client.ubidotsPublish("dravida");
  client.loop();
}
