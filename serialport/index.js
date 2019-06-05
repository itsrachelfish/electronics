const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');
const port = new SerialPort('/dev/ttyACM1', { baudRate: 9600 });

const parser = new Readline();
port.pipe(parser);

let clockwise = 0;
let counterClockwise = 0;
let buffer = 0;

parser.on('data', function(movement) {
    buffer += parseInt(movement);

    if(buffer >= 100) {
        clockwise++;
        buffer = 0;
        console.log(`Clockwise: ${clockwise}`);
    }

    if(buffer <= -100) {
        counterClockwise++;
        buffer = 0;
        console.log(`Counter Clockwise: ${counterClockwise}`);
    }
});
