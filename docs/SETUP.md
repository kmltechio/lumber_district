# Prerequisites

1. Unix-like system with GNU `make`
1. [1Password
   CLI](https://developer.1password.com/docs/cli/get-started#install) - so that
   we can inject wifi secrets
1. [Arduino CLI](https://docs.arduino.cc/arduino-cli/)
   1. `brew install arduino-cli`
   1. Periodically run `arduino-cli core update-index`
1. (optional) [Arduino IDE](https://www.arduino.cc/en/software) - useful for serial connection IO & debugging

# Setup

1. `git clone https://github.com/kmltechio/lumber_district.git`
1. `make setup` to clone the CommandStation-EX and EX-IOExpander repos
1. `make compile` to build the code while developing
1. Attach your Arduino board to the USB port
1. Run either `make upload_cs_ex` or `make upload_io_ex I2C_ADDRESS=0x65` depending on your need

I2C_ADDRESS should be assigned as follows:
- 0x65 | Touch panel nano
- 0x66 | H-Bridge nano - lower level
- 0x67 | H-Bridge nano - upper level

Note when uploading you may get the following warning, it can safely be ignored
as the upload still succeeds.
```
avrdude: jtagmkII_initialize(): Cannot locate "flash" and "boot" memories in description
```

# Using the Arduino IDE for Debugging

## Connecting the Mega/CommandStation-EX

1. Tools > Board > Arduino AVR Boards > Arduino Mega or Mega 2560
1. Tools > Processor > ATmega 2560 (Mega 2560)
1. Tools > Port > (select the usb port...see below)

## Connecting a Nano Every/EX-IOExpander

1. Tools > Board > Arduino megaAVR Boards > Arduino Nano Every
1. Tools > Registers Emulation > None ATMEGAA4809
1. Tools > Port > (select the usb port...see below)

## Selecting the USB port

The Arduino IDE on MacOS doesn't always pick up the connected board on the USB
port so run this from a shell to see what the proper port is

1. `arduino-cli board list`
