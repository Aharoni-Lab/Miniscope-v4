/*
 * SPI_BB_PYTHON480.h
 *
 * Created: 7/21/2018 9:49:03 PM
 *  Author: DBAharoni
 */ 


#ifndef SPI_BB_PYTHON480_H_
#define SPI_BB_PYTHON480_H_

#include "definitions.h"

uint16_t spi_BB_Read(uint16_t address) {
	//Bitbang SPI Master.
	//Assuming SS starts high and clock starts low
	
	int8_t i = 0;
	uint16_t value = 0;
	SPI_SS_PORT &= ~(1<<SS);
	
	for (i=8; i >=0 ;i--) { // 9bit address
		SPI_PORT &= ~(1<<SCK);
		// Set MOSI pin to next bit value
		if (0x0001&(address>>i)) //a 1
			SPI_PORT |= (1<<MOSI);
		else // a 0
			SPI_PORT &= ~(1<<MOSI);
		
		_delay_us(10);
		
		SPI_PORT |= (1<<SCK);
		_delay_us(10);
	}
	//_delay_us(100);
	// Read bit
	SPI_PORT &= ~(1<<SCK);
	SPI_PORT &= ~(1<<MOSI);
	_delay_us(10);
	SPI_PORT |= (1<<SCK);
	_delay_us(10);
	SPI_PORT &= ~(1<<SCK);
	_delay_us(10);
	SPI_PORT |= (1<<SCK);
	_delay_us(10);
	
	// Value
	for (i=15; i >=1 ;i--) {
		SPI_PORT &= ~(1<<SCK);
		value |= (0x01&(SPI_PORT>>MISO))<<i;

		_delay_us(10);
		
		SPI_PORT |= (1<<SCK);
		_delay_us(10);
	}
	
	SPI_PORT &= ~(1<<SCK);
	value |= (0x01&(SPI_PORT>>MISO));
	_delay_us(10);
	SPI_SS_PORT |= (1<<SS);
	return value;
}

void spi_BB_Write(uint16_t address, uint16_t value) {
	//Bitbang SPI Master.
	//Assuming SS starts high and clock starts low
	
	int8_t i = 0;
	
	SPI_SS_PORT &= ~(1<<SS);
	
	for (i=8; i >=0 ;i--) { // 9bit address
		SPI_PORT &= ~(1<<SCK);
		// Set MOSI pin to next bit value
		if (0x0001&(address>>i)) //a 1
		SPI_PORT |= (1<<MOSI);
		else // a 0
		SPI_PORT &= ~(1<<MOSI);
		
		_delay_us(10);
		
		SPI_PORT |= (1<<SCK);
		_delay_us(10);
	}
	//_delay_us(100);
	// Write bit
	SPI_PORT &= ~(1<<SCK);
	SPI_PORT |= (1<<MOSI);
	_delay_us(10);
	SPI_PORT |= (1<<SCK);
	_delay_us(10);
	
	// Value
	for (i=15; i >=0 ;i--) {
		SPI_PORT &= ~(1<<SCK);
		// Set MOSI pin to next bit value
		if (0x0001&(value>>i)) //a 1
			SPI_PORT |= (1<<MOSI);
		else // a 0
			SPI_PORT &= ~(1<<MOSI);
		
		_delay_us(10);
		
		SPI_PORT |= (1<<SCK);
		_delay_us(10);
	}
	
	SPI_PORT &= ~(1<<SCK);
	_delay_us(10);
	SPI_SS_PORT |= (1<<SS);
}

#endif /* SPI_BB_PYTHON480_H_ */