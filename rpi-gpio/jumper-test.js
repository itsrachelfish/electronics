const Gpio = require('onoff').Gpio;
const left = new Gpio(26, 'out');
const right = new Gpio(20, 'in', 'both');

right.watch((error, value) => {
  if (error) {
    throw error;
  }

  console.log('Got new value -', value);
});

process.on('SIGINT', () => {
  left.unexport();
  right.unexport();
});
