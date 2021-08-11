
//Blynk Alert system
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "Y_P-lXHC2AaU_a8qKX1Gx8wHSZN-axPp"; //Auth code sent via Email
char ssid[] = "Codermaker"; //Wifi name
char pass[] = "babi1pal";  //Wifi Password
int flag=0;
void notifyOnThings()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("FIRE ALERT");
    Blynk.notify("Alert : FIRE ALERT");
    flag=1;
  }
  else if (isButtonPressed==0)
  { 
    flag=0;
  }
}
void setup()
{
Serial.begin(11500);
Blynk.begin(auth, ssid, pass); 
pinMode(D1,INPUT_PULLUP);
timer.setInterval(1000L,notifyOnThings); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
