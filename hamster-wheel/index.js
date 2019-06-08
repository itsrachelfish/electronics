//const data = require('./savefile');
const SerialPort = require('serialport');
const encoder = new SerialPort('/dev/ttyACM0', { baudRate: 115200 });
const display1 = new SerialPort('/dev/ttyACM1', { baudRate: 9600 });
const display2 = new SerialPort('/dev/ttyACM2', { baudRate: 9600 });

const Readline = require('@serialport/parser-readline');
const parser = new Readline();

const asciiDigits = [0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39]; // 0 - 9 in ASCII
let clockwise = 88;
let counterClockwise = 88;
let buffer = 0;

encoder.pipe(parser);

parser.on('data', function(movement) {
    buffer += parseInt(movement);
    let date = new Date();

    if(buffer >= 3646) {
        clockwise++;
        buffer = 0;
        console.log(`${date} - Clockwise: ${clockwise}`);
        updateDisplay(display1, clockwise);
    }

    if(buffer <= -3646) {
        counterClockwise++;
        buffer = 0;
        console.log(`${date} - Counter Clockwise: ${counterClockwise}`);
        updateDisplay(display2, counterClockwise);
    }
});

function updateDisplay(display, score) {
    // Left pad score with zeroes
    score = ("000"+score).slice(-4);

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
