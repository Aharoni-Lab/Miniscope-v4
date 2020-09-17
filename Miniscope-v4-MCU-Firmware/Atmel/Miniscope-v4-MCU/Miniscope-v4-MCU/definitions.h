/*
 * definitions.h
 *
 * Created: 7/21/2018 9:03:41 PM
 *  Author: DBAharoni
 */ 


#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

// =========== SPI ==============================
#define SPI_PORT        PORTB
#define SPI_SS_PORT		PORTD
#define SPI_DDR         DDRB
#define SPI_SS_DDR		DDRD
#define MOSI            PB3
#define MISO            PB4
#define SCK             PB5
#define SS              PD3

// =========== OTHER ==========
#define	LED_PORT		PORTB
#define LED_DDR			DDRB
#define LED_PIN			PB7

#define LED_ENT1_PORT	PORTB
#define LED_ENT1_DDR	DDRB
#define LED_ENT1_PIN	PB0
#define LED_ENT2_PORT	PORTD
#define LED_ENT2_DDR	DDRD
#define LED_ENT2_PIN	PD5

#define PWM_PORT		PORTD
#define PWM_DDR			DDRD
#define PWM1_PIN		PD6 //OC0A
#define PWM2_PIN		PD5

// =========== For PYTHON ======
#define RESET_N_PORT	PORTC
#define RESET_N_DDR		DDRC
#define RESET_N_PIN		PC3

#define MONITOR_PORT	PORTC
#define MONITOR_PIN		PINC
#define MONITOR_DDR		DDRC
#define MONITOR0_PIN	PC1

#define TRIGGER0_PORT	PORTC
#define TRIGGER0_DDR		DDRC
#define TRIGGER0_PIN	PC2
// ==== Firmware Version ====
#define FIRMWARE_VERSION			0x11 //0x10

// === Product IDs ===========
#define PID_V4_MINISCOPE			0x40 // Product ID (0x40 for original production V4 Miniscope)

// ==== Vendor IDs ============
#define VID_OTHER					0x10
#define VID_AHARONI_LAB				0x11
#define VID_OEPS					0x12
#define VID_LABMAKER				0x13

// ========= I2C COMMANDS ====
// No 0x00 values

#define NO_WORD						0x00
#define SET_LED1_STATE				0x01
#define SET_LED2_STATE				0x02
#define SET_GAIN_VALUE				0x03
#define SET_MODE					0x04
#define I2C_PYTHON_PASSTHROUGH		0x05
#define SET_STATUS_LED_STATE		0x06

#define GET_PID						0xF0
#define GET_VID						0xF1
#define GET_FIRM_VER				0xF2

// ======= I2C ID Values ======
#define PID							PID_V4_MINISCOPE 
#define VID							VID_AHARONI_LAB //VID_OTHER
#define FIRM_VER					FIRMWARE_VERSION

// ======= I2C GAIN VALUES ====
#define GAIN_1			0x01
#define GAIN_2			0x02
#define GAIN_3_5		0x03

// ======== I2C MODE VALUES ====
#define MODE_V4_MINISCOPE			0x00
#define MODE_DEMO_2_COLOR			0x01
#define MODE_2_COLOR				0x02
#define MODE_V4_MINISCOPE_CONST_LED	0x03



#endif /* DEFINITIONS_H_ */