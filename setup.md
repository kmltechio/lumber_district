# Prerequisites

1. Unix-like system with GNU make (developed and tested on MacOS)
1. [1Password CLI](https://developer.1password.com/docs/cli/get-started#install) - so that I don't have to commit my home wifi network password
1. [Arduino IDE](https://www.arduino.cc/en/software) - v1.8.x is preferred over 2.0.x as it generates more compact compiled objects.

# Setup

## `make setup`

Run this before doing anything or anytime you want to pull changes from CommandSration-EX. 

1. `git clone` the CommandStation-EX repo
1. `git switch` to the specified branch
1. `make config`

## `make config`

Run this anytime you make changes to your local config/macros.

1. `cp` the local header comfig/marco files into the CommandStation-EX folder

## Compiling

1. Use the Arduino IDE to `verify` then `upload` your changes to your board. 
