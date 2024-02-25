byte sensorPin = A0;
int sensorValue = 0;
int threshold = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  if (sensorValue > threshold) {
    Serial.print("Sensor = ");
    Serial.println(sensorValue, DEC);
  }
  delay(10);
}
