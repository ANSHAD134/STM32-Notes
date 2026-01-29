

#ifndef INC_STM32F446XX_LOWPOWER_DRIVER_H_
#define INC_STM32F446XX_LOWPOWER_DRIVER_H_

#include "stm32f446xx.h"

#define SCB_BASEADDR   						0xE000ED00UL

typedef struct
{
    __vo uint32_t CPUID;
    __vo uint32_t ICSR;
    __vo uint32_t VTOR;
    __vo uint32_t AIRCR;
    __vo uint32_t SCR;
    __vo uint32_t CCR;
    __vo uint8_t  SHP[12];
    __vo uint32_t SHCSR;
} SCB_RegDef_t;

#define SCB 								((SCB_RegDef_t*)SCB_BASEADDR)


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
void CPU_Enter_WFI(void);

#endif /* INC_STM32F446XX_LOWPOWER_DRIVER_H_ */
