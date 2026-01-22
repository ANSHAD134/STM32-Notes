

#ifndef INC_STM32F446XX_LOWPOWER_DRIVER_H_
#define INC_STM32F446XX_LOWPOWER_DRIVER_H_

#include "stm32f446xx.h"

/* Clock Enable Macro for PWR peripheral */
#define PWR_PCLK_EN()   (RCC->APB1ENR |= (1 << 28))

/* Clock Disable Macro for PWR peripheral */
#define PWR_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 28))


typedef struct
{
    __vo uint32_t CR;                       /*!< PWR power control register,        Address offset: 0x00 */
    __vo uint32_t CSR;                      /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_RegDef_t;

#define PWR									((PWR_RegDef_t*)PWR_BASEADDR)

void Enter_Stop_Mode(void);
void PWR_ControlLowPowerRegulator(uint8_t Enable);
void PWR_ClearWakeUpFlag(void);
void SystemClock_ReConfig(void);

#endif /* INC_STM32F446XX_LOWPOWER_DRIVER_H_ */
