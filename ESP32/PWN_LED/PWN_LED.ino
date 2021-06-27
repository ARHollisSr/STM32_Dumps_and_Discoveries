
const byte LEDGPIO = 33;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  ledcAttachPin(LEDGPIO, 0);

  //initialize channels
  // chan 0-15, res 1-16 bits, freq limits depend on res
  ledcSetup(0, 4000, 8); //12 kHz PWM, 8-bit res
}

void loop() {
  ledcWrite(0, brightness); //set brightness of LED
  brightness += fadeAmount;

  //reverse fade direction at the end of fade
  if(brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
  
}
