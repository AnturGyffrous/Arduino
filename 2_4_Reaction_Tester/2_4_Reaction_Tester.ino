volatile byte state = 0;
byte ledArray[] = {8, 9, 10, 11, 12};
byte count = 0;
int timer = 150;
const byte stopLed = 6;
const byte goLed = 7;
const int randMin = 250;
const int randMax = 750;
int startDelay;

void setup() {
  for (count=0;count<5;count++) {
    pinMode(ledArray[count], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2), buttonPress, RISING);
  pinMode(stopLed, OUTPUT);
  pinMode(goLed, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  if (state == 0) {
    digitalWrite(stopLed, HIGH);
    digitalWrite(goLed, LOW);
    for (count=0;count<5;count++) {
      digitalWrite(ledArray[count], LOW);
    }
  }
  if (state == 1) {
    digitalWrite(stopLed, LOW);
    startDelay = random(randMin, randMax);
    delay(startDelay);
    digitalWrite(goLed, HIGH);
    for (count=0;count<5;count++) {
      digitalWrite(ledArray[count], HIGH);
      delay(timer);
      if (state == 2) {
        break;
      }
    }
  }
}

void buttonPress() {
  state++;
  if (state > 2) {
    state = 0;
  }
}
