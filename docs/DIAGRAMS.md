# Power Distribution

```mermaid
flowchart LR
  P120[Wall Plug]
  PSU
  P120 -->|120VAC| PSU
  Buck14[Buck 14V]
  Buck8[Buck 8V]
  PSU -->|19.5V| Buck14 & Buck8
  subgraph CmdStn[CommandStation EX]
    direction BT
    Mega
    Motor[Motor Shield]
    WiFi[Wifi Shield]
    Mega -->|5V| Motor -->|5V| WiFi
    end
  Lights[Lighting Nano]
  Touch[Touch Panel Nano]
  Gpio["IO_EX Nanos 1-2"]
  HBridge["H Bridges 1-9"]
  IRSensors[IR Sensors]
  Buck8 -->|8V| Mega
  Buck8 ----->|8V| Lights & Touch & Gpio
  Buck14 ----->|14V| HBridge
  Buck14 --->|14V| Motor
  Mega ---->|5V| IRSensors
  Mega -->|5V| Fan
```

# Communication & Ports

```mermaid
flowchart LR
  subgraph Layout
    CmdStn[ComandStation EX]
    Touch[Touch Panel Nano]
    Gpio["IO_EX Nanos 1-2"]
    Touch <-->|I2C| CmdStn
    CmdStn -->|I2C| Gpio
    end
  PSU[19.5V PSU]
  PSU -->|"2.5mm Barrel Connector"| Layout
  Phone & Tablet & Laptop -.->|WiFi| Layout
  Laptop <-->|USB type A| Layout
  Layout -->|2.1mm Barrel Connector| Cassette[Staging Cassette]
```


# Control Panel Wiring

```mermaid
flowchart LR
  subgraph lp[Right Pane]
    touchLP["Touch Toggle 2.1...2.6"]
  end
  subgraph cp[Center Pane]
    Powerp["19.5vdc +"] ---> toggle[Power Toggle] ---> Powern["19.5vdc -"]
    TrackAp["Track A +"] ---> LEDa["Bi-color LED"] --> ResistorA["Resistor"] --> TrackAn["Track A -"]
    TrackBp["Track B +"] ---> LEDb["Bi-color LED"] --> ResistorB["Resistor"] --> TrackBn["Track B -"]
    9Vp["9.0 VDC +"] ---> Nano ---> 9Vn["9.0 VDC -"]
    I2Cc["I2C Clock"] <---> Nano <---> I2Cd["I2C Data"]
  end
  subgraph rp[Left Pane]
    touchRP["Touch Toggle 1.1...1.9"]
  end
  Nano ---->|"brown +5V"| touchLP & touchRP --->|"red GND"| Nano
  Nano <---->|"yellow sensor"| touchLP & touchRP
