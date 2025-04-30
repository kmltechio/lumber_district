#ifndef MY_HAL_H
#define MY_HAL_H

// Set up our I2C expanders
HAL_IGNORE_DEFAULTS
HAL(EXIOExpander, 800, 18, 0x65) // touch panel nano
// TODO HAL(EXIOExpander, 850, 18, 0x66) // lower h-bridge nano
// TODO HAL(EXIOExpander, 900, 18, 0x67) // upper h-bridge nano
// TODO HAL(DFPlayer, 10000, 10, Serial1)

// Alias all Mega & IOExpander pins here
// see https://dcc-ex.com/reference/hardware/pin-vpin-allocations.html
// Mega Pin Assignements
ALIAS(PIN_FAN, 2)
// reserve : 22 possible use for I2C interrupts
ALIAS(SENS_IR_TROLLEY_WEST, 23)
ALIAS(SENS_IR_TROLLEY_MID, 24)
ALIAS(SENS_IR_TROLLEY_EAST, 25)
ALIAS(SENS_IR_TUNNEL_WEST, 26)
ALIAS(SENS_IR_TUNNEL_EAST, 27)
// ALIAS(SENS_IR_STAGING_WB, 28)
// ALIAS(SENS_IR_STAGING_EB, 29)
// usable : D30-D49
// usable : A8-A15

// Touch Panel Nano Pin Assignments
// unusable : D0 TX
// unusable : D1 RX
ALIAS(TOUCH_2_1, 800) // D2
ALIAS(TOUCH_2_2, 801) // D3
ALIAS(TOUCH_2_3, 802) // D4
ALIAS(TOUCH_2_4, 803) // D5
ALIAS(TOUCH_2_5, 804) // D6
ALIAS(TOUCH_2_6, 805) // D7
ALIAS(TOUCH_2_7, 806) // D8
ALIAS(TOUCH_2_8, 807) // D9
ALIAS(TOUCH_2_9, 808) // D10
// ALIAS(usable, 809) // D11
ALIAS(TOUCH_1_1, 810) // D12
// ALIAS(usable, 811) // D13 may be tied to the onboard LED
ALIAS(TOUCH_1_2, 812) // A0
ALIAS(TOUCH_1_3, 813) // A1
ALIAS(TOUCH_1_4, 814) // A2
ALIAS(TOUCH_1_5, 815) // A3
// unusable : A4 SDA
// unusable : A5 SDA
ALIAS(TOUCH_1_6, 816) // A6
ALIAS(SENS_HEAT, 817) // A7

#endif // MY_HAL_H
