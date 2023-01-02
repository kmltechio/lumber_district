# Prerequisites

1. Unix-like system with GNU make (developed and tested on MacOS)
1. [1Password
   CLI](https://developer.1password.com/docs/cli/get-started#install) - so that
   I don't have to commit my home wifi network password
1. [Arduino IDE](https://www.arduino.cc/en/software) - v1.8.x is preferred over
   2.0.x as it generates more compact compiled objects.

# Setup

## `make update_cs_ex`

Run this before doing anything or anytime you want to pull changes from
CommandSration-EX. 

1. Edit `Makefile` setting the `BRANCH` variable setting the branch of
   CommandStation-EX that you want to build
1. Run `make update_cs_ex` to do the following
1. `git clone` the CommandStation-EX repo
1. `git switch` to the specified branch

## `make config`

Run this anytime you make changes to your local config/macros. This will

1. `cp` the local header comfig/marco files into the CommandStation-EX folder

Since some of the files contain 1Password secrets that get replaced you will
have to log in to `op`.  To prevent having to do this every time you run make
you can run `eval $(op signon)` from your shell. This will keep you logged in
for 30 minutes. 

# Compilation

Use the Arduino IDE for these steps.

1. Run `make setup` if needed
1. Press the `verify` button
1. Ensure your board is connected (typically via USB on COM3)
1. Press the `upload` button
