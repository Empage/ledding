EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Thias Maite LED Project"
Date "2021-02-15"
Rev "1"
Comp "Matthis Hauschild"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:DIN-7_CenterPin7 J4
U 1 1 602ACD25
P 7400 1500
F 0 "J4" H 8050 1550 50  0000 C CNN
F 1 "LED Stripe Jack" H 8150 1400 50  0000 C CNN
F 2 "" H 7400 1500 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 7400 1500 50  0001 C CNN
	1    7400 1500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 602BB2F3
P 6500 2700
F 0 "J2" H 6418 3017 50  0000 C CNN
F 1 "Case-Board Jack" H 6418 2926 50  0000 C CNN
F 2 "" H 6500 2700 50  0001 C CNN
F 3 "~" H 6500 2700 50  0001 C CNN
	1    6500 2700
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Barrel_Jack_Switch J3
U 1 1 602BF0C3
P 3550 1400
F 0 "J3" H 3607 1625 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 3607 1626 50  0001 C CNN
F 2 "" H 3600 1360 50  0001 C CNN
F 3 "~" H 3600 1360 50  0001 C CNN
	1    3550 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 602C4148
P 7850 3150
F 0 "R2" V 7650 3150 50  0000 C CNN
F 1 "150" V 7750 3150 50  0000 C CNN
F 2 "" V 7780 3150 50  0001 C CNN
F 3 "~" H 7850 3150 50  0001 C CNN
	1    7850 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	6700 5550 6350 5550
Wire Wire Line
	6700 5550 8500 5550
Wire Wire Line
	8500 5550 8500 5150
Connection ~ 6700 5550
Wire Wire Line
	4050 5700 4050 4850
Wire Wire Line
	8000 3150 8700 3150
Wire Wire Line
	8700 3150 8700 4350
Wire Wire Line
	8700 4350 8500 4350
$Comp
L eec:SN74HCT245N U2
U 1 1 60292962
P 8600 5150
F 0 "U2" H 9300 5415 50  0000 C CNN
F 1 "SN74HCT245N" H 9300 5324 50  0000 C CNN
F 2 "Texas_Instruments-SN74HCT245N-0-0-*" H 8600 5550 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hct245.pdf" H 8600 5650 50  0001 L CNN
F 4 "+85°C" H 8600 5750 50  0001 L CNN "ambient temperature range high"
F 5 "-40°C" H 8600 5850 50  0001 L CNN "ambient temperature range low"
F 6 "No" H 8600 5950 50  0001 L CNN "automotive"
F 7 "IC" H 8600 6050 50  0001 L CNN "category"
F 8 "Integrated Circuits (ICs)" H 8600 6150 50  0001 L CNN "device class L1"
F 9 "Logic ICs" H 8600 6250 50  0001 L CNN "device class L2"
F 10 "Drivers and Transceivers" H 8600 6350 50  0001 L CNN "device class L3"
F 11 "IC TXRX NON-INVERT 5.5V 20DIP" H 8600 6450 50  0001 L CNN "digikey description"
F 12 "296-1612-5-ND" H 8600 6550 50  0001 L CNN "digikey part number"
F 13 "5.08mm" H 8600 6650 50  0001 L CNN "height"
F 14 "DIP794W46P254L2540H508Q20" H 8600 6750 50  0001 L CNN "ipc land pattern name"
F 15 "Yes" H 8600 6850 50  0001 L CNN "lead free"
F 16 "64376d108c417d40" H 8600 6950 50  0001 L CNN "library id"
F 17 "Non-Inverting" H 8600 7050 50  0001 L CNN "logic function desc"
F 18 "Texas Instruments" H 8600 7150 50  0001 L CNN "manufacturer"
F 19 "+150°C" H 8600 7250 50  0001 L CNN "max junction temp"
F 20 "5.5V" H 8600 7350 50  0001 L CNN "max supply voltage"
F 21 "4.5V" H 8600 7450 50  0001 L CNN "min supply voltage"
F 22 "Bus Transceivers Tri-State Octal Bus" H 8600 7550 50  0001 L CNN "mouser description"
F 23 "595-SN74HCT245N" H 8600 7650 50  0001 L CNN "mouser part number"
F 24 "8-80uA" H 8600 7750 50  0001 L CNN "nominal supply current"
F 25 "8" H 8600 7850 50  0001 L CNN "number of circuits"
F 26 "2" H 8600 7950 50  0001 L CNN "number of inputs"
F 27 "2" H 8600 8050 50  0001 L CNN "number of outputs"
F 28 "PDIP20" H 8600 8150 50  0001 L CNN "package"
F 29 "20ns" H 8600 8250 50  0001 L CNN "propagation delay"
F 30 "Yes" H 8600 8350 50  0001 L CNN "rohs"
F 31 "0.51mm" H 8600 8450 50  0001 L CNN "standoff height"
F 32 "+85°C" H 8600 8550 50  0001 L CNN "temperature range high"
F 33 "-40°C" H 8600 8650 50  0001 L CNN "temperature range low"
	1    8600 5150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 5550 4250 4950
