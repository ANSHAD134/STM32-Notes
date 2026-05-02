/*
 * LED_Train_animation.c
 *
 * Created: 02-05-2026 6.41.57 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB |= (1 << DDB0);					// Set PORT0 as OUTPUT
	DDRB |= (1 << DDB1);					// Set PORT1 as OUTPUT
	DDRB |= (1 << DDB2);					// Set PORT2 as OUTPUT
	DDRB |= (1 << DDB3);					// Set PORT3 as OUTPUT
	DDRB |= (1 << DDB4);					// Set PORT4 as OUTPUT
	DDRB |= (1 << DDB5);					// Set PORT5 as OUTPUT
	DDRB |= (1 << DDB6);					// Set PORT6 as OUTPUT
	DDRB |= (1 << DDB7);					// Set PORT7 as OUTPUT
	
    /* Replace with your application code */
    while (1) 
    {
		for(uint8_t i=0; i<8; i++)
		{
			PORTB &= ~(1 << PORTB0);			// Clear 1st LED
			PORTB &= ~(1 << PORTB1);			// Clear 2nd LED
			PORTB &= ~(1 << PORTB2);			// Clear 3rd LED
			PORTB &= ~(1 << PORTB3);			// Clear 4th LED
			PORTB &= ~(1 << PORTB4);			// Clear 5th LED
			PORTB &= ~(1 << PORTB5);			// Clear 6th LED
			PORTB &= ~(1 << PORTB6);			// Clear 7th LED
			PORTB &= ~(1 << PORTB7);			// Clear 8th LED
			
			PORTB |= (1 << i);					// Turns ON current LED
			
			_delay_ms(200);						// 200ms delay
		}
    }
}

