

#ifndef INC_STM32F446XX_LOWPOWER_DRIVER_H_
#define INC_STM32F446XX_LOWPOWER_DRIVER_H_

#include "stm32f446xx.h"

#define PWR_BASEADDR (APB1PERIPH_BASEADDR + 0x7000)


/* Clock Enable Macro for PWR peripheral */
#define PWR_PCLK_EN()   (RCC->APB1ENR |= (1 << 28))

/* Clock Disable Macro for PWR peripheral */
#define PWR_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 28))


void Enter_Stop_Mode(void);
void PWR_ControlLowPowerRegulator(uint8_t Enable);
void PWR_ClearWakeUpFlag(void);
void SystemClock_ReConfig(void);

#endif /* INC_STM32F446XX_LOWPOWER_DRIVER_H_ */
