EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title "Miniscope-V4-Rigid-Flex"
Date "2020-06-25"
Rev "4.40"
Comp "Aharoni Lab"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L .MCU:ATmega328-MU U?
U 1 1 5D79A391
P 3925 3900
AR Path="/5D79A391" Ref="U?"  Part="1" 
AR Path="/5D795553/5D79A391" Ref="U1"  Part="1" 
F 0 "U1" H 3475 5350 50  0000 C CNN
F 1 "ATmega328-MU" H 4375 5350 50  0000 C CNN
F 2 ".Package_QFN:QFN_33_P50_500X500X80L40X24T310L" H 3925 2050 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001906C.pdf" H 3925 3900 50  0001 C CNN
	1    3925 3900
	1    0    0    -1  
$EndComp
$Comp
L .Capacitor:GRM155R60J475ME87D C?
U 1 1 5D79A39F
P 3325 1950
AR Path="/5D79A39F" Ref="C?"  Part="1" 
AR Path="/5D795553/5D79A39F" Ref="C2"  Part="1" 
F 0 "C2" H 3417 1996 50  0000 L CNN
F 1 "GRM155R60J475ME47D" H 2935 2120 50  0001 L CNN
F 2 ".Capacitor:C_0402_1005Metric_L" H 3435 2220 50  0001 C CNN
F 3 "" H 3335 2020 50  0001 C CNN
F 4 "4.7uF" H 3417 1905 50  0000 L CNN "Note"
F 5 "0402" H 3435 1770 50  0001 C CNN "Size"
	1    3325 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D79A3A5
P 4125 5400
AR Path="/5D79A3A5" Ref="#PWR?"  Part="1" 
AR Path="/5D795553/5D79A3A5" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 4125 5150 50  0001 C CNN
F 1 "GND" H 4130 5227 50  0000 C CNN
F 2 "" H 4125 5400 50  0001 C CNN
F 3 "" H 4125 5400 50  0001 C CNN
	1    4125 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+1V8 #PWR?
U 1 1 5D79A3AB
P 2925 1850
AR Path="/5D79A3AB" Ref="#PWR?"  Part="1" 
AR Path="/5D795553/5D79A3AB" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 2925 1700 50  0001 C CNN
F 1 "+1V8" H 2940 2023 50  0000 C CNN
F 2 "" H 2925 1850 50  0001 C CNN
F 3 "" H 2925 1850 50  0001 C CNN
	1    2925 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4025 2400 3925 2400
Wire Wire Line
	3825 2400 3825 1850
Wire Wire Line
	3825 1850 3325 1850
Connection ~ 3825 2400
Connection ~ 3925 2400
Wire Wire Line
	3925 2400 3825 2400
Connection ~ 3325 1850
Wire Wire Line
	3325 1850 2925 1850
Wire Wire Line
	3325 2050 2925 2050
Wire Wire Line
	3825 5400 3925 5400
Connection ~ 3925 5400
Wire Wire Line
	3925 5400 4025 5400
Connection ~ 4025 5400
Wire Wire Line
	4025 5400 4125 5400
Connection ~ 4125 5400
$Comp
L power:GND #PWR?
U 1 1 5D79A3C0
P 3325 2050
AR Path="/5D79A3C0" Ref="#PWR?"  Part="1" 
AR Path="/5D795553/5D79A3C0" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 3325 1800 50  0001 C CNN
F 1 "GND" H 3330 1877 50  0000 C CNN
F 2 "" H 3325 2050 50  0001 C CNN
F 3 "" H 3325 2050 50  0001 C CNN
	1    3325 2050
	1    0    0    -1  
$EndComp
Connection ~ 3325 2050
Wire Wire Line
	4525 2700 4975 2700
Wire Wire Line
	4525 2800 4975 2800
Wire Wire Line
	4525 3000 4975 3000
Wire Wire Line
	4525 3100 4975 3100
Wire Wire Line
	4525 3200 4975 3200
Wire Wire Line
	4525 3300 4975 3300
Wire Wire Line
	4525 3400 4975 3400
Wire Wire Line
	4525 3600 4975 3600
Wire Wire Line
	4525 3700 4975 3700
Wire Wire Line
	4525 3800 4975 3800
Wire Wire Line
	4525 3900 4975 3900
Wire Wire Line
	4525 4000 4975 4000
Wire Wire Line
	4525 4100 4975 4100
Wire Wire Line
	4525 4200 4975 4200
Wire Wire Line
	4525 4700 4975 4700
Wire Wire Line
	4525 5000 4975 5000
