/*
 * Miniscope_PYTHON_I2C_2_SPI.c
 *
 * Created: 7/21/2018 6:34:01 PM
 * Author : DBAharoni
 */ 

// ----- USER DEFINED CONFIG (SELECT ONE) ------
//#define DUAL_LED_MINISCOPE
//#define DUAL_LED_MINISCOPE_DEMO
#define V4_MINISCOPE
// ---------------------------------------------
#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "I2CSlave.h"
#include "definitions.h"
#include "PYTHON480.h"
#include "SPI_BB_PYTHON480.h"

#define I2C_ADDR 0x10

volatile uint8_t pastI2CWord = NO_WORD;
volatile uint8_t i2c_return_data;
volatile uint8_t previousLED = 1;
volatile uint8_t ledValue1 = 0xFF;
volatile uint8_t ledValue2 = 255;

volatile uint8_t ms_mode = 0;

// for i2c passthrough to spi
volatile uint16_t reg = 0;
volatile uint16_t value = 0;
volatile uint8_t bytesReceived;


void I2C_received(uint8_t received_data)
{
// The switch function below becomes effective once 2 bytes have been received over I2C
// pastI2CWord acts as the "write reg" and received_data act as the value being written
	switch (pastI2CWord) {
		case (NO_WORD):
			switch(received_data) {
				case(GET_PID):
					// Product ID
					i2c_return_data = PID;
					break;
				case(GET_VID):
					// Vendor ID
					i2c_return_data = VID;
					break;
				case(GET_FIRM_VER):
					// Firmware Version
					i2c_return_data = FIRM_VER;
					break;
				default:
					// This gets called and saves the byte after address into pastI2CWord
					pastI2CWord = received_data;
					bytesReceived = 0;
					break;
			}
			
			break;			
		case (I2C_PYTHON_PASSTHROUGH):
			switch (bytesReceived) {
				case (0):
					reg = ((uint16_t)received_data)<<8;
					bytesReceived++;
					break;
				case (1):
					reg |= ((uint16_t)received_data);
					bytesReceived++;
					break;
				case (2):
					value = ((uint16_t)received_data)<<8;
					bytesReceived++;
					break;
				case (3):
					value |= ((uint16_t)received_data);
					spi_BB_Write(reg, value);
					pastI2CWord = NO_WORD;
					reg = 0;
					value = 0;
					bytesReceived = 0;
					break;	
			}
				
			break;
		case (SET_LED1_STATE):
			OCR0A = received_data;
			ledValue1 = received_data;
							
			if (received_data == 0xFF)
				LED_ENT1_PORT &= ~(1<<LED_ENT1_PIN); //Set ENT pin to off
			else
				LED_ENT1_PORT |= (1<<LED_ENT1_PIN); //Make sure ENT pin is on
			pastI2CWord = NO_WORD; //Idle state
			break;
		case (SET_LED2_STATE):
			OCR0B = received_data;
			ledValue2 = received_data;
			if (received_data == 0xFF)
				LED_ENT2_PORT &= ~(1<<LED_ENT2_PIN); //Set ENT pin to off
			else
				LED_ENT2_PORT |= (1<<LED_ENT2_PIN); //Make sure ENT pin is on
			pastI2CWord = NO_WORD; //Idle state
			break;
		case (SET_STATUS_LED_STATE):
			if (received_data == 0)
				LED_PORT &= ~(1<<LED_PIN);
			else
				LED_PORT |= (1<<LED_PIN);
			pastI2CWord = NO_WORD; //Idle state
			break;
		case (SET_GAIN_VALUE):
			switch (received_data) {
				case (GAIN_1):
					spi_BB_Write(204, 0x00E1);
					break;
				case (GAIN_2):
					spi_BB_Write(204, 0x00E4);
					break;
				case (GAIN_3_5):
					spi_BB_Write(204, 0x0024);
					break;
			}
			pastI2CWord = NO_WORD; //Idle state
			break;
		case (SET_MODE):
			switch (received_data) {
				case (MODE_V4_MINISCOPE):
					ms_mode = MODE_V4_MINISCOPE;
					break;
				case (MODE_2_COLOR):
					ms_mode = MODE_2_COLOR;
					break;
				case (MODE_DEMO_2_COLOR):
					ms_mode = MODE_DEMO_2_COLOR;
					break;
			}
			pastI2CWord = NO_WORD; //Idle state
			break;
		default:
			// This portion should no longer get called. This is now handled in the NO_WORD case at the top
			pastI2CWord = received_data;
			bytesReceived = 0;
			break;
	}
}

void I2C_requested()
{
	I2C_transmitByte(i2c_return_data);
}

void setup_I2C()
{
	// set received/requested callbacks
	I2C_setCallbacks(I2C_received, I2C_requested);

	// init I2C
	I2C_init(I2C_ADDR);
}

void initPWM() {
	DDRD |= (1<<PWM1_PIN)|(1<<PWM2_PIN); //Set PWM pins as output
	TCCR0A = (1<<COM0A1)|(1<<WGM01)|(1<<WGM00); //Clear on compare match. Fast PWM Mode 
	TCCR0B = (0<<WGM02)|(0<<CS02)|(0<<CS01)|(1<<CS00); //Clock select. No prescaler
	TCNT0 = 0; //TC0 Counter Value
	OCR0A = 12; //TC0 Output Compare Register A
	OCR0B = 127; //TC0 Output Compare Register B
}

