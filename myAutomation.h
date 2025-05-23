#include "myRoster.h"
#include "myPins.h"

// Setup our track power but don't start it...do that from the controller app
AUTOSTART                                     // This sequence auto runs at bootup
SET_TRACK(A, MAIN)                            // Track A is set for DCC
SETLOCO(TROLLEY_LOCO_NUM) SET_TRACK(B, DC)    // Track B set for DC, specifically the trolley
DONE


// Autostart our fan controller
#define HEAT_ON_VAL  165 // ~95degF based on empirical testing
#define HEAT_OFF_VAL 155 // about room temp
ALIAS(SEQ_FAN_CTL)
SEQUENCE(SEQ_FAN_CTL)
  AUTOSTART
  ATGTE(SENS_HEAT, HEAT_ON_VAL)
  SET(PIN_FAN)
  ATLT(SENS_HEAT, HEAT_OFF_VAL)
  RESET(PIN_FAN)
  FOLLOW(SEQ_FAN_CTL)


/* This macro does the following
 * 1. Create a handy alias for the turnout
 * 2. Create a turnout object but with a bogus pin since we need 2 pins per kato
 *    turnout with special pulsing logic
 * 3. ONCLOUSE/ONTHROW event handlers to do the pulsing logic
 * 4. A sequence (that follows itself) to listing for touch toggle changes and
 *    throw/close the turnout accordingly
*/
#define KATO_PULSE_MS 20
#define KATO_TURNOUT(ali, turn, sens, hba, hbb, desc) \
ALIAS(ali, turn) \
PIN_TURNOUT(turn, 0, desc) \
ONCLOSE(turn) SET(hba) DELAY(KATO_PULSE_MS) RESET(hba) DONE \
ONTHROW(turn) SET(hbb) DELAY(KATO_PULSE_MS) RESET(hbb) DONE \
SEQUENCE(turn+2000) \
  AUTOSTART \
  IF(sens) \
    AT(-sens) CLOSE(turn) FOLLOW(turn+2000) \
  ELSE \
    AT(sens) THROW(turn) FOLLOW(turn+2000) \
  ENDIF \
DONE

KATO_TURNOUT(TRN_1_1,  1, TOU_1_1, HBL_1_1_A, HBL_1_1_B, "E. loop (fake X)")
KATO_TURNOUT(TRN_1_2,  2, TOU_1_2, HBL_1_2_A, HBL_1_2_B, "Bakery")
KATO_TURNOUT(TRN_1_3,  3, TOU_1_3, HBL_1_3_A, HBL_1_3_B, "Interchange")
KATO_TURNOUT(TRN_1_4,  4, TOU_1_4, HBL_1_4_A, HBL_1_4_B, "Scrap yard")
KATO_TURNOUT(TRN_1_5,  5, TOU_1_5, HBL_1_5_A, HBL_1_5_B, "Runaround (fake X)")
KATO_TURNOUT(TRN_1_6,  6, TOU_1_6, HBL_1_6_A, HBL_1_6_B, "Brewery / Lumber yard")
KATO_TURNOUT(TRN_2_1,  7, TOU_2_1, HBU_2_1_A, HBU_2_1_B, "todo")
KATO_TURNOUT(TRN_2_2,  8, TOU_2_2, HBU_2_2_A, HBU_2_2_B, "todo")
KATO_TURNOUT(TRN_2_3,  9, TOU_2_3, HBU_2_3_A, HBU_2_3_B, "todo")
KATO_TURNOUT(TRN_2_4, 10, TOU_2_4, HBU_2_4_A, HBU_2_4_B, "todo")
KATO_TURNOUT(TRN_2_5, 11, TOU_2_5, HBU_2_5_A, HBU_2_5_B, "todo")
KATO_TURNOUT(TRN_2_6, 12, TOU_2_6, HBU_2_6_A, HBU_2_6_B, "todo")
KATO_TURNOUT(TRN_2_7, 13, TOU_2_7, HBU_2_7_A, HBU_2_7_B, "todo")
KATO_TURNOUT(TRN_2_8, 14, TOU_2_8, HBU_2_8_A, HBU_2_8_B, "todo")
KATO_TURNOUT(TRN_2_9, 15, TOU_2_9, HBU_2_9_A, HBU_2_9_B, "todo")


// Include all remaining routes and automations below
#include "myTrolley.h"
#include "myPassengerLoop.h"
