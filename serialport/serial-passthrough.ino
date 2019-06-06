#include <SoftwareSerial.h>

SoftwareSerial displaySerial(2, 3); // RX, TX
int incomingByte = 0x00;

void setup() {
    Serial.begin(9600);
    displaySerial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        incomingByte = Serial.read();
        displaySerial.write(incomingByte);
    }
}
