# Prerequisites

1. Unix-like system with GNU `make`
1. [1Password
   CLI](https://developer.1password.com/docs/cli/get-started#install) - so that
   we can inject wifi secrets
1. [Arduino CLI](https://docs.arduino.cc/arduino-cli/)
   1. `brew install arduino-cli`
   1. Periodically run `arduino-cli core update-index`
1. (optional) [Arduino IDE](https://www.arduino.cc/en/software) - useful for serial connection debugging/output

# Setup

1. Clone this repo
1. Run `make setup` to clone the CommandStation-EX and EX-IOExpander repos.
1. Run `make` (or `make compile`) to configure and compile the code.
1. Attach your Arduino board to the USB.
1. Run either `make upload_cs_ex` or `make upload_io_ex` depending on your need.

Note when uploading you may get the following error, it can be ignored; the upload still succeeds
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

Arduino IDE on MacOS doesn't always pick up the usb port so run this from a shell to see what the proper port is

1. Connect the usb cable to the Arduino
1. `ls -la /dev/tty.usb*`
