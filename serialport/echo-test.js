const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

const port = new SerialPort('/dev/ttyACM0', { baudRate: 9600 })
const parser = new Readline();

port.pipe(parser);

parser.on('data', function(line) {
    console.log(line);
});

setTimeout(function() {
    port.write('Hello World\n');
}, 3000);
