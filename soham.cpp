#include <avr/io.h>
#include <util/delay.h>
void pwm_init(){
	//Initialize TCCR0
	TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00);

	//PB3 is OC0 pin for atmega 32
	DDRB |= (1<<PB3);
}

void main(){
	uint8_t duty;
	duty = 127;

	pwm_init();

	while(1){
		OCR0 = duty;
	}
}
