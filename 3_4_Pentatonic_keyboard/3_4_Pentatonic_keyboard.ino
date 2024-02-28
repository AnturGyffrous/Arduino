const int threshold = 200;
const int toneDuration = 40;
const byte speakerPin = 8;

int sensorValue = 0;
int tones[] = {262, 294, 330, 392, 440};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int sensorPin = 0; sensorPin < 5; sensorPin++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > threshold) {
      tone(speakerPin, tones[sensorPin], toneDuration);
    }
  }
}
