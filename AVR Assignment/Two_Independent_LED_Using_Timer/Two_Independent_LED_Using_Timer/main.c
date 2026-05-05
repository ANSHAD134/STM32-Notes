/*
 * Two_Independent_LED_Using_Timer.c
 *
 * Created: 05-05-2026 6.41.57 PM
 * Author : HP
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PORTB1);							// Status LED is High
}

ISR(TIMER2_COMPA_vect)
{
	PORTB ^= (1 << PORTB2);							// Heartbeat LED is High
}


int main(void)
{
	DDRB |= (1 << DDB1);							// Set output for Status LED
	DDRB |= (1 << DDB2);							// Set output for Heartbeat LED
	
	// Timer1 (16-bit)
	TCCR1A |= (1 << WGM01);							// CTC MODE
	TCCR1A |= (1 << CS02) | (1 << CS00);
	OCR0A = 31249;
	
	TIMSK0 |= (1 << OCIE0A);						// Output Compare Match A Interrupt
	
	// Timer 2 (8-bit)
	TCCR2A |= (1 << WGM01);							// CTC MODE
	OCR0A = 200;
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

