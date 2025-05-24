// TODO we may need to use SETFREQ during bootup
// TODO see ANOUT & PLAYSOUND for how to add mp3s with a DFPlayer

#define TROLLEY_SPEED 50 // TODO actual value needed
#define TROLLEY_SHRT_MS 2500
#define TROLLEY_MED_MS 10000
#define TROLLEY_LNG_MS 25000


// We start at or driving westbound to the west IR sensor.  This is the only
// sequence that will be visible to throttles
ALIAS(TROLLEY_START)
AUTOMATION(TROLLEY_START,"Start Trolley")
  IF(SENS_IR_STREET_WEST) FOLLOW(TROLLEY_LOOP) ENDIF
  FWD(TROLLEY_SPEED)
  AT(SENS_IR_STREET_WEST) STOP FOLLOW(TROLLEY_LOOP)
DONE

// Assumes starting position at SENS_IR_STREET_WEST then travels eastbound, then
// westbound, ad naseum.  Hidden to throttles, must use the start automation in
// order ascertain the location of the trolley safely.
ALIAS(TROLLEY_LOOP)
SEQUENCE(TROLLEY_LOOP)
  REV(TROLLEY_SPEED)
  AT(SENS_IR_STREET_MIDD) STOP DELAYRANDOM(TROLLEY_SHRT_MS, TROLLEY_MED_MS)
  REV(TROLLEY_SPEED)
  AT(SENS_IR_STREET_EAST) STOP DELAYRANDOM(TROLLEY_MED_MS, TROLLEY_LNG_MS)
  FWD(TROLLEY_SPEED)
  AT(SENS_IR_STREET_MIDD) STOP DELAYRANDOM(TROLLEY_SHRT_MS, TROLLEY_MED_MS)
  FWD(TROLLEY_SPEED)
  AT(SENS_IR_STREET_WEST) STOP DELAYRANDOM(TROLLEY_MED_MS, TROLLEY_LNG_MS)
  FOLLOW(TROLLEY_LOOP)
DONE
