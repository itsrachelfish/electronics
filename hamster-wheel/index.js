const SerialPort = require('serialport');
const encoder = new SerialPort('/dev/ttyACM0', { baudRate: 115200 });
const display = new SerialPort('/dev/ttyACM1', { baudRate: 9600 });

const Readline = require('@serialport/parser-readline');
const parser = new Readline();

const asciiDigits = [0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39]; // 0 - 9 in ASCII
let clockwise = 0;
let counterClockwise = 0;
let buffer = 0;

encoder.pipe(parser);

parser.on('data', function(movement) {
    buffer += parseInt(movement);

    if(buffer >= 100) {
        clockwise++;
        buffer = 0;
        console.log(`Clockwise: ${clockwise}`);
        updateDisplay(clockwise);
    }

    if(buffer <= -100) {
        counterClockwise++;
        buffer = 0;
        console.log(`Counter Clockwise: ${counterClockwise}`);
    }
});

function updateDisplay(score) {
    // Left pad score with zeroes
    score = ("00"+score).slice(-3);

    // Split score into an array of digits
    digits = String(score).split('').reverse();

    // Required header data for the AlfaZeta RS-485 control protocol
    const data = [0xAA, 0x56, 0x02, 0x00, 0x00];
    let checksum = 0;

    digits.forEach(function(digit) {
        data.push(asciiDigits[digit]);
        checksum += asciiDigits[digit];
    });

    checksum = checksum % 0x100;
    data.push(checksum);

    display.write(Buffer.from(data));
}