Wire Wire Line
	4050 4850 4250 4850
Wire Wire Line
	4250 4450 4150 4450
Wire Wire Line
	8500 4650 8750 4650
Wire Wire Line
	8750 4650 8750 4850
Wire Wire Line
	8500 4850 8750 4850
Connection ~ 8750 4850
NoConn ~ 5650 4650
Text Notes 5600 4650 0    50   ~ 0
Internal LED
NoConn ~ 5650 4150
Text Notes 5600 4150 0    50   ~ 0
DevButton
NoConn ~ 5650 4450
NoConn ~ 5650 4350
NoConn ~ 5650 4250
NoConn ~ 5650 4950
NoConn ~ 5650 4850
NoConn ~ 5650 4050
NoConn ~ 5650 3950
NoConn ~ 5650 3850
NoConn ~ 5650 3750
NoConn ~ 5650 3650
NoConn ~ 4250 4350
NoConn ~ 4250 4250
NoConn ~ 4250 3950
NoConn ~ 4250 3850
NoConn ~ 4250 3750
NoConn ~ 4250 3650
NoConn ~ 4250 3550
Wire Wire Line
	7700 3150 7350 3150
Wire Wire Line
	7350 3150 7350 2600
Wire Wire Line
	7350 2600 6700 2600
$Comp
L Device:R R1
U 1 1 602C3B17
P 6900 3150
F 0 "R1" H 7000 3200 50  0000 L CNN
F 1 "150" H 7000 3100 50  0000 L CNN
F 2 "" V 6830 3150 50  0001 C CNN
F 3 "~" H 6900 3150 50  0001 C CNN
	1    6900 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2900 6700 3300
Wire Wire Line
	6700 2700 6900 2700
Wire Wire Line
	6900 2700 6900 3000
Wire Wire Line
	6800 5700 6800 3450
Wire Wire Line
	6800 2800 6700 2800
Wire Wire Line
	6900 3300 6700 3300
Connection ~ 6700 3300
Wire Wire Line
	6700 3300 6700 5550
Wire Wire Line
	8750 5700 6800 5700
Wire Wire Line
	8750 4850 8750 5700
Connection ~ 6800 5700
Wire Wire Line
	6800 3450 7300 3450
Connection ~ 6800 3450
Wire Wire Line
	6800 3450 6800 2800
$Comp
L power:GND #PWR04
U 1 1 60397E53
P 6350 5850
F 0 "#PWR04" H 6350 5600 50  0001 C CNN
F 1 "GND" H 6355 5677 50  0000 C CNN
F 2 "" H 6350 5850 50  0001 C CNN
F 3 "" H 6350 5850 50  0001 C CNN
	1    6350 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5700 6350 5850
Connection ~ 6350 5700
$Comp
L power:+5V #PWR03
U 1 1 6039C8CF
P 6350 5450
F 0 "#PWR03" H 6350 5300 50  0001 C CNN
F 1 "+5V" H 6365 5623 50  0000 C CNN
F 2 "" H 6350 5450 50  0001 C CNN
F 3 "" H 6350 5450 50  0001 C CNN
	1    6350 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5450 6350 5550
Connection ~ 6350 5550
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 603A58F1
P 3250 3350
F 0 "J1" H 3168 2725 50  0000 C CNN
F 1 "Touch Button Jack" H 3168 2816 50  0000 C CNN
F 2 "" H 3250 3350 50  0001 C CNN
F 3 "~" H 3250 3350 50  0001 C CNN
	1    3250 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3450 4750 3450 3650
Wire Wire Line
	3450 4750 4250 4750
Wire Wire Line
	3550 4650 3550 3550
Wire Wire Line
	3550 3550 3450 3550
Wire Wire Line
	3550 4650 4250 4650
