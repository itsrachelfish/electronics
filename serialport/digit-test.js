const SerialPort = require('serialport');
const port = new SerialPort('/dev/ttyACM0', { baudRate: 9600 })

const digits = [0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39]; // 0 - 9 in ASCII

setTimeout(function() {
    const checksum = digits[4] + digits[4] + digits[0];
    const buffer = Buffer.from([0xAA, 0x56, 0x02, 0x00, 0x00, digits[4], digits[4], digits[0], checksum]);

    port.write(buffer);
}, 3000);
