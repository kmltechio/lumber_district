/* This macro does the following
 * 1. Create a handy alias for the turnout
 * 2. Create a virtual turnout object since we need 3 pins per kato
 *    turnout with special pulsing logic
 * 3. ONCLOUSE/ONTHROW event handlers to do the pulsing logic
 * 4. ONSENSOR handlers to allow the touch toggle to switch the turnout
 * Ref: https://dcc-ex.com/ex-commandstation/accessories/turnouts/solenoid-turnouts.html#using-an-l293d-motor-driver-single-solenoid-coil-turnouts
 *      https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/
*/
#define KATO_PULSE_MS 10
#define KATO_TURNOUT_W_TOUCH(ali, turn, sens, hba, hbb, enable, desc) \
ALIAS(ali, turn) \
VIRTUAL_TURNOUT(turn, desc) \
DONE \
ONSENSOR(sens) IF(sens) THROW(turn) ELSE CLOSE(turn) ENDIF DONE \
ONCLOSE(turn) SET(hba) RESET(hbb) SET(enable) DELAY(KATO_PULSE_MS) RESET(enable) DONE \
ONTHROW(turn) RESET(hba) SET(hbb) SET(enable) DELAY(KATO_PULSE_MS) RESET(enable) DONE

KATO_TURNOUT_W_TOUCH(TRN_1_1,  1, TOU_1_1, HBL_1_1_A, HBL_1_1_B, HBL_1_1_E, "E. loop (fake X)")
KATO_TURNOUT_W_TOUCH(TRN_1_2,  2, TOU_1_2, HBL_1_2_A, HBL_1_2_B, HBL_1_2_E, "Bakery")
KATO_TURNOUT_W_TOUCH(TRN_1_3,  3, TOU_1_3, HBL_1_3_A, HBL_1_3_B, HBL_1_3_E, "Interchange")
KATO_TURNOUT_W_TOUCH(TRN_1_4,  4, TOU_1_4, HBL_1_4_A, HBL_1_4_B, HBL_1_4_E, "Scrap yard")
KATO_TURNOUT_W_TOUCH(TRN_1_5,  5, TOU_1_5, HBL_1_5_A, HBL_1_5_B, HBL_1_5_E, "Runaround (fake X)")
KATO_TURNOUT_W_TOUCH(TRN_1_6,  6, TOU_1_6, HBL_1_6_A, HBL_1_6_B, HBL_1_6_E, "Brewery / Lumber yard")
// KATO_TURNOUT_W_TOUCH(TRN_2_1,  7, TOU_2_1, HBU_2_1_A, HBU_2_1_B, HBL_2_1_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_2,  8, TOU_2_2, HBU_2_2_A, HBU_2_2_B, HBL_2_2_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_3,  9, TOU_2_3, HBU_2_3_A, HBU_2_3_B, HBL_2_3_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_4, 10, TOU_2_4, HBU_2_4_A, HBU_2_4_B, HBL_2_4_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_5, 11, TOU_2_5, HBU_2_5_A, HBU_2_5_B, HBL_2_5_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_6, 12, TOU_2_6, HBU_2_6_A, HBU_2_6_B, HBL_2_6_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_7, 13, TOU_2_7, HBU_2_7_A, HBU_2_7_B, HBL_2_7_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_8, 14, TOU_2_8, HBU_2_8_A, HBU_2_8_B, HBL_2_8_E, "todo")
// KATO_TURNOUT_W_TOUCH(TRN_2_9, 15, TOU_2_9, HBU_2_9_A, HBU_2_9_B, HBL_2_9_E, "todo")
