/*
 * pwm.h
 *
 * Created: 16-05-2026 1.15.44 PM
 *  Author: HP
 */ 

#include <avr/io.h>

#ifndef PWM_H_
#define PWM_H_

void PWM_Init(void);
void Motor_Speed(uint8_t speed);


#endif /* PWM_H_ */