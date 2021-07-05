#include <Arduino.h>

const byte LED_GPIO = 32;

void setup() {
pinMode(LED_GPIO, OUTPUT);
Serial.begin(115200);
delay(1000);
Serial.println("ESP32 Touch Test");
}

void loop() {
Serial.println(touchRead(T4));

if(touchRead(T4) < 20) 
{
  digitalWrite(LED_GPIO, HIGH);
}
else
{
  digitalWrite(LED_GPIO, LOW);
}

delay(500);
}