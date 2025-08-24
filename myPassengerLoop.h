
#define PSSNGR_SPEED 40
#define PSSNGR_DELAY_LO_MS  5000 // TODO adjust timing after testing
#define PSSNGR_DELAY_HI_MS 10000

/*
Assume start from upper level and thus clockwise direction
Assume initial turnouts are manually set
TODO Use XF*() functions to turn on/off DCC loco sounds/lights
*/
ALIAS(PSSNGR_LOOP)
AUTOMATION(PSSNGR_LOOP,"Pass. Loop")
  FWD(PSSNGR_SPEED)
  AT(SENS_IR_TUNNEL_WEST)
  // TODO turn DCC sound & lights off
  AT(SENS_IR_TUNNEL_EAST)
  STOP
  DELAYRANDOM(PSSNGR_DELAY_LO_MS,PSSNGR_DELAY_LO_MS)
  /* TODO
  blow horn
  delay to let crews get out of the way
  blow horn twice
  short delay
  turn sound on
  turn lights on
  CALL turnout ROUTE to set the switches as needed to loop
  */
FOLLOW(PSSNGR_LOOP)