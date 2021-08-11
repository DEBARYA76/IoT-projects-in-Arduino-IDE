#include <BlynkSimpleEsp8266.h>
int RED_LED=D1;
char auth[] = "hosEitmcOMgVentoZ17g0jPdGot_tWYX";
char ssid[] = "Codermaker";
char pass[] = "babi1pal";


void setup() {
Serial.begin(115200); 
pinMode(D3,OUTPUT);
Blynk.begin(auth, ssid, pass);
}

void loop() 
{
Blynk.run();
    delay(1000);            
  }

BLYNK_WRITE(V0)

{
  int a=param.asInt();
  if(a==1)
  digitalWrite(RED_LED,1);
  else
  digitalWrite(RED_LED,0);
  
}
