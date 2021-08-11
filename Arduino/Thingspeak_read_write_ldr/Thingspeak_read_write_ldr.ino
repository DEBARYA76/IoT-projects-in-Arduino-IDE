#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
const char* ssid = "Codermaker";
const char* password = "babi1pal";
WiFiClient client;
unsigned long myChannelNumber = 1397491;
const char * myWriteAPIKey = "MDG3OGR1VX53M1PL";
const char * myReadAPIKey = "6Z2VMQTYP5TUKY1N";
int led_1;
///int led2 = D3;
int ldr = A0;
int val =0;
//int statusCode;
void setup() {
  Serial.begin(115200);
  delay(10);
//pinMode(led2,OUTPUT);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}
void loop() {
val = analogRead(ldr);
Serial.println(val);
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  
led_1 = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
Serial.println("DATA FROM THINGSPEAK");
Serial.println(led_1);
delay(15000);
/*if(led_1<200)
{
digitalWrite(led2,HIGH);
}
else
{
digitalWrite(led2,LOW);
}
 */
}
