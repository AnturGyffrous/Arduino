int ledArray[] = {8, 9, 10, 11, 12};
int count = 0;
int timer = 75;

void setup() {
  for (count=0;count<5;count++) {
    pinMode(ledArray[count], OUTPUT);
  }

}

void loop() {
  for (count=0;count<5;count++) {
    digitalWrite(ledArray[count], HIGH);
    delay(timer);
    digitalWrite(ledArray[count], LOW);
    delay(timer);
  }

}
