volatile byte state = 0;
byte ledArray[] = {8, 9, 10, 11, 12};
byte ledCount = 0;
int timer = 15;
const byte stopLed = 6;
const byte goLed = 7;
const int randMin = 250;
const int randMax = 750;
int startDelay;
volatile float time;
float start_time;
byte delayCount = 0;

void setup() {
  for (ledCount=0;ledCount<5;ledCount++) {
    pinMode(ledArray[ledCount], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2), buttonPress, RISING);
  pinMode(stopLed, OUTPUT);
  pinMode(goLed, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  if (state == 0) {
    digitalWrite(stopLed, HIGH);
    digitalWrite(goLed, LOW);
    for (ledCount=0;ledCount<5;ledCount++) {
      digitalWrite(ledArray[ledCount], LOW);
    }
  }
  if (state == 1) {
    digitalWrite(stopLed, LOW);
    startDelay = random(randMin, randMax);
    delay(startDelay);
    start_time = millis();
    digitalWrite(goLed, HIGH);
    state = 1;
    for (ledCount=0;ledCount<5;ledCount++) {
      digitalWrite(ledArray[ledCount], HIGH);
      for (delayCount=0;delayCount<10;delayCount++) {
        delay(timer);
        if (state == 2) {
          break;
        }
      }
      if (state == 2) {
        float reactionTime = (time - start_time)/1000;
        Serial.print("Reaction time: ");
        Serial.print(reactionTime);
        Serial.println(" seconds");
        delay(1000);
        state = 2;
        break;
      }
    }
    if (ledCount == 5) {
        Serial.println("Reaction time: FAIL!");
        delay(1000);
        state = 2;
    }
  }
}

void buttonPress() {
  static unsigned long lastMillis = 0;
  unsigned long newMillis = millis();
  Serial.print("lastMillis: ");
  Serial.print(lastMillis);
  Serial.print("; newMillis: ");
  Serial.print(newMillis);
  Serial.print("; newMillis - lastMillis: ");
  Serial.print(newMillis - lastMillis);
  if (newMillis - lastMillis >= 50) {
    state++;
    if (state == 2) {
      time = millis();
    }
    if (state == 3) {
      state = 0;
    }
    lastMillis = newMillis;
  }
  Serial.print("; state: ");
  Serial.println(state);
}
