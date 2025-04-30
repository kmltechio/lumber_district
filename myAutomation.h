#include "myRoster.h"
#include "myHal.h"

// Startup our track power
AUTOSTART                                     // This sequence auto runs at bootup
SET_TRACK(A, MAIN)                            // Track A is set for DCC
SETLOCO(TROLLEY_LOCO_NUM) SET_TRACK(B, DC)    // Track B set for DC, specifically the trolley
POWERON                                       // Turn on power to both tracks
DONE

// Autostart our fan controller
#define HEAT_ON_VAL  150 // ~95degF based on empirical testing
#define HEAT_OFF_VAL 142 // about room temp
ALIAS(SEQ_FAN_CTL)
SEQUENCE(SEQ_FAN_CTL)
  AUTOSTART
  ATGTE(SENS_HEAT, HEAT_ON_VAL)
  SET(PIN_FAN)
  ATLT(SENS_HEAT, HEAT_OFF_VAL)
  RESET(PIN_FAN)
  FOLLOW(SEQ_FAN_CTL)

// TODO create a macro for turnout/touch/h-bridge control

// Include all remaining routes and automations below
#include "myTrolley.h"
#include "myPassengerLoop.h"
