/*
 * LCD_Button_Press_Program.c
 *
 * Created: 11-05-2026 7.54.38 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"


int main(void)
{
	DDRD &= ~(1 << DDD2);							// Input for Push-Button
	PORTD |= (1 << PORTD2);							// Enable Pull-up
	
	lcd_init();										// Initialize LCD Display
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

