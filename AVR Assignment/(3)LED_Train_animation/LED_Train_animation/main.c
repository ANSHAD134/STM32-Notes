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
	DDRB |= (1 << DDD6);					// Set PORT6 as OUTPUT
	DDRB |= (1 << DDD7);					// Set PORT7 as OUTPUT
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB &= ~(1 << PORTB1);
		PORTB |=  (1 << PORTB0);
		_delay_ms(200);
		PORTB &= ~(1 << PORTB0);
		
		PORTB &= ~(1 << PORTB2);
		PORTB |=  (1 << PORTB1);
		_delay_ms(200);
		PORTB &= ~(1 << PORTB1);
		
		PORTB &= ~(1 << PORTB3);
		PORTB |=  (1 << PORTB2);
		_delay_ms(200);
		PORTB &= ~(1 << PORTB2);
		
		PORTB &= ~(1 << PORTB4);
		PORTB |=  (1 << PORTB3);
		_delay_ms(200);
		PORTB &= ~(1 << PORTB3);
		
		PORTB &= ~(1 << PORTB5);
		PORTB |=  (1 << PORTB4);
		_delay_ms(200);
		PORTB &= ~(1 << PORTB4);
		
		PORTD &= ~(1 << PORTD6);
		PORTB |=  (1 << PORTB5);
		_delay_ms(200);
		PORTB &= ~(1 << PORTB5);

		PORTD &= ~(1 << PORTD7);
		PORTD |=  (1 << PORTD6);
		_delay_ms(200);
		PORTD &= ~(1 << PORTD6);
		
		PORTD |=  (1 << PORTD7);
		_delay_ms(200);
		PORTD &= ~(1 << PORTD7);
    }
}

