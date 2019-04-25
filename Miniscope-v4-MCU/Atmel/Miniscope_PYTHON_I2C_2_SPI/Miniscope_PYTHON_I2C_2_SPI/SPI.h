/*
 * SPI.h
 *
 * Created: 7/21/2018 6:55:47 PM
 *  Author: DBAharoni
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "definitions"

//For ATMEGA328P

void init_SPI() {
	
	//SPI_DDR = 0x00;
	// Set MOSI and SCK as output, MISO as input
	//Set SS as output so SPIF cannot get reset
	SPI_DDR |= (1<<MOSI)|(1<<SCK)|(1<<SS);//|(1<<RTS);
	SPI_SS_DDR |= (1<<SS);
	SPI_DDR &= ~(1<<MISO);
	//SPI_PORT |= (1<<RTS);
	//Enable SPI by SPE=1, set uC as Master
	//Sets Data order, 0 for MSB transmitted first
	//Other bits of SPCR set clock config
	//CPOL =1 sets the clock output to high when idle
	//CPHA = 1 sample on trailing edge of clock. This is dependent on CPOL
	//SPR1 and 0 affect clock freq.
	SPCR = (1<<SPE)|(1<<MSTR)|(0<<DORD)|(1<<CPOL)|(1<<CPHA)|(0<<SPR1)|(1<<SPR0);
	//Set clock rate, fck/2 (maximum)
	//More clock rates can be made using last 2 bits in SPCR
}

void SPI_Write(unsigned char dataout) {
	unsigned char dump;
	
	// Start transmission (MOSI)
	SPDR = dataout;
	// Wait for trans to complete
	while(!(SPSR & (1<<SPIF))) {
		//         USART_Transmit(0x11);
	}
	
	
	dump = SPDR;
}

unsigned char SPI_Read() {
	unsigned char word;
	//Start receiving (MISO)
	SPDR = 0xFF;
	
	while(!(SPSR & (1<<SPIF))) {
		//      USART_Transmit(0x22);
	}
	//  _delay_us(10); //Not sure if this helps any
	word = SPDR;
	return word;
	
}


#endif /* SPI_H_ */