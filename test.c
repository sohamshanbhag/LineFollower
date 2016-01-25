#include <avr/io.h>
#include <util/delay.h>

void main(){
	DDRD = (1<<4)|(1<<5);

	while(1){
		PORTD = (1<<4)|(1<<5);
	}
}
