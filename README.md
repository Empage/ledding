Ledding
=======

Fancy LED project

## Hardware
1. MCU is the ESP32

Feature | Description
---------- | ------
SoM | from Broodio (quite unknown, selecting the ESP32 Development Kit (DevKitC) is suitable)
SoC | ESP-WROOM-32D
CPU | ESP32-D0WD
Flash | 4 MiB
RAM | 320 KiB

1. LED stripes are WS2812B
    1. 30 LED per meter, and
    1. 60 LED per meter

## Notes
1. Writing one pixel takes ~30 µs (tbc)

## TODO
1. Add 200 Ohm Resistor on Data to GND
1. Add capacitor on the power lines of the strip
