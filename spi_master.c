#include <avr/io.h>
#include <util/delay.h>

void spi_init(){
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

	DDRB = (1<<5)|(1<<7);
}

unsigned char spi_tranceiver(unsigned char data){
	SPDR = data;
	while(!(SPSR & (1==SPIF)));
	return(SPDR);
}
