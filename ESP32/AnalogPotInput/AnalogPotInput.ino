const byte POT_GPIO = 36;

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(POT_GPIO));

}
