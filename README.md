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
  P120[120V Plug]
  Pswitch[On/Off]
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
  Mega -->|5V| Gpio
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
  Phone
  Laptop
  Cassette
  Phone & Laptop -->|WiFi| Layout
  Laptop <-->|USB| Layout
  Layout -->|DCC| Cassette
```
