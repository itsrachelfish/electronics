enum PinAssignments {
    encoderPinA = 2, // White
    encoderPinB = 3, // Green
};

volatile unsigned int encoderPos = 0;
unsigned int lastReportedPos = 1;

boolean A_set = false;
boolean B_set = false;

void setup() {
    pinMode(encoderPinA, INPUT);
    pinMode(encoderPinB, INPUT);
    digitalWrite(encoderPinA, HIGH);  // turn on pull-up resistor
    digitalWrite(encoderPinB, HIGH);  // turn on pull-up resistor

    // encoder pin on interrupt 0 (pin 2)
    attachInterrupt(0, doEncoderA, CHANGE);
    // encoder pin on interrupt 1 (pin 3)
    attachInterrupt(1, doEncoderB, CHANGE);

    Serial.begin(9600);
}


void loop() {
    if (lastReportedPos != encoderPos) {
        Serial.print("Index:");
        Serial.print(encoderPos, DEC);
        Serial.println();
        lastReportedPos = encoderPos;
    }
}

// Interrupt on A changing state
void doEncoderA() {
    // Test transition
    A_set = digitalRead(encoderPinA) == HIGH;
    // and adjust counter + if A leads B
    encoderPos += (A_set != B_set) ? +1 : -1;
}

// Interrupt on B changing state
void doEncoderB() {
    // Test transition
    B_set = digitalRead(encoderPinB) == HIGH;
    // and adjust counter + if B follows A
    encoderPos += (A_set == B_set) ? +1 : -1;
}
