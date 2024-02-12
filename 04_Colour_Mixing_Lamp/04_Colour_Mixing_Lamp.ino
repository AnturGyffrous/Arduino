const byte redLedPin = 9;
const byte greenLedPin = 11;
const byte blueLedPin = 10;

const byte redSesnsorPin = A0;
const byte greenSesnsorPin = A1;
const byte blueSesnsorPin = A2;

byte redValue = 0;
byte greenValue = 0;
byte blueValue = 0;

byte redSensorValue = 0;
byte greenSensorValue = 0;
byte blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSesnsorPin);
  delay(5);
  greenSensorValue = analogRead(greenSesnsorPin);
  delay(5);
  blueSensorValue = analogRead(blueSesnsorPin);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  analogWrite(redLedPin, redValue);
  analogWrite(greenLedPin, greenValue);
  analogWrite(blueLedPin, blueValue);
}
