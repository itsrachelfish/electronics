int relay = 11;
int middle = 10;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(middle, OUTPUT);
}

void loop() {
  // Wait a second before doing anything
  delay(1000);

  // Erase everything
  digitalWrite(relay, HIGH);
  delay(90);
  digitalWrite(relay, LOW);
  delay(1000);

  // Turn on the center segment
  digitalWrite(middle, HIGH);
  delay(90);
  digitalWrite(middle, LOW);
}
