#include <Arduino.h>

void setup() {
  
}

void loop() {
  // create triangle waveform
  for(int value = 0; value < 255; value++)
  {
    dacWrite(25, value);
  }

  for (int value = 255;  value > -1; value--)
  {
    dacWrite(25, value);
  }
}