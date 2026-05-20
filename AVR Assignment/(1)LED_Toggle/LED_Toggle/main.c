/*
 * LED_Toggle.c
 *
 * Created: 01-05-2026 7.39.02 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD |= (1 << DDD5);
    /* Replace with your application code */
    while (1) 
    {
		PORTD |= (1 << PORTD5);				// Set PORTB5 for LED ON
		_delay_ms(3000);					// 3 seconds Delay
		PORTD &=~(1 << PORTD5);				// Clear PORTB5 for LED OFF
		_delay_ms(5000);					// 5 Seconds Delay  
    }
}

