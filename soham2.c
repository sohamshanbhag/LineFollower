#include <avr/io.h>
#include <util/delay.h>

void pwm_init(){
	//TCCR1 to be enabled
	TCCR1A |= (1<< COM1A1)|(1<<COM1B1)|(1<<WGM10);
	TCCR1B |= (1<<WGM12)|(1<<CS10);

	//Enable Pins
	DDRD |= (1<<PD4)|(1<<PD5);
}

void main(){
	uint8_t v_1 = 0, v_2 = 0;
	
	pwm_init();

	uint8_t flag1 = 0, flag2 = 0;

	while(1){
		OCR1A = v_1/15*153;
		OCR1B = v_2/15*153;
//		if (flag1 == 0){
//			v_1++;
//			if (v_1 == 15) flag1 = 1;
//		}else if (flag1 == 1){
//			v_1--;
//			if (v_1 == 0) flag1 = 0;
//		}
//		
//		if (flag2 == 0){
//			v_2++;
//			if (v_2 == 15) flag2 = 1;
//		}else if (flag2 == 1){
//			v_2--;
//			if (v_2 == 0) flag2 = 0;
//		}
		_delay_ms(10);
	}
}
