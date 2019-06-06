byte digits [] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39 }; // 0 - 9 in ASCII


void sendNumber(int number) {
    int checksum = digits[number] + digits[0] + digits[0];

    Serial.write(0xAA); // Start of message
    Serial.write(0x56); // ASCII mode
    Serial.write(0x02); // Number of digits - 1
    Serial.write(0x00); // Offset of first character being displayed
    Serial.write(0x00); // Address of display being updated, 0x00 means update all... not entirely sure how this differs from the offset...
    Serial.write(digits[number]);
    Serial.write(digits[0]);
    Serial.write(digits[0]);
    Serial.write(checksum);
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    int x;

    for(x=0; x<10; x++) {
        sendNumber(x);
        delay(1000);
    }
}
