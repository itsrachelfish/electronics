int controlPin = 12;
int onPin = 11;
int offPin = 10;

void setup() {
  pinMode(controlPin, OUTPUT);
  pinMode(onPin, OUTPUT);
  pinMode(offPin, OUTPUT);
}

void loop() {
  // Wait a second before doing anything
  delay(1000);

  // Turn the segment on
  digitalWrite(controlPin, HIGH);
  digitalWrite(offPin, LOW);
  digitalWrite(onPin, HIGH);
  delay(90);

  // Wait another second
  digitalWrite(controlPin, LOW);
  delay(1000);

  // Turn the segment off
  digitalWrite(controlPin, HIGH);
  digitalWrite(onPin, LOW);
  digitalWrite(offPin, HIGH);
  delay(90);
  digitalWrite(controlPin, LOW);
}
