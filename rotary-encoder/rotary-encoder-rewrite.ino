enum EncoderPins {
    pinA = 2, // White
    pinB = 3, // Green
};

volatile unsigned int position = 0;

boolean aActive = false;
boolean bActive = false;

boolean clockwise = false;
boolean counterClockwise = false;

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
    if(clockwise || counterClockwise) {
        if(clockwise) {
            Serial.print(1, DEC);
            Serial.println();
        }

        if(counterClockwise) {
            Serial.print(-1, DEC);
            Serial.println();
        }

        clockwise = false;
        counterClockwise = false;
    }
    //
}

void aChanged() {
    if(digitalRead(pinA) == HIGH) {
        aActive = true;

        // If A is active and B is already active, we are moving counter clockwise
        if(aActive && bActive) {
            counterClockwise = true;
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
            clockwise = true;
        }
    } else {
        bActive = false;
    }
}