Text Label 4675 3400 0    50   ~ 0
LED
Text Label 4675 3000 0    50   ~ 0
MOSI
Text Label 4675 3100 0    50   ~ 0
MISO
Text Label 4675 3200 0    50   ~ 0
SCLK
Text Label 4675 4100 0    50   ~ 0
SCL
Text Label 4675 4000 0    50   ~ 0
SDA
Text Label 4675 4700 0    50   ~ 0
SS_N
Text Label 4675 3700 0    50   ~ 0
MONITOR0
Text Label 4675 3800 0    50   ~ 0
TRIGGER0
Text Label 4675 3900 0    50   ~ 0
RESET_N
Text Label 4675 4200 0    50   ~ 0
RESET_N_ISP
Text Label 4675 2700 0    50   ~ 0
ENT1
Text Label 4675 2800 0    50   ~ 0
ENT2
$Comp
L .Connector:Conn_01x01 J?
U 1 1 5D79A414
P 6725 2600
AR Path="/5D79A414" Ref="J?"  Part="1" 
AR Path="/5D795553/5D79A414" Ref="J5"  Part="1" 
F 0 "J5" H 6804 2596 50  0000 L CNN
F 1 "DNL" H 6805 2551 50  0001 L CNN
F 2 ".Connector:Conn_1x1_700_Circular_Pad" H 6725 2600 50  0001 C CNN
F 3 "~" H 6725 2600 50  0001 C CNN
	1    6725 2600
	1    0    0    -1  
$EndComp
$Comp
L .Connector:Conn_01x01 J?
U 1 1 5D79A41A
P 6725 2500
AR Path="/5D79A41A" Ref="J?"  Part="1" 
AR Path="/5D795553/5D79A41A" Ref="J3"  Part="1" 
F 0 "J3" H 6804 2496 50  0000 L CNN
F 1 "DNL" H 6805 2451 50  0001 L CNN
F 2 ".Connector:Conn_1x1_700_Circular_Pad" H 6725 2500 50  0001 C CNN
F 3 "~" H 6725 2500 50  0001 C CNN
	1    6725 2500
	1    0    0    -1  
$EndComp
$Comp
L .Connector:Conn_01x01 J?
U 1 1 5D79A420
P 6725 2400
AR Path="/5D79A420" Ref="J?"  Part="1" 
AR Path="/5D795553/5D79A420" Ref="J1"  Part="1" 
F 0 "J1" H 6804 2396 50  0000 L CNN
F 1 "DNL" H 6805 2351 50  0001 L CNN
F 2 ".Connector:Conn_1x1_700_Circular_Pad" H 6725 2400 50  0001 C CNN
F 3 "~" H 6725 2400 50  0001 C CNN
	1    6725 2400
	1    0    0    -1  
$EndComp
$Comp
L .Connector:Conn_01x01 J?
U 1 1 5D79A426
P 6975 2400
AR Path="/5D79A426" Ref="J?"  Part="1" 
AR Path="/5D795553/5D79A426" Ref="J2"  Part="1" 
F 0 "J2" H 6895 2267 50  0000 C CNN
F 1 "DNL" H 7055 2351 50  0001 L CNN
F 2 ".Connector:Conn_1x1_700_Circular_Pad" H 6975 2400 50  0001 C CNN
F 3 "~" H 6975 2400 50  0001 C CNN
	1    6975 2400
	-1   0    0    1   
$EndComp
$Comp
L .Connector:Conn_01x01 J?
U 1 1 5D79A42C
P 6975 2500
AR Path="/5D79A42C" Ref="J?"  Part="1" 
AR Path="/5D795553/5D79A42C" Ref="J4"  Part="1" 
F 0 "J4" H 6895 2367 50  0000 C CNN
F 1 "DNL" H 7055 2451 50  0001 L CNN
F 2 ".Connector:Conn_1x1_700_Circular_Pad" H 6975 2500 50  0001 C CNN
F 3 "~" H 6975 2500 50  0001 C CNN
	1    6975 2500
	-1   0    0    1   
$EndComp
$Comp
L .Connector:Conn_01x01 J?
U 1 1 5D79A432
P 6975 2600
AR Path="/5D79A432" Ref="J?"  Part="1" 
AR Path="/5D795553/5D79A432" Ref="J6"  Part="1" 
F 0 "J6" H 6895 2467 50  0000 C CNN
F 1 "DNL" H 7055 2551 50  0001 L CNN
F 2 ".Connector:Conn_1x1_700_Circular_Pad" H 6975 2600 50  0001 C CNN
F 3 "~" H 6975 2600 50  0001 C CNN
	1    6975 2600
	-1   0    0    1   
$EndComp
Wire Wire Line
	6525 2400 6175 2400
Wire Wire Line
	6525 2500 6175 2500
