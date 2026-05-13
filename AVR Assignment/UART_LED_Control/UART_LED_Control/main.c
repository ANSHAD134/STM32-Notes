/*
 * UART_LED_Control.c
 *
 * Created: 13-05-2026 7.46.49 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pwm.h"
#include "uart.h"


int main(void)
{
	char buffer[50];
	uint8_t index = 0;
	char received;
	uint8_t brightness;
	
	UART_Init();
	PWM_init();
	
	UART_TxString("UART LED Control Ready\n");
	
    /* Replace with your application code */
    while (1) 
    {
		received = UART_RxChar();

		if(received == '\r' || received == '\n')
		{
			buffer[index] = '\0';

			if(strcmp(buffer, "ON") == 0)						// ON Command
			{
				LED_Brightness(100);

				UART_TxString("LED is now ON\r\n");
			}

			else if(strcmp(buffer, "OFF") == 0)					// OFF Command
			{
				TCCR0A &= ~(1 << COM0A1);						// Disconnect PWM
				PORTD &= ~(1 << PORTD6);						// Force LED OFF

				UART_TxString("LED is now OFF\r\n");
			}
			else
			{
				brightness = atoi(buffer);

				if(brightness <= 100)
				{
					char msg[40];

					if(brightness == 0)
					{
						TCCR0A &= ~(1 << COM0A1);					// Disconnect PWM
						PORTD &= ~(1 << PORTD6);					// LED OFF
					}
					else
					{
						TCCR0A |= (1 << COM0A1);					// Enable PWM
						LED_Brightness(brightness);
					}
					sprintf(msg, "Brightness set to %d%%\r\n", brightness);

					UART_TxString(msg);
				}
				else
				{
					UART_TxString("Invalid Brightness Value\r\n");
				}
			}

			index = 0;
		}

		else
		{
			if(index < sizeof(buffer)-1)
			{
				buffer[index++] = received;
			}
		}
	}
}

