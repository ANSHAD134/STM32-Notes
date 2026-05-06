/*
 * Control_LED_Brightness_Using_PWM.c
 *
 * Created: 06-05-2026 7.17.33 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


void LED_Condition(void)
{
	uint16_t LED_Brightness = 0;
	uint8_t state;
	
	if(!(PIND&(1 << PIND2)))
	{
		_delay_ms(50);							// Debounce delay for Push-button
		while(!(PIND&(1 << PIND2)));			// Wait until button released
		
		state++;
		if (state > 5)
		state = 1
		
		switch(state)
		{
			case 1:
			LED_Brightness = 25;				// 25% LED Brightness
			break;
			
			case 2:
			LED_Brightness = 50;				// 50% LED Brightness
			break;
			
			case 3:
			LED_Brightness = 75;				// 75% LED Brightness
			break;
			
			case 4:
			LED_Brightness = 100;				// 100% LED Brightness
			break;
			
			case 5:
			LED_Brightness = 0;					// LED OFF
			break;
		}
		OCR0A = LED_Brightness;
	}
} 

int main(void)
{
	DDRD |= (1 << DDD6);						// Set PD6 for Output
	
	DDRD &= ~(1 << DDD2);						// Set PD2 for Input
	PORTD |= (1 << PORTD2);						// Enable PULL-UP on PD2
	
	TCCR0A |= (1 << COM0A1);					// Non-inverting
	
	TCCR0B |= (1 << CS01) | (1 << CS00);		// Prescalar 64
	TCCR0A |= (1 << WGM00) | (1 << WGM01);		// Fast PWM
	OCR0A = 0;									// Start with LED off
    /* Replace with your application code */
    while (1) 
    {
		LED_Condition();
    }
}

