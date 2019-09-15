/*
 * Miniscope_PYTHON_I2C_2_SPI.c
 *
 * Created: 7/21/2018 6:34:01 PM
 * Author : DBAharoni
 */ 

// ----- USER DEFINED CONFIG (SELECT ONE) ------
#define DUAL_LED_MINISCOPE
//#define V4_MINISCOPE
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

volatile uint8_t pastI2CWord = 0;
volatile uint8_t data;
volatile uint8_t previousLED = 1;
volatile uint8_t ledValue1 = 0;
volatile uint8_t ledValue2 = 0;

void I2C_received(uint8_t received_data)
{
// The switch function below becomes effective once 2 bytes have been received over I2C
// pastI2CWord acts as the "write reg" and received_data act as the value being written
	switch (pastI2CWord) {
		case (SET_LED1_VALUE):
			OCR0A = received_data;
			ledValue1 = received_data;
			LED_ENT_PORT |= (1<<LED_ENT1_PIN); //Make sure ENT pin is on
			if (received_data == 0) 
				LED_ENT_PORT &= ~(1<<LED_ENT1_PIN); //Set ENT pin to off
			pastI2CWord = 0; //Idle state
			break;
		case (SET_LED2_VALUE):
			OCR0B = received_data;
			ledValue2 = received_data;
			LED_ENT_PORT |= (1<<LED_ENT2_PIN); //Make sure ENT pin is on
			if (received_data == 0) 
				LED_ENT_PORT &= ~(1<<LED_ENT2_PIN); //Set ENT pin to off
			pastI2CWord = 0; //Idle state
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
			pastI2CWord = 0; //Idle state
			break;
		default:
			pastI2CWord = received_data;
			break;
	}
}

void I2C_requested()
{
	I2C_transmitByte(data);
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
		LED_ENT_PORT |= (1<<LED_ENT1_PIN);
	if (LEDNum&0x02)
		LED_ENT_PORT |= (1<<LED_ENT2_PIN);
}
void disableLED(uint8_t LEDNum) {
	if (LEDNum&0x01)
		LED_ENT_PORT &= ~(1<<LED_ENT1_PIN);
	if (LEDNum&0x02)
		LED_ENT_PORT &= ~(1<<LED_ENT2_PIN);
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
	LED_ENT_DDR |= (1<<LED_ENT1_PIN)|(1<<LED_ENT2_PIN);
	LED_ENT_PORT |= (0<<LED_ENT1_PIN)|(0<<LED_ENT2_PIN);
	
	
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
	initBoard();
	initPWM();
    setup_I2C();
	initExtInt(); // For Monitor0 pin
	sei(); // This is also called in setup_I2C but putting this here as well just in case setup_I2C gets removed at some point
	RESET_N_PORT |= (1<<RESET_N_PIN);
	//_delay_us(20); // Min delay of 10us
	_delay_ms(1); // Min delay of 10us
	init_PYTHON480();
	updatePWM1(50);
	enableLED(1);
	LED_PORT |= (1<<LED_PIN);
    while (1) 
    {

    }
}
ISR(PCINT1_vect) //Interrupt for PCINT[14:8]. Will be triggered when a pin toggles
{
	// If more than 1 pin can trigger this interrupt then we need to save previous state and make a more complex if/else statement below
	if ((MONITOR_PORT>>MONITOR0_PIN) & 0x01) {
		// Monitor0 went high which is the start of frame integration
		#ifdef DUAL_LED_MINISCOPE
			if (previousLED == 1) {
				// LED1 was previously one
				if (ledValue2 != 0)
					LED_ENT_PORT |= (1<<LED_ENT2_PIN);
				previousLED = 2;
			}
			else {
				// LED2 was previously one
				if (ledValue1 != 0)
					LED_ENT_PORT |= (1<<LED_ENT1_PIN);
				previousLED = 1;
			}
		#endif
		#ifdef V4_MINISCOPE
			if (ledValue1 != 0)
				LED_ENT_PORT |= (1<<LED_ENT1_PIN)
		#endif
		
	}
	else {
		// Monitor0 went low which is end of frame integration. Let's turn off all LEDs during this time
		LED_ENT_PORT &= ~((1<<LED_ENT1_PIN)|(1<<LED_ENT2_PIN));
	}
}

