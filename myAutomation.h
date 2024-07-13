// Locomotive Roster
// BLI w/ Paragon2 sound
ROSTER(9916,"CB&Q E7A","Lights/*Bell/*Horn/Couple/DynBrake/EngUp/EngDown/MARS/Vol/Startup/Shutdown/Fan/Air/Brake/XHorn/Passenger/Freight/Maint/Radio/City/Farm/Indistry/Lumber/2ndHorn//CabLight/Dimmer/Play/Record/Squeal")
// Kato w/ Digitrax DN123K3 decoder
ROSTER(9211,"CB&Q NW2","Lights")
// Non-DDC engines on the B track
ROSTER(666,"CD Engine")

// Track Manager
AUTOSTART
SET_TRACK(A, MAIN)
SETLOCO(666) SET_TRACK(B, DC) // set the DC locos to Track B aka trolley line
POWERON
DONE
