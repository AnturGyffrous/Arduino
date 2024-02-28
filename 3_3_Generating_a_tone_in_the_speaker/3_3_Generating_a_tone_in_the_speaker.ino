const byte sensorPin = A0;
int sensorValue = 0;
const int threshold = 200;
const int toneDuration = 40;
const int toneFrequency = 262;
const byte speakerPin = 8;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  if (sensorValue > threshold) {
    tone(speakerPin, toneFrequency, toneDuration);
  }
}