Wire Wire Line
	3650 4050 3650 3450
Wire Wire Line
	3650 3450 3450 3450
Wire Wire Line
	3650 4050 4250 4050
Wire Wire Line
	3750 4150 3750 3350
Wire Wire Line
	3750 3350 3450 3350
Wire Wire Line
	3750 4150 4250 4150
Wire Wire Line
	5850 4750 5850 5250
Wire Wire Line
	5850 5250 3850 5250
Wire Wire Line
	3850 5250 3850 3250
Wire Wire Line
	3850 3250 3450 3250
Wire Wire Line
	5850 4750 5650 4750
Wire Wire Line
	5950 4550 5950 5350
Wire Wire Line
	5950 5350 3950 5350
Wire Wire Line
	3950 5350 3950 3150
Wire Wire Line
	3950 3150 3450 3150
Wire Wire Line
	5950 4550 5650 4550
Wire Wire Line
	4050 4550 4050 3050
Wire Wire Line
	4050 3050 3450 3050
Wire Wire Line
	4050 4550 4250 4550
Wire Wire Line
	4150 2950 3450 2950
Wire Wire Line
	4150 2950 4150 4450
Wire Wire Line
	6350 5700 6800 5700
Wire Wire Line
	6150 3550 5650 3550
Wire Wire Line
	6150 4350 7300 4350
Wire Wire Line
	6150 3550 6150 4350
Wire Notes Line
	2900 2250 2900 6200
Wire Notes Line
	2900 6200 8950 6200
Wire Notes Line
	8950 6200 8950 2250
Wire Notes Line
	8950 2250 2900 2250
Wire Wire Line
	5650 5550 6350 5550
Wire Wire Line
	5650 5700 6350 5700
Wire Wire Line
	4050 5700 6350 5700
Text Notes 2900 2350 0    50   ~ 0
Board
Text Notes 2500 3700 0    50   ~ 0
B7: Intensity+
Text Notes 2500 3600 0    50   ~ 0
B8: Intensity-
Text Notes 2500 3500 0    50   ~ 0
B5: Color next
Text Notes 2500 3400 0    50   ~ 0
B6: Color prev
Text Notes 2500 3300 0    50   ~ 0
B3: Mode next
Text Notes 2500 3200 0    50   ~ 0
B4: Mode prev
Text Notes 2500 3100 0    50   ~ 0
B1: Brightness+
Text Notes 2500 3000 0    50   ~ 0
B2: Brightness-
Text Notes 6000 2750 0    50   ~ 0
Status LED
Text Notes 6250 2850 0    50   ~ 0
GND
Text Notes 6300 2950 0    50   ~ 0
5V
Text Notes 5950 2650 0    50   ~ 0
Stripe Data
$Comp
L Device:LED D1
U 1 1 60427A6C
P 5850 1900
F 0 "D1" H 5843 2117 50  0000 C CNN
F 1 "LED" H 5843 2026 50  0000 C CNN
F 2 "" H 5850 1900 50  0001 C CNN
F 3 "~" H 5850 1900 50  0001 C CNN
	1    5850 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 604271D7
P 5550 1450
F 0 "C1" H 5668 1496 50  0000 L CNN
F 1 "4700µ" H 5668 1405 50  0000 L CNN
F 2 "" H 5588 1300 50  0001 C CNN
F 3 "~" H 5550 1450 50  0001 C CNN
	1    5550 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1300 4150 1300
$Comp
L Switch:SW_DIP_x01 SW1
U 1 1 602C6CC6
P 4800 1300
F 0 "SW1" H 4800 1475 50  0000 C CNN
F 1 "SW_DIP_x01" H 4800 1476 50  0001 C CNN
F 2 "" H 4800 1300 50  0001 C CNN
F 3 "~" H 4800 1300 50  0001 C CNN
	1    4800 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 1300 5550 1300
Wire Wire Line
	5550 1600 5300 1600
Wire Wire Line
	3850 1600 3850 1500
$Comp
L power:GND #PWR02
U 1 1 60450BDD
P 4150 1750
F 0 "#PWR02" H 4150 1500 50  0001 C CNN
F 1 "GND" H 4155 1577 50  0000 C CNN
F 2 "" H 4150 1750 50  0001 C CNN
F 3 "" H 4150 1750 50  0001 C CNN
	1    4150 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 1600 4150 1750
