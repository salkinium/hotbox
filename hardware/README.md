# Box Controller Hardware

## Controller PCB

The controller is build around a ATmega328p on a PCB which contains:

- a UART PSK plug for communication,
- a reset button,
- 4 PSK plugs for I2C bus with pull-ups,
- a ISP programming header,
- 4 mounting holes,
- a ATX 24-pin connector for 3.3V, 5V, PowerOn, 
- a ATX 4-pin connector for 12V,
- 1 external crystal (14.7456 MHz),
- 2 white LEDs, 1 RGB LED all connected to the ATmegas Timer Outputs,
- 1 TMP175 temperature sensor on the I2C bus,
- 4 MOSFETs (BUZ11) with snubber diodes, and
- several 0603 resistors and capacitors.

The PCB is designed to be one-sided so it can be cheaply produced or easily PCB-milled.
However, the ISP reset line has to be connected using wire, since it simply did not fit on one side anymore.

## Mote harness

This is a mote harness for the MTM-CM5000-MSP TelosB mote.
The motes battery pack must be unsolderes, otherwise it won't fit.

The harness rotates the mote around the PCB antenna in 5° steps, so the distance between two rotated motes does not change.
The harness can be clamped onto a distance bar, which allows moving the harness in 5mm steps.

## Box Baseboard

The baseboard is simply a lasercut 5mm thick piece of wood, which holds the controller PCB, the heater, the circulation fan and a disperser using M3 screws.

The heater is a 150W element, and the fan a standard 12V PC fan.