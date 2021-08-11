#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "Codermaker"; //Your Network SSID

const char* password = "babi1pal"; //Your Network Password

int val;
int led2 = D4;
int LDRpin = A0; //LDR Pin Connected at A0 Pin

WiFiClient client;

unsigned long myChannelNumber =1397491; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "MDG3OGR1VX53M1PL"; //Your Write API Key

void setup()

{
Serial.begin(115200);

delay(1000);

// Connect to WiFi network
WiFi.begin(ssid, password);
ThingSpeak.begin(client);

}
void loop()
{

val = analogRead(LDRpin); //Read Analog values and Store in val variable
Serial.println(val); //Print on Serial Monitor
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
if(val<100)
{
digitalWrite(led2,HIGH);

}
else
{
digitalWrite(led2,LOW);

}


delay(100);

}
