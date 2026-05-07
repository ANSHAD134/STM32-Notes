/*
 * Control_Speed_DC motor_Using_PWM.c
 *
 * Created: 07-05-2026 7.19.49 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


void Motor_Speed(void)
{
	uint8_t speed = 64;
	static uint8_t state = 1;
	
	if(!(PIND&(1 << PIND2)))
	{
		_delay_ms(50);							// Debounce delay for Push-button
		
		state++;
		if (state > 4)
		state = 1;
		
		switch(state)
		{
			case 1:
			speed = 64;							// 25% Motor speed
			break;
			
			case 2:
			speed = 128;						// 50% Motor speed
			break;
			
			case 3:
			speed = 192;						// 75% Motor speed
			break;
			
			case 4:
			speed = 255;						// 100% Motor speed
			break;
		}
		OCR0A = speed;
		while(!(PIND&(1 << PIND2)));			// Wait until button released
	}
}

int main(void)
{
	DDRD |= (1 << DDD6);						// Set PD6 for Output Motor
	
	DDRD &= ~(1 << DDD2);						// Set PD2 for Input
	PORTD |= (1 << PORTD2);						// Enable PULL-UP on PD2
	
	TCCR0A |= (1 << COM0A1);					// Non-inverting
	
	TCCR0B |= (1 << CS01) | (1 << CS00);		// Prescalar 64
	TCCR0A |= (1 << WGM00) | (1 << WGM01);		// Fast PWM
	OCR0A = 64;									// Start with 25% Motor speed
	/* Replace with your application code */
	while (1)
	{
		Motor_Speed();
	}
}