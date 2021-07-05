#include <Arduino.h>

volatile byte LED_GPIO = 32; //marked volatile in order to be read by ISR
bool led_state = false;
const byte interruptPin = 25;
volatile int interruptCounter = 0;
int numberOfInterrupts = 0;
long debouncing_time = 1000; // in milli seconds
volatile unsigned long last_micros;

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR handleInterrupt() {
  portENTER_CRITICAL_ISR(&mux);
  if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    interruptCounter++;
  }

  last_micros = micros();
  portEXIT_CRITICAL_ISR(&mux);
}
void setup() {
  Serial.begin(115200);
  pinMode(LED_GPIO, OUTPUT);
  Serial.println("Monitoring Interrupts:  ");
  pinMode(interruptPin, INPUT_PULLUP); //using external pull up instead of internal
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);
}

void loop() {
  if(interruptCounter > 0)
  {
    portENTER_CRITICAL(&mux);
    interruptCounter--;
    portEXIT_CRITICAL(&mux);

    led_state = !led_state;

    digitalWrite(LED_GPIO, led_state);
    numberOfInterrupts++;
    Serial.print("An interrupt has occured. Total:");
    Serial.println(numberOfInterrupts);
  }
}