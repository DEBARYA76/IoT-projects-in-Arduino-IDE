#include "UbidotsESPMQTT.h"
/****************************************
 * Define Constants
 ****************************************/
#define TOKEN "BBFF-gVi9xeeTWYvrrswzoRxfLU5Aat1Zyd" // Your Ubidots TOKEN
#define WIFINAME "Codermaker" //Your SSID
#define WIFIPASS "babi1pal" // Your Wifi Pass
#define DEVICE_LABEL "dravida" // Put here your Ubidots device label
#define VARIABLE_LABEL "abcd" // Put here your Ubidots variable label 
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
 client.ubidotsSetBroker("industrial.api.ubidots.com"); // Sets the broker properly for
 client.setDebug(false); // Pass a true or false bool value to activate debug messages
 Serial.begin(115200);
 client.wifiConnection(WIFINAME, WIFIPASS);
 client.begin(callback);
 client.ubidotsSubscribe(DEVICE_LABEL, VARIABLE_LABEL); //Insert the dataSource and Var
 }
void loop() {
 // put your main code here, to run repeatedly:
 if(!client.connected()){
 client.reconnect();
  //Insert the dataSource and
 }client.ubidotsSubscribe(DEVICE_LABEL, VARIABLE_LABEL);
 client.loop();
 }