Wire Wire Line
	6525 2600 6175 2600
Wire Wire Line
	7175 2400 7525 2400
Wire Wire Line
	7175 2500 7525 2500
Wire Wire Line
	7175 2600 7525 2600
$Comp
L power:GND #PWR?
U 1 1 5D79A43E
P 7525 2600
AR Path="/5D79A43E" Ref="#PWR?"  Part="1" 
AR Path="/5D795553/5D79A43E" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 7525 2350 50  0001 C CNN
F 1 "GND" V 7530 2472 50  0000 R CNN
F 2 "" H 7525 2600 50  0001 C CNN
F 3 "" H 7525 2600 50  0001 C CNN
	1    7525 2600
	1    0    0    -1  
$EndComp
$Comp
L power:+1V8 #PWR?
U 1 1 5D79A444
P 6175 2400
AR Path="/5D79A444" Ref="#PWR?"  Part="1" 
AR Path="/5D795553/5D79A444" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 6175 2250 50  0001 C CNN
F 1 "+1V8" V 6190 2528 50  0000 L CNN
F 2 "" H 6175 2400 50  0001 C CNN
F 3 "" H 6175 2400 50  0001 C CNN
	1    6175 2400
	1    0    0    -1  
$EndComp
Text Label 6175 2500 0    50   ~ 0
MOSI
Text Label 6175 2600 0    50   ~ 0
MISO
Text Label 7275 2400 0    50   ~ 0
SCLK
Text Label 7275 2500 0    50   ~ 0
RESET_N_ISP
$Comp
L .Capacitor:GRM155R71A104JA01D C?
U 1 1 5D79A46A
P 2925 1950
AR Path="/5D79A46A" Ref="C?"  Part="1" 
AR Path="/5D795553/5D79A46A" Ref="C1"  Part="1" 
F 0 "C1" H 3017 1996 50  0000 L CNN
F 1 "GRM033R61A104ME15D" H 2535 2120 50  0001 L CNN
F 2 ".Capacitor:C_0201_0603Metric_L" H 2985 2220 50  0001 C CNN
F 3 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM033R61A104ME15-01.pdf" H 2935 2020 50  0001 C CNN
F 4 "0.1uF" H 3017 1905 50  0000 L CNN "Note"
F 5 "0201" H 3035 1770 50  0001 C CNN "Size"
	1    2925 1950
	1    0    0    -1  
$EndComp
Connection ~ 2925 1850
$Comp
L .Connector:Conn_01x01 J?
U 1 1 5D79A471
P 5225 1725
AR Path="/5D79A471" Ref="J?"  Part="1" 
AR Path="/5D795553/5D79A471" Ref="J9"  Part="1" 
F 0 "J9" H 5304 1721 50  0000 L CNN
F 1 "DNL" H 5305 1676 50  0001 L CNN
F 2 ".Connector:Conn_1x1_700_Circular_Pad" H 5225 1725 50  0001 C CNN
F 3 "~" H 5225 1725 50  0001 C CNN
	1    5225 1725
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1725 5025 1725
Text HLabel 4975 3000 2    50   Output ~ 0
MOSI
Text HLabel 4975 3100 2    50   Input ~ 0
MISO
Text HLabel 4975 3700 2    50   Input ~ 0
MONITOR0
Text HLabel 4975 3800 2    50   Output ~ 0
TRIGGER0
Text HLabel 4975 3900 2    50   Output ~ 0
RESET_N
Text HLabel 4975 3200 2    50   Output ~ 0
SCK
Text HLabel 4975 4700 2    50   Output ~ 0
SS_N
Text HLabel 4975 3400 2    50   Output ~ 0
LED
Text HLabel 4975 4000 2    50   BiDi ~ 0
I2C_SDA
Text HLabel 4975 2700 2    50   Output ~ 0
ENT1
Text HLabel 4975 2800 2    50   Output ~ 0
ENT2
Text HLabel 4975 4100 2    50   Input ~ 0
I2C_SCL
Text Label 4325 1725 0    50   ~ 0
ENT2
Wire Notes Line
	5850 1850 5850 2975
Wire Notes Line
	5850 2975 7925 2975
Wire Notes Line
	7925 2975 7925 1850
Wire Notes Line
	7925 1850 5850 1850
Wire Notes Line
	2600 1450 2600 5850
Wire Notes Line
	2600 5850 5450 5850
Wire Notes Line
	5450 5850 5450 1450
Wire Notes Line
	5450 1450 2600 1450
Text Notes 2700 1500 0    50   ~ 0
MCU
Text Notes 5875 1925 0    50   ~ 0
ISP Pogopin Pads
$EndSCHEMATC
