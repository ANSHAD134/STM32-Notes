/*
 * LEDs_display_4-bit binary.c
 *
 * Created: 02-05-2026 7.11.08 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


void display(uint8_t value)
{
	if (value & (1 << 0))
	{
		PORTB |= (1 << PORTB0);
	}
	else
	{
		PORTB &= ~(1 << PORTB0);
	}
	
	if (value & (1 << 1))
	{
		PORTB |= (1 << PORTB1);
	}
	else
	{
		PORTB &= ~(1 << PORTB1);
	}

	if (value & (1 << 2))
	{
		PORTB |= (1 << PORTB2);
	}
	else
	{
		PORTB &= ~(1 << PORTB2);
	}

	if (value & (1 << 3))
	{
		PORTB |= (1 << PORTB3);
	}
	else
	{
		PORTB &= ~(1 << PORTB3);
	}
}

int main(void)
{
	DDRB |= (1 << DDB0);					// PORTB0 set as OUTPUT
	DDRB |= (1 << DDB1);					// PORTB1 set as OUTPUT
	DDRB |= (1 << DDB2);					// PORTB2 set as OUTPUT
	DDRB |= (1 << DDB3);					// PORTB3 set as OUTPUT
	
	DDRD &= ~(1 << DDD2);					// PORTD2 set as INPUT for Push-Button
	PORTD |= (1 << PORTD2);					// Set Pull-up for Push-Button
	
	uint8_t count = 0;
	
	display(count);
	
    /* Replace with your application code */
    while (1) 
    {
		if(!(PIND & (1 << PIND2)))
		{
			_delay_ms(50);					// Debounce delay
		
			if(!(PIND & (1 << PIND2)))
			{
				count++;
				if(count > 15)
				{	
					count=0;
				}
			
				display(count);
			
				while(!(PIND & (1 << PIND2)));	// Wait for until Release
				_delay_ms(50);
			}
		}
    }
}

