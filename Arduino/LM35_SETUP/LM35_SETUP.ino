#include <ESP8266WiFi.h>;

const int sensor=A0; // Assigning analog pin A0 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
void setup()
{
pinMode(sensor,INPUT);
Serial.begin(115200);
}
void loop() 
{
vout=analogRead(sensor);
vout=(vout*3300)/1024;
tempc=vout/10; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
Serial.print("in DegreeC=");
Serial.print("\t");
Serial.print(tempc);
Serial.println();
Serial.print("in Fahrenheit=");
Serial.print("\t");
Serial.print(tempf);
Serial.println();
delay(1000); 
}
