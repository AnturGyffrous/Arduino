volatile int state = LOW;
int ledArray[] = {8, 9, 10, 11, 12};
const byte ledPin = 13;
int count = 0;
int timer = 75;
int pause = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  for (count=0;count<5;count++) {
    pinMode(ledArray[count], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2), ledOnOff, RISING);
}

void loop() {
  if (state) {
    for (count=0;count<5;count++) {
      digitalWrite(ledArray[count], HIGH);
      delay(timer);
      if (!state) {
        break;
      }
    }
    delay(pause);
    if (state) {
      for (count=0;count<5;count++) {
        digitalWrite(ledArray[count], LOW);
      }
      delay(pause);
    }
  }
}

void ledOnOff() {
  static unsigned long lastMillis = 0;
  unsigned long newMillis = millis();
  if (newMillis - lastMillis >= 50) {
    state = !state;
    digitalWrite(ledPin, state);
    lastMillis = newMillis;
  }
}