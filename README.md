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

1. LED stripes are WS2812B and WS2815 with 30 LEDs per meter and WS2812B with 60 LEDs per meter.

### LED stripe WS2812B and WS2815
Consists of a 5050 SMD and a WS2812B or WS2815 chip.

#### Timing:
Clock of the stripe is at 800 kHz. Writing one bit takes
```
t_b = 1 / 800 kHz = 1.25 µs
```
Writing one pixel takes
```
t_B = 24 bit * 1.25 µs/bit = 30 µs`
```
Writing 10m stripe of 30 LED/m takes
```
T = 10 m * 30 px/m * 30 µs = 9 ms
```
This would give a maximum refresh rate of
```
f = 1 / 9 ms ≈ 111 Hz
```

### Power considerations
####WS2812B
For the 5V strips each LED pulls max. ~20 mA (realistic max is 15 mA) per color, so 60 mA (45 mA) per pixel.
For 10 m of the 30 px/m stripe, we have at maximum brightness
```
Theoretical:
I_t5 = 10 m * 30 px/m * 60 mA/px = 18 A
P_t5 = 18 A * 5V = 90 W

Realistic:
I_r5 = 10 m * 30 px/m * 45 mA/px = 13.5 A
P_r5 = 13.5 A * 5V = 67.5 W
```

####WS2815
For the 12V strips each LED pulls max. 15 mA per color, but also max. 15 mA for the full pixel (they are in series). Power is burnt for non-white.
For 10 m of the 30 LED/m stripe, we have at maximum brightness
```
I_r12 = 10 m * 30 px/m * 15 mA/px = 4.5 A
P_r12 = 15 A * 12V = 54 W
```

####Cabling
For the cable the resistance is
```
R = l / (\kappa * A)
```
where l is the cable length in m, kappa is the conductivity in (m / (\ohm * mm^2)) and A is the cross-section in mm^2.
Longest length is 18 m (twice that to account for GND back) with copper `\gamma = 57.18 (m / (\ohm * mm^2))`
```
R_2.5 = 36 m / 57.18 (m / (\ohm * mm^2)) / 2.5 mm^2 ≈ 0.252 \Ohm
R_1.5 = 36 m / 57.18 (m / (\ohm * mm^2)) / 1.5 mm^2 ≈ 0.420 \Ohm
```
Assuming to power 5 m of the LED strip with the 18m of cable leads to
```
I = 5 m * 30 px/m * 45 mA = 6.75 A
U = 0.252 * 6.75 A = 1.701 V
```
leaving only `5 - 1.701 = 3.299 V` for the LEDs with 2.5 mm^2 copper cable. Not really enough...\
With the WS2815 it would be:
```
I = 5 m * 30px/m * 15 mA = 2.25 A
U_c2.5 = 0.252 * 2.25 A = 0.567 V for 2.5 mm^2 copper or
U_c1.5 = 0.420 * 2.25 A = 0.945 V for 1.5 mm^2 copper
```
leaving > 11 V for the LEDs in both cases. This should enough for equal color rendering on all LEDs (to be confirmed).

### Level shifters
Available (should be fast enough):
- 74AHCT125 (quad level shifter)
- TXB0108 (eight channel bi-directional)

## Software
This project uses platformio (https://platformio.org/) as its build system.
Important platformio commands (next to those in the Makefile which are described there):

1. Serial console: `pio device monitor -b 115200`

### Programming
To program the ESP32, issue `make upload`, then hold down the `BOOT` button on the ESP32-board until the upload starts.

## Partyraum Installation
LED stripes of
- 2x 10 m
- 4x  2 m

results in `28 m * 30 px/m = 840 px`. Safety margin: `900 px`

We choose the WS2815 for less current and therefore easier cabeling
Theoretically, we need
```
900 px * 15 mA/px = 13.5 A
13.5 A * 12 V = 162 W
```

The Meanwell LRS-200-12 is a good fit.

### TODO
1. Add 200 Ohm Resistor on Data to GND
1. Add capacitor on the power lines of the strip
