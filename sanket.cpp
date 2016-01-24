#include<avr/io.h>
#define           F_CPU           1000000
#include<util/delay.h>
#include<avr/adc.h>
#define           REF           600

// x1, x2 ,x3 ,x4 to denote ON/OFF for each sensor
int t1=18000,t2=18000;   //dummy  default value
DDRD |= 0b00000011;
TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1B1;
TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10;           //a is left and b is right
ICR1A = 24999;               // freq is 40Hz
ICR1B=24999;                                                     
OCR1A = t1;
OCR1B=t2;




int main(void)
	{
	DDRA=0x00110000 ;
	/*PA1,PA2,PA3 and PA4 pins of PortB are declared output ( i/p1,i/p2,i/p3,i/p4 pins of DC Motor Driver are connected )*/

	int x1=0,x2=0,x3=0,x4=0 ;

	adc_init();

	while(1)
	{
		left_sensor_value=read_adc_channel(0);
		/*Reading left IR sensor value*/
		middle_sensor_value=read_adc_channel(1);
		/*Reading middle IR sensor value*/
		right_sensor_value=read_adc_channel(2);
		/*Reading right IR sensor value*/
		/*Checking the sensor values with the reference value*/

		if( x1<ref1)
		x1=0;
		else if(x1<ref2)
		x1=0.5;
		else
		x1=1;

		if( x2<ref1)
		x2=0;
		else if (x2<ref2)
		x2=0.5;
		else
		x2=1;

		if( x3<ref1)
		x3=0;
		else if (x3<ref2)
		x3=0.5;
		else
		x3=1;

		if( x4<ref1)
		x4=0;
		else if (x4<ref2)
		x4=0.5;
		else
		x4=1;

		value_decider(int x1,int x2,int x3,int x4);

		_delay_ms(100);

	}


	void value_decider(int x1,int x2,int x3,int x4)
	{

	if ((x1==1) && ( x2==0) && (x3==1) && (x4==0))
	{ 
		pwm_set(9,9);
		_delay_ms(3000);
	   
	}

	if ((x1==0.5) && ( x2==0) && (x3==0.5) && (x4==0.5))
	{ 
	   pwm_set(10,8);
	  _delay_ms(10)}
	if ((x1==0) && ( x2==1) && (x3==0) && (x4==0))
	{ 
	   //move right fast slow down left ,, sharp turn
	}

	if ((x1==0.4) && ( x2==0.5) && (x3==0.5) && (x4==0.5))
	{ 
	   //move left slow , right fast
	}

	if ((x1==0) && ( x2==0) && (x3==0) && (x4==1))
	{ 
	   // right fast left slow
	}

	if ((x1==0) && ( x2==1) && (x3==1) && (x4==1))
	{ 
	   //move left or right sharp turn 
	}

	if ((x1==1) && ( x2==0) && (x3==1) && (x4==0))
	{ 
	   //move forward
	}

	if ((x1==0.5) && ( x2==0) && (x3==0.5) && (x4==0))
	{ 
	   //move forward
	}

	if ((x1==0) && ( x2==0) && (x3==1) && (x4==1))
	{ 
	   //right slow left fast
	}

	if ((x1==1) && ( x2==1) && (x3==0) && (x4==0))
	{ 
	   //left slow right fast 
	}

	if ((x1==1) && ( x2==1) && (x3==1) && (x4==1))
	{ 
	   //move forward
	}
}

pwm_set(t1,t2)
{
	OCR1A=24999-t1/12*25000;
	OCR1B=24999-t2*25000/12;
}

