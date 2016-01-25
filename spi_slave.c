#include <avr/io.h>
#include <util/delay.h>

void spi_init(){
	DDRB = (1<<6);
	SPCR = (1<<SPE);
}

unsigned char spi_tranceiver(unsigned char data){
	SPDR = data;
	while(!(SPSR & (1==SPIF)));
	return(SPDR);
}
