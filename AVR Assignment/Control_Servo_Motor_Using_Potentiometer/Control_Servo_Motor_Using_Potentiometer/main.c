/*
 * Control_Servo_Motor_Using_Potentiometer.c
 *
 * Created: 10-05-2026 7.37.05 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>




int main(void)
{
	DDRB |=(1 << DDB1);																		// Output for Servo motor
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

