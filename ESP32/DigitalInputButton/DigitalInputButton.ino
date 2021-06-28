const byte LEDGPIO = 32;
const byte BUTTONGPIO = 36;

int buttonState = 0;

void setup() {
  pinMode(LEDGPIO, OUTPUT); //initialize digital pin as output
  pinMode(BUTTONGPIO, INPUT); //initialize button as input
}

void loop() {
  buttonState = digitalRead(BUTTONGPIO);

  if(buttonState == HIGH) {
    digitalWrite(LEDGPIO, HIGH);
  } else {
    digitalWrite(LEDGPIO, LOW);
  }
}
