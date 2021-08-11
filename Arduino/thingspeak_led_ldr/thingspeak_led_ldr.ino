#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
const char* ssid = "Codermaker";
const char* password = "babi1pal";
WiFiClient client;
unsigned long myChannelNumber =  1397491;

const char * myReadAPIKey = "6Z2VMQTYP5TUKY1N";
int led_1;
int led2 = D3;


int statusCode;
void setup() {
  Serial.begin(115200);
  pinMode(led2,OUTPUT);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}
void loop() {
  
 
 led_1 = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
Serial.println(led_1);
if(led_1<200)
{
digitalWrite(led2,HIGH);
}
else
{
digitalWrite(led2,LOW);
}
  delay(1000);
}
