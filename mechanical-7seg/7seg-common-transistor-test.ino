int commonPositive = 11;
int commonNegative = 10;

void setup() {
  pinMode(commonPositive, OUTPUT);
  pinMode(commonNegative, OUTPUT);
}

void loop() {
  // Wait a second before doing anything
  delay(1000);

  // Make the common line positive?
  digitalWrite(commonPositive, HIGH);
  digitalWrite(commonNegative, LOW);
  delay(90);
  digitalWrite(commonPositive, LOW);

  // Wait another second
  delay(1000);

  // Make the common line negative?
  digitalWrite(commonPositive, LOW);
  digitalWrite(commonNegative, HIGH);
  delay(90);
  digitalWrite(commonNegative, LOW);
}
