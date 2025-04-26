// Always include roster first
#include "myRoster.h"

// Set up our I2C expanders
HAL(EXIOExpander, 800, 18, 0x65) // touch panel nano
// TODO add more here

// Alias all Mega & IOExpander pins here
// see https://dcc-ex.com/reference/hardware/pin-vpin-allocations.html
ALIAS(SENS_HEAT, A8)
// Reserve 22 for possible I2C interrupts
ALIAS(PIN_FAN, 23)
ALIAS(SENS_IR_TROLLEY_WEST, 24)
ALIAS(SENS_IR_TROLLEY_MID, 25)
ALIAS(SENS_IR_TROLLEY_EAST, 26)
ALIAS(SENS_IR_TUNNEL_WEST, 27)
ALIAS(SENS_IR_TUNNEL_EAST, 28)
// Reserve these next two
// ALIAS(SENS_IR_STAGING_WB, 29)
// ALIAS(SENS_IR_STAGING_EB, 30)

// Startup our track power
AUTOSTART                                     // This sequence auto runs at bootup
SET_TRACK(A, MAIN)                            // Track A is set for DCC
SETLOCO(TROLLEY_LOCO_NUM) SET_TRACK(B, DC)    // Track B set for DC, specifically the trolley
POWERON                                       // Turn on power to both tracks
DONE

// Autostart our fan controller
#define HEAT_ON_VAL 95  // TODO need real value via experimenation
#define HEAT_OFF_VAL 85 // TODO need real value via experimenation
ALIAS(SEQ_FAN_CTL)
SEQUENCE(SEQ_FAN_CTL)
  AUTOSTART
  ATGTE(SENS_HEAT, HEAT_ON_VAL)
  SET(PIN_FAN)
  ATLT(SENS_HEAT, HEAT_OFF_VAL)
  RESET(PIN_FAN)
  FOLLOW(SEQ_FAN_CTL)

// Include all remaining routes and automations below
#include "myTrolley.h"
#include "myPassengerLoop.h"
