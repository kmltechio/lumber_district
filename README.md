# DCC-EX config and automation settings for CB&Q Lumber District.

## Prerequisites

1. 1Password CLI

## Setup

`make` will do the following:
1. git clone the CommandStation-EX repo
1. switch it to the specified branch
1. copy the local header comfig/marco files into the CommandStation-EX folder

## TODOs

1. Can we use arduino-cli to make the project?
1. Will eventually have code for the I2C arduinos that manage the touch toggles

## Diagrams

### Power Distribution

```mermaid
flowchart LR
  subgraph ac ["⚡️120V A/C⚡️"]
    P120[Wall Plug]
    Pswitch[On/Off]
    end
  PSU
  P120 -->|black| Pswitch --> PSU
  P120 -->|white| PSU
  P120 -->|green| PSU
  Buck14[Buck 14V]
  Buck8[Buck 8V]
  PSU -->|24V| Buck14 & Buck8
  subgraph CmdStn[CommandStation EX]
    direction BT
    Mega
    Motor[Motor Shield]
    WiFi[Wifi Shield]
    Mega -->|5V| Motor -->|5V| WiFi
    end
  Lights[Lighting Nano]
  Touch[Touch Panel Nano]
  Gpio["GPIO Expanders 1-2"]
  HBridge["H Bridges 1-9"]
  Buck8 -->|8V| Mega
  Buck8 --->|8V| Lights & Touch
  Buck14 --->|14V| HBridge & Motor
  Mega --->|5V| Gpio
  Mega -->|5V| Fan
```

### Communication & Ports

```mermaid
flowchart LR
  subgraph Layout
    CmdStn[ComandStation EX]
    Touch[Touch Panel Nano]
    Gpio["GPIO Expanders 1-2"]
    Touch <-->|I2C| CmdStn
    CmdStn -->|I2C| Gpio
    end
  Wall[Wall Plug]
  Wall -->|"⚡120V A/C⚡️"| Layout
  Phone & Laptop -->|WiFi| Layout
  Laptop <-->|USB| Layout
  Layout -->|DCC| Cassette
```

### Power Panel Wiring

```mermaid
flowchart 
  subgraph Panel[Power Panel]
    Toggle1[Power SPST On-Off]
    Toggle2[Lights SPST On-Off]
    LED1[Track Power LED]
    Toggle3["Prog v. DC SPDT (On)-Off-(On)"]
    LED2[Prog LED]
    LED3[DC LED]
    end
  Wall[Wall Plug] -->|"⚡️120V A/C⚡️"| Toggle1 --> PSU
  Buck8[Buck 8V] --> Toggle2 --> Lights[Lighting Nano]
  Mega -->|Pin 3| LED1
  Mega -->|Pin TBD1| LED2
  Mega -->|Pin TBD2| Toggle3
  Mega -->|Pin TBD3| Toggle3
  Mega -->|Pin TBD4| LED3
  LED1 & LED2 & LED3 & Toggle3 --> GND
    
```
