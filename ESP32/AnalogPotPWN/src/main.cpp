#include <Arduino.h>

const byte POT_GPIO = 36;
const byte LED_GPIO = 32; 
int brightness = 0;
int fadeAmount = 5;

void setup() {
  ledcAttachPin(LED_GPIO, 0);
  ledcSetup(0, 4000, 12); 
}

void loop() {
  ledcWrite(0, analogRead(POT_GPIO));
}