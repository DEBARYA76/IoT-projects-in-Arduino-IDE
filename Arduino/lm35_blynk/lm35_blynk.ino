#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int val;
int tempPin = A0;
char auth[] = "hosEitmcOMgVentoZ17g0jPdGot_tWYX";
char ssid[] = "Codermaker";
char pass[] = "babi1pal";

void setup() {
Serial.begin(115200); 
pinMode(A0,INPUT);
Blynk.begin(auth, ssid, pass);
}

void loop() 
{
Blynk.run();
val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 3300;
  float cel = mv / 10;

  Serial.println(cel);
  {
    Blynk.virtualWrite(V0,cel);
    delay(100);
  }
}
