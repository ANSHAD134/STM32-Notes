/*
 * One-way_Traffic_Light_Controller.c
 *
 * Created: 03-05-2026 7.25.13 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>

void delay_1ms(void)
{
	TCNT0 = 0;								// Initial value of Time is 0
	TIFR0 |= (1 << OCF0A);					// Write 1 to OCF0A of TIFR0 Register to Reset
	
	while(!(TIFR0&(1 << OCF0A)));			// Wait for set
}

void delay_ms(uint16_t ms)
{
	for(uint16_t i=0; i<ms; i++)
	{
		delay_1ms();
	}
}


int main(void)
{
	DDRB |= (1 << DDB0);					// Set output for GREEN LED
	DDRB |= (1 << DDB4);					// Set output for ORANGE LED
	DDRB |= (1 << DDB5);					// Set output for RED LED
	
	TCCR0A |= (1 << WGM01);					// CTC Mode
	OCR0A = 249;							// Set point equal to 249
	TCCR0B |= (1 << CS01) | (1 << CS00);	// Prescalar 64
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB = (1 << PORTB0);				// GREEN LED
		delay_ms(10000);					// 10 second delay
		
		PORTB = (1 << PORTB4);				// ORANGE LED
		delay_ms(3000);						// 3 second delay
		
		PORTB = (1 << PORTB5);				// RED LED
		delay_ms(10000);					// 10 second delay
    }
}