void updatePWM1(uint8_t newValue) {
	OCR0A = newValue;
}
void updatePWM2(uint8_t newValue) {
	OCR0B = newValue;
}

void enableLED(uint8_t LEDNum) {
	if (LEDNum&0x01)
		LED_ENT1_PORT |= (1<<LED_ENT1_PIN);
	if (LEDNum&0x02)
		LED_ENT2_PORT |= (1<<LED_ENT2_PIN);
}
void disableLED(uint8_t LEDNum) {
	if (LEDNum&0x01)
		LED_ENT1_PORT &= ~(1<<LED_ENT1_PIN);
	if (LEDNum&0x02)
		LED_ENT2_PORT &= ~(1<<LED_ENT2_PIN);
}

void init_PYTHON480() {
	// Sets up initial register values in the PYTHON 480
	EnableClockMngmnt1();
	//Maybe a small pause here for things to stabilize
	_delay_ms(10);
	EnableClockMngmnt2();
	RequiredUploads();
	SoftPowerUp();

	//EnableSeq(); //Not sure if this is good or not
}

void initBoard() {
	// Setup SPI
	SPI_DDR |= (1<<MOSI)|(1<<SCK)|(1<<SS);//|(1<<RTS);
	SPI_SS_DDR |= (1<<SS);
	SPI_DDR &= ~(1<<MISO);
	
	SPI_SS_PORT |= (1<<SS); //Pull SS high
	SPI_PORT &= ~(1<<SCK);
	
	// Setup status LED
	LED_DDR |= (1<<LED_PIN);
	LED_PORT &= ~(1<<LED_PIN);
	
	// Setup excitation LED
	LED_ENT1_DDR |= (1<<LED_ENT1_PIN);
	LED_ENT1_PORT &= ~(0<<LED_ENT1_PIN);
	
	LED_ENT2_DDR |= (1<<LED_ENT2_PIN);
	LED_ENT2_PORT &= ~(0<<LED_ENT2_PIN);
	
	
	// Setup pins connecting to PYTHON480
	RESET_N_DDR |= (1<<RESET_N_PIN);
	RESET_N_PORT &= ~(1<<RESET_N_PIN);
	
	MONITOR_DDR &= ~(1<<MONITOR0_PIN); // Input

	
	
}
void initExtInt() {
	PCICR |= (1<<PCIE1); // Enable PCI1
	PCMSK1 |= (1<<PCINT9); //Enable mask for PCINT9
}

int main(void)
{
	#ifdef DUAL_LED_MINISCOPE
	ms_mode = MODE_DEMO_2_COLOR;
	#else
	ms_mode = MODE_V4_MINISCOPE;
	#endif
	
	double flashDelay = 500;	
	
	initBoard();
	// initPWM();
    setup_I2C();
	initExtInt(); // For Monitor0 pin
	sei(); // This is also called in setup_I2C but putting this here as well just in case setup_I2C gets removed at some point
	RESET_N_PORT |= (1<<RESET_N_PIN);
	//_delay_us(20); // Min delay of 10us
	_delay_ms(1); // Min delay of 10us
	init_PYTHON480();
	//updatePWM1(50);
	enableLED(1);
	disableLED(0x03);
	
	LED_PORT |= (1<<LED_PIN);
    while (1)
    {
		if (ms_mode == MODE_DEMO_2_COLOR) {
			enableLED(0x01);
			_delay_ms(flashDelay);
			disableLED(0x01);
			enableLED(0x02);
			_delay_ms(flashDelay);
			disableLED(0x02);
			_delay_ms(10);
			enableLED(0x03);
			_delay_ms(flashDelay);
			disableLED(0x03);
			_delay_ms(flashDelay/2);
		}
    }
}
ISR(PCINT1_vect) //Interrupt for PCINT[14:8]. Will be triggered when a pin toggles
{
	if (ms_mode != MODE_DEMO_2_COLOR) {
		// If more than 1 pin can trigger this interrupt then we need to save previous state and make a more complex if/else statement below
		if ((MONITOR_PIN>>MONITOR0_PIN) & 0x01) {
			// Monitor0 went high which is the start of frame integration
			if (ms_mode == MODE_2_COLOR) {
				if (previousLED == 1) {
					// LED1 was previously one
					if (ledValue2 != 0)
						LED_ENT1_PORT |= (1<<LED_ENT2_PIN);
					previousLED = 2;
				}
				else {
					// LED2 was previously one
					if (ledValue1 != 0)
						LED_ENT1_PORT |= (1<<LED_ENT1_PIN);
					previousLED = 1;
				}
			}
			if (ms_mode == MODE_V4_MINISCOPE) {
				if (ledValue1 < 0xFF)
					LED_ENT1_PORT |= (1<<LED_ENT1_PIN);
				if (ledValue2 < 0xFF)
					LED_ENT2_PORT |= (1<<LED_ENT2_PIN);
			}
		}
		else {
			// Monitor0 went low which is end of frame integration. Let's turn off all LEDs during this time
			LED_ENT1_PORT &= ~(1<<LED_ENT1_PIN);
			LED_ENT2_PORT &= ~(1<<LED_ENT2_PIN);
		}
	}
}

