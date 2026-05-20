/*
 * Push-button_Toggle_LEDS.c
 *
 * Created: 01-05-2026 8.25.52 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD |= (1 << DDD5);			// Green LED
	DDRD |= (1 << DDD3);			// Red LED
	DDRD &= ~(1 << DDD1);			// Push-Button
	PORTD |= (1 << PORTD1);			// Pull-up
	
	uint8_t state = 1;
	
	PORTD &=~ (1 << PORTD5);		// Set initial GREEN LED is OFF 
	PORTD |= (1 << PORTD3);			// Set initial RED LED is ON
    /* Replace with your application code */
    while (1) 
    {
		if(!(PIND & (1 << PIND1)))
		{
			_delay_ms(50);							// Debounce Delay
			
			if (!(PIND & (1 << PIND1)))
			{
				state = !state;						// Toggle LED state
				
				if(state)
				{
					PORTD |= (1 << PORTD3);			// Set PORTD3 for RED LED ON 
					PORTD &= ~(1 << PORTD5);		// Clear PORTD5 for GREEN LED OFF
				}
				else
				{
					PORTD &= ~(1 << PORTD3);		// Clear PORTD3 for RED LED OFF
					PORTD |= (1 << PORTD5);			// Set PORTD5 for GREEN LED ON
				}
				while (!(PIND & (1 << PIND1)));		// waits until Release the Button
			}
		}
	}
}