Connection ~ 4150 1600
Wire Wire Line
	4150 1600 3850 1600
$Comp
L power:+5V #PWR01
U 1 1 60453217
P 4150 1150
F 0 "#PWR01" H 4150 1000 50  0001 C CNN
F 1 "+5V" H 4165 1323 50  0000 C CNN
F 2 "" H 4150 1150 50  0001 C CNN
F 3 "" H 4150 1150 50  0001 C CNN
	1    4150 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 1150 4150 1300
Connection ~ 4150 1300
Wire Wire Line
	4150 1300 4250 1300
$Comp
L power:PWR_FLAG #FLG01
U 1 1 6045594B
P 4250 1150
F 0 "#FLG01" H 4250 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 4250 1323 50  0001 C CNN
F 2 "" H 4250 1150 50  0001 C CNN
F 3 "~" H 4250 1150 50  0001 C CNN
	1    4250 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1150 4250 1300
Connection ~ 4250 1300
Wire Wire Line
	4250 1300 4500 1300
$Comp
L power:PWR_FLAG #FLG02
U 1 1 60457DD9
P 4250 1750
F 0 "#FLG02" H 4250 1825 50  0001 C CNN
F 1 "PWR_FLAG" H 4250 1923 50  0001 C CNN
F 2 "" H 4250 1750 50  0001 C CNN
F 3 "~" H 4250 1750 50  0001 C CNN
	1    4250 1750
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 1750 4250 1600
Connection ~ 4250 1600
Wire Wire Line
	4250 1600 4150 1600
$Comp
L Connector:Conn_01x04_Female P2
U 1 1 602BC31E
P 6450 2200
F 0 "P2" V 6296 1912 50  0000 R CNN
F 1 "Case-Board Plug" V 6387 1912 50  0000 R CNN
F 2 "" H 6450 2200 50  0001 C CNN
F 3 "~" H 6450 2200 50  0001 C CNN
	1    6450 2200
	0    -1   1    0   
$EndComp
Wire Wire Line
	6350 2000 6350 1800
Wire Wire Line
	6450 2000 6450 1900
Wire Wire Line
	6450 1900 6000 1900
Wire Wire Line
	5700 1900 5300 1900
Wire Wire Line
	5300 1900 5300 1600
Connection ~ 5300 1600
Wire Wire Line
	5300 1600 4250 1600
Wire Wire Line
	6550 2000 6550 1600
Wire Wire Line
	6550 1600 5550 1600
Connection ~ 5550 1600
Wire Wire Line
	6350 1800 7400 1800
Wire Wire Line
	6550 1600 7100 1600
Connection ~ 6550 1600
Wire Wire Line
	7100 1500 7100 1600
Connection ~ 7100 1600
Wire Wire Line
	7100 1400 7100 1500
Connection ~ 7100 1500
Wire Wire Line
	7700 1600 7700 1500
Wire Wire Line
	7700 1500 7700 1400
Connection ~ 7700 1500
Connection ~ 7700 1400
Wire Wire Line
	7700 1250 6650 1250
Wire Wire Line
	7700 1250 7700 1400
Wire Wire Line
	4250 5550 6350 5550
Wire Wire Line
	6650 1250 6650 2000
Wire Wire Line
	6650 1250 5550 1250
Wire Wire Line
	5550 1250 5550 1300
Connection ~ 6650 1250
Connection ~ 5550 1300
$Comp
L ESP32DEVKITV1:ESP32DEVKITV1 U1
U 1 1 60290A50
P 4950 4050
F 0 "U1" V 3874 4050 50  0000 C CNN
F 1 "ESP32DEVKITV1" H 4950 4050 50  0001 L BNN
F 2 "ESP32-DEVKITV1" H 4950 4050 50  0001 L BNN
F 3 "" H 4950 4050 50  0001 C CNN
	1    4950 4050
	0    -1   -1   0   
$EndComp
NoConn ~ 3850 1400
NoConn ~ 7300 3650
NoConn ~ 7300 3750
NoConn ~ 7300 3850
NoConn ~ 7300 3950
NoConn ~ 7300 4050
NoConn ~ 7300 4150
NoConn ~ 7300 4250
NoConn ~ 8500 4250
NoConn ~ 8500 4150
NoConn ~ 8500 4050
NoConn ~ 8500 3950
NoConn ~ 8500 3850
NoConn ~ 8500 3750
NoConn ~ 8500 3650
$EndSCHEMATC
