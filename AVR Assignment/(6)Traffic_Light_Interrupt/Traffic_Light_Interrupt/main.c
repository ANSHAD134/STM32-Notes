/*
 * Traffic_Light_Interrupt.c
 *
 * Created: 04-05-2026 7.28.32 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t flag = 0;

// Interrupt service routine for INT0
ISR(INT0_vect)
{
	flag = 1;
}


int main(void)
{
	DDRB |= (1 << DDB0);						// Set Output for GREEN LED
	DDRB |= (1 << DDB1);						// Set Output for ORANGE LED
	DDRB |= (1 << DDB2);						// Set Output for RED LED
	
	DDRD &= ~(1 << DDD2);						// Set Input for Push-Button
	PORTD |= (1 << PORTD2);						// Enable internal Pull-up
	
	EIMSK |= (1 << INT0);						// Enable INT0 at EIMSK Register
	EICRA |= (1 << ISC01);						// Enable Falling edge detection in EICRA Register
	sei();										// Enable global Interrupt 
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB = (1 << PORTB0);					// GREEN LED For High
		_delay_ms(10000);						// 10 second delay
		
		if(flag)
		{
			PORTB = (1 << PORTB0);				// Priority GREEN
			_delay_ms(5000);					// 5 second delay
			flag = 0;
			continue;
		}
			
		PORTB = (1 << PORTB1);					// ORANGE LED For High
		_delay_ms(3000);						// 3 second delay
		
		if(flag)
		{
			PORTB = (1 << PORTB0);				// Priority GREEN
			_delay_ms(5000);					// 5 second delay
			flag = 0;
			continue;
		}
			
			
		PORTB = (1 << PORTB2);					// RED LED For High
		_delay_ms(10000);						// 10 second delay
		
		if(flag)
		{
			PORTB = (1 << PORTB0);				// Priority GREEN
			_delay_ms(5000);					// 5 second delay
			flag = 0;
		}
    }
}

