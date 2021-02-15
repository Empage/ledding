EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:DIN-7_CenterPin7 J?
U 1 1 602ACD25
P 8450 1950
F 0 "J?" H 8450 2317 50  0000 C CNN
F 1 "DIN-7_CenterPin7" H 8450 2226 50  0000 C CNN
F 2 "" H 8450 1950 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 8450 1950 50  0001 C CNN
	1    8450 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J?
U 1 1 602B80E9
P 5150 2750
F 0 "J?" V 5114 2262 50  0000 R CNN
F 1 "Conn_01x08" V 5023 2262 50  0000 R CNN
F 2 "" H 5150 2750 50  0001 C CNN
F 3 "~" H 5150 2750 50  0001 C CNN
	1    5150 2750
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 602BB2F3
P 6200 2750
F 0 "J?" V 6164 2462 50  0000 R CNN
F 1 "Conn_01x04" V 6073 2462 50  0000 R CNN
F 2 "" H 6200 2750 50  0001 C CNN
F 3 "~" H 6200 2750 50  0001 C CNN
	1    6200 2750
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Barrel_Jack_Switch J?
U 1 1 602BF0C3
P 2200 2200
F 0 "J?" H 2257 2517 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 2257 2426 50  0000 C CNN
F 2 "" H 2250 2160 50  0001 C CNN
F 3 "~" H 2250 2160 50  0001 C CNN
	1    2200 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Female J?
U 1 1 602C23F9
P 5150 2400
F 0 "J?" V 5150 3300 50  0000 C CNN
F 1 "Conn_01x08_Female" V 5050 3200 50  0000 C CNN
F 2 "" H 5150 2400 50  0001 C CNN
F 3 "~" H 5150 2400 50  0001 C CNN
	1    5150 2400
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 602C3B17
P 6200 3600
F 0 "R?" H 6050 3650 50  0000 L CNN
F 1 "150" H 6000 3550 50  0000 L CNN
F 2 "" V 6130 3600 50  0001 C CNN
F 3 "~" H 6200 3600 50  0001 C CNN
	1    6200 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 602C4148
P 7550 3150
F 0 "R?" V 7343 3150 50  0000 C CNN
F 1 "150" V 7434 3150 50  0000 C CNN
F 2 "" V 7480 3150 50  0001 C CNN
F 3 "~" H 7550 3150 50  0001 C CNN
	1    7550 3150
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_DIP_x01 SW?
U 1 1 602C6CC6
P 2150 1750
F 0 "SW?" H 2150 2017 50  0000 C CNN
F 1 "SW_DIP_x01" H 2150 1926 50  0000 C CNN
F 2 "" H 2150 1750 50  0001 C CNN
F 3 "~" H 2150 1750 50  0001 C CNN
	1    2150 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 5550 3250 5550
Wire Wire Line
	6400 5550 8200 5550
Wire Wire Line
	8200 5550 8200 5150
Connection ~ 6400 5550
Wire Wire Line
	6300 2950 6300 5700
Wire Wire Line
	6300 5700 3050 5700
Wire Wire Line
	3050 5700 3050 4850
Wire Wire Line
	7700 3150 8400 3150
Wire Wire Line
	8400 3150 8400 4350
Wire Wire Line
	8400 4350 8200 4350
$Comp
L eec:SN74HCT245N U?
U 1 1 60292962
P 8300 5150
F 0 "U?" H 9000 5415 50  0000 C CNN
F 1 "SN74HCT245N" H 9000 5324 50  0000 C CNN
F 2 "Texas_Instruments-SN74HCT245N-0-0-*" H 8300 5550 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hct245.pdf" H 8300 5650 50  0001 L CNN
F 4 "+85°C" H 8300 5750 50  0001 L CNN "ambient temperature range high"
F 5 "-40°C" H 8300 5850 50  0001 L CNN "ambient temperature range low"
F 6 "No" H 8300 5950 50  0001 L CNN "automotive"
F 7 "IC" H 8300 6050 50  0001 L CNN "category"
F 8 "Integrated Circuits (ICs)" H 8300 6150 50  0001 L CNN "device class L1"
F 9 "Logic ICs" H 8300 6250 50  0001 L CNN "device class L2"
F 10 "Drivers and Transceivers" H 8300 6350 50  0001 L CNN "device class L3"
F 11 "IC TXRX NON-INVERT 5.5V 20DIP" H 8300 6450 50  0001 L CNN "digikey description"
F 12 "296-1612-5-ND" H 8300 6550 50  0001 L CNN "digikey part number"
F 13 "5.08mm" H 8300 6650 50  0001 L CNN "height"
F 14 "DIP794W46P254L2540H508Q20" H 8300 6750 50  0001 L CNN "ipc land pattern name"
F 15 "Yes" H 8300 6850 50  0001 L CNN "lead free"
F 16 "64376d108c417d40" H 8300 6950 50  0001 L CNN "library id"
F 17 "Non-Inverting" H 8300 7050 50  0001 L CNN "logic function desc"
F 18 "Texas Instruments" H 8300 7150 50  0001 L CNN "manufacturer"
F 19 "+150°C" H 8300 7250 50  0001 L CNN "max junction temp"
F 20 "5.5V" H 8300 7350 50  0001 L CNN "max supply voltage"
F 21 "4.5V" H 8300 7450 50  0001 L CNN "min supply voltage"
F 22 "Bus Transceivers Tri-State Octal Bus" H 8300 7550 50  0001 L CNN "mouser description"
F 23 "595-SN74HCT245N" H 8300 7650 50  0001 L CNN "mouser part number"
F 24 "8-80uA" H 8300 7750 50  0001 L CNN "nominal supply current"
F 25 "8" H 8300 7850 50  0001 L CNN "number of circuits"
F 26 "2" H 8300 7950 50  0001 L CNN "number of inputs"
F 27 "2" H 8300 8050 50  0001 L CNN "number of outputs"
F 28 "PDIP20" H 8300 8150 50  0001 L CNN "package"
F 29 "20ns" H 8300 8250 50  0001 L CNN "propagation delay"
F 30 "Yes" H 8300 8350 50  0001 L CNN "rohs"
F 31 "0.51mm" H 8300 8450 50  0001 L CNN "standoff height"
F 32 "+85°C" H 8300 8550 50  0001 L CNN "temperature range high"
F 33 "-40°C" H 8300 8650 50  0001 L CNN "temperature range low"
	1    8300 5150
	-1   0    0    1   
