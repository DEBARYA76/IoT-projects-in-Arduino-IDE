#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <Servo.h>

char auth[] = "VMxWkaMAVaKkDvZQ_S8hAE_s1suoji8_";
char ssid[] = "Codermaker";
char pass[] = "babi1pal";

Servo servo;

BLYNK_WRITE(V3) {

servo.write(param.asInt());

}

void setup() {

Serial.begin(115200);

Blynk.begin(auth, ssid, pass);

servo.attach(2); // 15 means D8 pin of ESP8266

}

void loop()

{

Blynk.run(); // You can inject your own code or combine it with other sketches.

}
