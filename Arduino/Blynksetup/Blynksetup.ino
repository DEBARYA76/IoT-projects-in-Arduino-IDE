#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "hosEitmcOMgVentoZ17g0jPdGot_tWYX";
char ssid[] = "Codermaker";
char pass[] = "babi1pal";


void setup() {
Serial.begin(115200); 
Blynk.begin(auth, ssid, pass);
}

void loop() 
{
Blynk.run();
    delay(10);            
  }
