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
	duty = 0;

	uint8_t flag = 1;

	pwm_init();

	while(1){
		if (flag == 0){
			OCR0 = duty;
			duty--;
			if (duty == 0) {flag = 1;}
			_delay_ms(10);
		} else if (flag == 1){
			OCR0 = duty;
			duty++;
			if (duty == 127) {flag = 0;}
			_delay_ms(10);
		}
	}
}
