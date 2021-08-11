#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
const char* ssid = "Codermaker"; //Your Network SSID
const char* password = "babi1pal"; //Your Network Password
WiFiClient client;
unsigned long myChannelNumber = 1397491;
const char * myWriteAPIKey = "MDG3OGR1VX53M1PL";
const char * myReadAPIKey = "6Z2VMQTYP5TUKY1N";
int led_1;
int led1 = D1;
int led2 = D3;
int ldr = A0;
int val =0;
int statusCode;
void setup() {
  Serial.begin(115200);
  //delay(10);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}
void loop() {
  
  val = analogRead(ldr);
  //Serial.println(val);

if(val<200)
{
digitalWrite(led1,HIGH);
}
else
{
digitalWrite(led1, LOW);
}
    ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
    
  
  

  
  

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
  delay(15000);
}
