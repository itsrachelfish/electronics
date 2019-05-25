// First relay control board
int commonPositive = 13;
int commonNegative = 12;

int middlePositive = 11; // g
int middleNegative = 10;

int topPositive = 9; // a
int topNegative = 8;

int topRightPositive = 7; // b
int topRightNegative = 6;

// Second relay control board
int bottomRightPositive = 14; // c
int bottomRightNegative = 15;

int bottomPositive = 5; // d
int bottomNegative = 4;

int bottomLeftPositive = 3; // e
int bottomLeftNegative = 2;

int topLeftPositive = 1; // f
int topLeftNegative = 0;

void setup() {
  // TODO: I feel like there's a better way to define this?
  pinMode(commonPositive, OUTPUT);
  pinMode(commonNegative, OUTPUT);
  pinMode(middlePositive, OUTPUT);
  pinMode(middleNegative, OUTPUT);
  pinMode(topPositive, OUTPUT);
  pinMode(topNegative, OUTPUT);
  pinMode(topRightPositive, OUTPUT);
  pinMode(topRightNegative, OUTPUT);
  pinMode(bottomRightPositive, OUTPUT);
  pinMode(bottomRightNegative, OUTPUT);
  pinMode(bottomPositive, OUTPUT);
  pinMode(bottomNegative, OUTPUT);
  pinMode(bottomLeftPositive, OUTPUT);
  pinMode(bottomLeftNegative, OUTPUT);
  pinMode(topLeftPositive, OUTPUT);
  pinMode(topLeftNegative, OUTPUT);
}


void test(int pin) {
  digitalWrite(pin, HIGH);
  delay(90);
  digitalWrite(pin, LOW);
  delay(90);
}

void on(int positivePin) {
  digitalWrite(commonNegative, HIGH);
  delay(90);
  digitalWrite(positivePin, HIGH);
  delay(90);
  digitalWrite(positivePin, LOW);
  delay(90);
  digitalWrite(commonNegative, LOW);
  delay(90);
}

void off(int negativePin) {
  digitalWrite(negativePin, HIGH);
  delay(90);
  digitalWrite(commonPositive, HIGH);
  delay(90);
  digitalWrite(commonPositive, LOW);
  delay(90);
  digitalWrite(negativePin, LOW);
  delay(90);
}

void allOff() {
  off(commonNegative);
  off(middleNegative);
  off(topNegative);
  off(topRightNegative);
  off(bottomRightNegative);
  off(bottomNegative);
  off(bottomLeftNegative);
  off(topLeftNegative);
}

void noInduct() {
  digitalWrite(commonNegative, HIGH);
  delay(30);
  digitalWrite(middleNegative, HIGH);
  digitalWrite(topNegative, HIGH);
  digitalWrite(topRightNegative, HIGH);
  digitalWrite(bottomRightNegative, HIGH);
  digitalWrite(bottomNegative, HIGH);
  digitalWrite(bottomLeftNegative, HIGH);
  digitalWrite(topLeftNegative, HIGH);
  digitalWrite(middlePositive, HIGH);
  digitalWrite(topPositive, HIGH);
  digitalWrite(topRightPositive, HIGH);
  digitalWrite(bottomRightPositive, HIGH);
  digitalWrite(bottomPositive, HIGH);
  digitalWrite(bottomLeftPositive, HIGH);
  digitalWrite(topLeftPositive, HIGH);
  delay(90);
  digitalWrite(middleNegative, LOW);
  digitalWrite(topNegative, LOW);
  digitalWrite(topRightNegative, LOW);
  digitalWrite(bottomRightNegative, LOW);
  digitalWrite(bottomNegative, LOW);
  digitalWrite(bottomLeftNegative, LOW);
  digitalWrite(topLeftNegative, LOW);
  digitalWrite(middlePositive, LOW);
  digitalWrite(topPositive, LOW);
  digitalWrite(topRightPositive, LOW);
  digitalWrite(bottomRightPositive, LOW);
  digitalWrite(bottomPositive, LOW);
  digitalWrite(bottomLeftPositive, LOW);
  digitalWrite(topLeftPositive, LOW);
  delay(90);
  digitalWrite(commonNegative, LOW);
  delay(30);
}


void loop() {
  // Wait a few seconds before doing anything
  test(commonNegative);
  test(commonNegative);
  test(commonNegative);
  delay(3000);
  test(commonNegative);
  test(commonNegative);
  test(commonNegative);
  delay(3000);

  // Erase everything
  allOff();

  // L
  on(topLeftPositive);
  on(bottomLeftPositive);
  on(bottomPositive);

  delay(1000);
  allOff();

  // O
  on(topPositive);
  on(topRightPositive);
  on(bottomRightPositive);
  on(bottomPositive);
  on(bottomLeftPositive);
  on(topLeftPositive);

  delay(1000);
  allOff();

  // L
  on(topLeftPositive);
  on(bottomLeftPositive);
  on(bottomPositive);
  delay(1000);
}


/*

  // L
  on(topLeftPositive);
  on(bottomLeftPositive);
  on(bottomPositive);

  delay(1000);
  allOff();

  // O
  on(topPositive);
  on(topRightPositive);
  on(bottomRightPositive);
  on(bottomPositive);
  on(bottomLeftPositive);
  on(topLeftPositive);

  delay(1000);
  allOff();

  // L
  on(topLeftPositive);
  on(bottomLeftPositive);
  on(bottomPositive);
}


/*
test(commonPositive);
test(commonNegative);
test(middlePositive);
test(middleNegative);
test(topPositive);
test(topNegative);
test(topRightPositive);
test(topRightNegative);
test(bottomRightPositive);
test(bottomRightNegative);
test(bottomPositive);
test(bottomNegative);
test(bottomLeftPositive);
test(bottomLeftNegative);
test(topLeftPositive);
test(topLeftNegative);
*/
