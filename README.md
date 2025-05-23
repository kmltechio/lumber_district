# lumber_district

Configuration and automation settings for an N scale layout modeled off of
CB&Q's Lumber District in Chicago's Pilsen neighborhood during the 1950s/60s.

Trains on the main section of the layout are powered by DCC signals generated
by [CommandStation-EX](https://dcc-ex.com/ex-commandstation/index.html) running
on an [Arduino Mega 2560
Rev3](https://store-usa.arduino.cc/products/arduino-mega-2560-rev3) with an
[Arduino Motor
Shield](https://store-usa.arduino.cc/collections/shields/products/arduino-motor-shield-rev3)
and a [Makerfabs ESP8266 WiFi
shield](https://www.makerfabs.com/esp8266-wifi-shield.html). 

A secondary track can toggle between DCC Programming mode and DC power to run
legacy DC locomotives. This will most often run a street trolley with
automation scripted by [EX-RAIL](https://dcc-ex.com/ex-rail/index.html). 

Mimic panels are designed around [Berret Hill Touch
Toggles](https://www.berretthillshop.com/store/products/touch-controls/) driven
by custom code loaded onto an [Arduino Nano
Every](https://store-usa.arduino.cc/collections/boards/products/arduino-nano-every)
which communicates with the Mega over I2C

Also on the I2C bus are two 16pin GPIO expanders to activate [L289N H
Bridges](https://www.amazon.com/dp/B08RS3P1ZW) which drive the Kato Unitrack
snap turnouts.

Finally an Arduino Nano Every with custom code drives static and animated LED
lighting across the layout. 

## Documentation

* [Setup & Compilation](./docs/SETUP.md)
* [Diagrams](./docs/DIAGRAMS.md)
* [TODOs](./docs/TODO.md)
