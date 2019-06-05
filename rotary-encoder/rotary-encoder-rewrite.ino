enum EncoderPins {
    pinA = 2, // White
    pinB = 3, // Green
};

volatile unsigned int position = 0;
unsigned int lastPosition = 1;

boolean aActive = false;
boolean bActive = false;

void setup() {
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    digitalWrite(pinA, HIGH);  // turn on pull-up resistor
    digitalWrite(pinB, HIGH);  // turn on pull-up resistor

    attachInterrupt(0, aChanged, CHANGE);
    attachInterrupt(1, bChanged, CHANGE);

    Serial.begin(9600);
}


void loop() {
    if(lastPosition != position) {
        Serial.print(position, DEC);
        Serial.println();
        lastPosition = position;
    }
}

void aChanged() {
    if(digitalRead(pinA) == HIGH) {
        aActive = true;

        // If A is active and B is already active, we are moving counter clockwise
        if(aActive && bActive) {
            position--;
        }
    } else {
        aActive = false;
    }
}

void bChanged() {
    if(digitalRead(pinB) == HIGH) {
        bActive = true;

        // If B is active and A is already active, we are moving clockwise
        if(aActive && bActive) {
            position++;
        }
    } else {
        bActive = false;
    }
}
