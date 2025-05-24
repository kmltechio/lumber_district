// this ordering is important
#include "myPins.h"
#include "myTurnouts.h"
#include "myRoster.h"

#include "myPassengerLoop.h"
#include "myTrolley.h"

// Setup our track power but don't start it...do that from the controller app
AUTOSTART                                     // This sequence auto runs at bootup
SET_TRACK(A, MAIN)                            // Track A is set for DCC
SETLOCO(TROLLEY_LOCO_NUM) SET_TRACK(B, DC)    // Track B set for DC, specifically the trolley
DONE

// Autostart the fan controller
#define HEAT_ON_VAL  165 // ~95degF based on empirical testing
#define HEAT_OFF_VAL 155 // about room temp
ALIAS(SEQ_FAN_CTL)
SEQUENCE(SEQ_FAN_CTL)
  AUTOSTART
  ATGTE(SENS_HEAT, HEAT_ON_VAL)   SET(PIN_FAN)
  ATLT(SENS_HEAT, HEAT_OFF_VAL) RESET(PIN_FAN)
  FOLLOW(SEQ_FAN_CTL)
DONE