$EndComp
Wire Wire Line
	6100 3150 7400 3150
Wire Wire Line
	6100 2950 6100 3150
Wire Wire Line
	2950 4650 2950 3000
Wire Wire Line
	2950 3000 4950 3000
Wire Wire Line
	4950 3000 4950 2950
Wire Wire Line
	5050 2950 5050 3050
Wire Wire Line
	5050 3050 3000 3050
Wire Wire Line
	3000 3050 3000 4050
Wire Wire Line
	3250 5550 3250 4950
Wire Wire Line
	3050 4850 3250 4850
Wire Wire Line
	3250 4650 2950 4650
Wire Wire Line
	3000 4050 3250 4050
Wire Wire Line
	2900 2950 4850 2950
Wire Wire Line
	3250 4750 2900 4750
Wire Wire Line
	2900 4750 2900 2950
Wire Wire Line
	3250 4150 3050 4150
Wire Wire Line
	3050 4150 3050 3100
Wire Wire Line
	3050 3100 5150 3100
Wire Wire Line
	5150 3100 5150 2950
Wire Wire Line
	5250 2950 5250 4750
Wire Wire Line
	5250 4750 4650 4750
Wire Wire Line
	5350 2950 5350 4550
Wire Wire Line
	5350 4550 4650 4550
Wire Wire Line
	3250 4550 3100 4550
Wire Wire Line
	3100 4550 3100 3150
Wire Wire Line
	5450 3150 5450 2950
Wire Wire Line
	3250 4450 3150 4450
Wire Wire Line
	3150 4450 3150 3200
Wire Wire Line
	3150 3200 5550 3200
Wire Wire Line
	5550 3200 5550 2950
$Comp
L power:GND #PWR?
U 1 1 6031B31B
P 8450 5000
F 0 "#PWR?" H 8450 4750 50  0001 C CNN
F 1 "GND" H 8455 4827 50  0000 C CNN
F 2 "" H 8450 5000 50  0001 C CNN
F 3 "" H 8450 5000 50  0001 C CNN
	1    8450 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 4650 8450 4650
Wire Wire Line
	8450 4650 8450 4850
$Comp
L power:GND #PWR?
U 1 1 6031D15F
P 6750 3550
F 0 "#PWR?" H 6750 3300 50  0001 C CNN
F 1 "GND" H 6755 3377 50  0000 C CNN
F 2 "" H 6750 3550 50  0001 C CNN
F 3 "" H 6750 3550 50  0001 C CNN
	1    6750 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3550 6750 3450
Wire Wire Line
	6750 3450 7000 3450
Wire Wire Line
	8200 4850 8450 4850
Connection ~ 8450 4850
Wire Wire Line
	8450 4850 8450 5000
Wire Wire Line
	7000 4350 5650 4350
Wire Wire Line
	5650 4350 5650 3550
Wire Wire Line
	5650 3550 4650 3550
NoConn ~ 4650 4650
Text Notes 4600 4650 0    50   ~ 0
Internal LED
NoConn ~ 4650 4150
Text Notes 4600 4150 0    50   ~ 0
DevButton
Wire Wire Line
	3100 3150 5450 3150
$Comp
L ESP32DEVKITV1:ESP32DEVKITV1 U?
U 1 1 60290A50
P 3950 4050
F 0 "U?" V 2874 4050 50  0000 C CNN
F 1 "ESP32DEVKITV1" H 3950 4050 50  0001 L BNN
F 2 "ESP32-DEVKITV1" H 3950 4050 50  0001 L BNN
F 3 "" H 3950 4050 50  0001 C CNN
	1    3950 4050
	0    -1   -1   0   
$EndComp
NoConn ~ 4650 4450
NoConn ~ 4650 4350
NoConn ~ 4650 4250
NoConn ~ 4650 4950
NoConn ~ 4650 4850
NoConn ~ 4650 4050
NoConn ~ 4650 3950
NoConn ~ 4650 3850
NoConn ~ 4650 3750
NoConn ~ 4650 3650
NoConn ~ 3250 4350
NoConn ~ 3250 4250
NoConn ~ 3250 3950
NoConn ~ 3250 3850
NoConn ~ 3250 3750
NoConn ~ 3250 3650
NoConn ~ 3250 3550
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 602BC31E
P 6200 2400
F 0 "J?" V 6046 2112 50  0000 R CNN
F 1 "Conn_01x04_Female" V 6137 2112 50  0000 R CNN
F 2 "" H 6200 2400 50  0001 C CNN
F 3 "~" H 6200 2400 50  0001 C CNN
	1    6200 2400
	0    -1   1    0   
$EndComp
Wire Wire Line
	6200 2950 6200 3450
Wire Wire Line
	6400 2950 6400 3750
Wire Wire Line
	6200 3750 6400 3750
Connection ~ 6400 3750
Wire Wire Line
	6400 3750 6400 5550
$EndSCHEMATC
