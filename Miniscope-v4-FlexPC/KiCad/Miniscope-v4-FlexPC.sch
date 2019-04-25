EESchema Schematic File Version 4
LIBS:Miniscope-v4-FlexPC-cache
EELAYER 29 0
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
L Connector_Generic:Conn_01x20 J1
U 1 1 5C423782
P 1600 2000
F 0 "J1" H 1950 2100 50  0000 C CNN
F 1 "Conn_01x20" H 1925 2000 50  0000 C CNN
F 2 ".Connector:B2B_Flex_20_Dual_Row_38milx24mil_Hole_10milx20mil" H 1600 2000 50  0001 C CNN
F 3 "~" H 1600 2000 50  0001 C CNN
	1    1600 2000
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x20 J2
U 1 1 5C4237CC
P 2250 2000
F 0 "J2" H 2330 1992 50  0000 L CNN
F 1 "Conn_01x20" H 2330 1901 50  0000 L CNN
F 2 ".Connector:B2B_Flex_20_Dual_Row_38milx24mil_Hole_10milx20mil" H 2250 2000 50  0001 C CNN
F 3 "~" H 2250 2000 50  0001 C CNN
	1    2250 2000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x14 J?
U 1 1 5CC82349
P 4200 2100
F 0 "J?" H 4350 2150 50  0000 L CNN
F 1 "Conn_01x14" H 4325 2050 50  0000 L CNN
F 2 ".Connector:B2B_Flex_14_Dual_Row_38milx24mil_Hole_10milx20mil" H 4200 2100 50  0001 C CNN
F 3 "~" H 4200 2100 50  0001 C CNN
	1    4200 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x14 J?
U 1 1 5CC847F7
P 3550 2100
F 0 "J?" H 3750 2200 50  0000 C CNN
F 1 "Conn_01x14" H 3875 2075 50  0000 C CNN
F 2 ".Connector:B2B_Flex_14_Dual_Row_38milx24mil_Hole_10milx20mil" H 3550 2100 50  0001 C CNN
F 3 "~" H 3550 2100 50  0001 C CNN
	1    3550 2100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3750 1500 4000 1500
Wire Wire Line
	3750 1600 4000 1600
Wire Wire Line
	3750 1700 4000 1700
Wire Wire Line
	3750 1800 4000 1800
Wire Wire Line
	3750 1900 4000 1900
Wire Wire Line
	3750 2000 4000 2000
Wire Wire Line
	3750 2100 4000 2100
Wire Wire Line
	3750 2200 4000 2200
Wire Wire Line
	3750 2300 4000 2300
Wire Wire Line
	3750 2400 4000 2400
Wire Wire Line
	3750 2500 4000 2500
Wire Wire Line
	3750 2600 4000 2600
Wire Wire Line
	3750 2700 4000 2700
Wire Wire Line
	3750 2800 4000 2800
Wire Wire Line
	1800 2300 2050 2300
Wire Wire Line
	1800 2400 2050 2400
Wire Wire Line
	1800 2500 2050 2500
Wire Wire Line
	1800 2600 2050 2600
Wire Wire Line
	1800 2700 2050 2700
Wire Wire Line
	1800 2800 2050 2800
Wire Wire Line
	1800 2900 2050 2900
Wire Wire Line
	1800 3000 2050 3000
Wire Wire Line
	1800 1500 2050 1500
Wire Wire Line
	1800 1600 2050 1600
Wire Wire Line
	1800 1700 2050 1700
Wire Wire Line
	1800 1800 2050 1800
Wire Wire Line
	1800 1900 2050 1900
Wire Wire Line
	1800 2000 2050 2000
Wire Wire Line
	1800 2100 2050 2100
Wire Wire Line
	1800 2200 2050 2200
Wire Wire Line
	1800 1100 2050 1100
Wire Wire Line
	1800 1200 2050 1200
Wire Wire Line
	1800 1300 2050 1300
Wire Wire Line
	1800 1400 2050 1400
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5CC945E9
P 6250 2050
F 0 "J?" H 6475 2100 50  0000 L CNN
F 1 "Conn_01x05" H 6330 2001 50  0000 L CNN
F 2 ".Connector:B2B_Flex_05_Dual_Row_38milx24mil_Hole_20mil" H 6250 2050 50  0001 C CNN
F 3 "~" H 6250 2050 50  0001 C CNN
	1    6250 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5CC950E2
P 5600 2050
F 0 "J?" H 5925 2075 50  0000 C CNN
F 1 "Conn_01x05" H 5900 1975 50  0000 C CNN
F 2 ".Connector:B2B_Flex_05_Dual_Row_38milx24mil_Hole_20mil" H 5600 2050 50  0001 C CNN
F 3 "~" H 5600 2050 50  0001 C CNN
	1    5600 2050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5800 1850 6050 1850
Wire Wire Line
	5800 1950 6050 1950
Wire Wire Line
	5800 2050 6050 2050
Wire Wire Line
	5800 2150 6050 2150
Wire Wire Line
	5800 2250 6050 2250
Text Notes 1600 975  0    50   ~ 0
SER-POW to CMOS
Text Notes 3575 1325 0    50   ~ 0
CMOS to MCU
Text Notes 5625 1675 0    50   ~ 0
MCU to LED_ETL
$EndSCHEMATC
