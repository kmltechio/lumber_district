// Always include roster first
#include "myRoster.h"

// Next alias all Mega & IOExpander pins here
// TODO see HAL() to allocate IOEXPANDERS as well
// TODO need actual pin assignments ... these are dummies
ALIAS(SENS_HEAT, 12)
ALIAS(PIN_FAN, 55)
ALIAS(SENS_IR_WEST, 56)
ALIAS(SENS_IR_MID, 57)
ALIAS(SENS_IR_EAST, 58)

// Next startup our tracks/power
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

#include "myTrolley.h"



/*
TODO lower loop automation
Needs at least one IR sensor
Needs to CALL a ROUTE to set turnouts
Use XF*() functions to turn on/off DCC loco sounds
*/
