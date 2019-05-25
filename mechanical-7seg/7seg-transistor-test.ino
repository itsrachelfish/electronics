int commonPositive = 13;
int commonNegative = 12;
int middleOn = 11;
int middleOff = 10;


void setup() {
  pinMode(commonPositive, OUTPUT);
  pinMode(commonNegative, OUTPUT);
  pinMode(middleOn, OUTPUT);
  pinMode(middleOff, OUTPUT);
}

void loop() {
  // Wait a second before doing anything
  delay(1000);

  // Turn the segment on
  digitalWrite(commonPositive, HIGH);
  digitalWrite(commonNegative, LOW);

  digitalWrite(middleOn, HIGH);
  digitalWrite(middleOff, LOW);
  delay(90);

  // Wait another second
  digitalWrite(middleOn, LOW);
  delay(1000);

  // Turn the segment off
  digitalWrite(commonPositive, LOW);
  digitalWrite(commonNegative, HIGH);

  digitalWrite(middleOn, LOW);
  digitalWrite(middleOff, HIGH);
  delay(90);

  digitalWrite(middleOff, LOW);
}
