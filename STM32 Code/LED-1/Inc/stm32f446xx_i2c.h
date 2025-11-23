/*
 * stm32f446xx_i2c.h
 *
 *  Created on: Nov 20, 2025
 *      Author: HP
 */

#ifndef STM32F446XX_I2C_H_
#define STM32F446XX_I2C_H_

/*
 * I2C BASE ADDRESS (APB1 Bus)
 */

#define I2C1_BASEADDR		0x40005400U
#define I2C2_BASEADDR		0x40005800U
#define I2C3_BASEADDR		0x40005C00U

/*
 * I2C REGISTER STRUCTURE
 */

typedef struct
{
	volatile uint32_t I2C_CR1;		//I2C CONTROL REGISTER 1 (0x00)
	volatile uint32_t I2C_CR2;		//I2C CONTROL REGISTER 2 (0x04)
	volatile uint32_t I2C_OAR1;		//I2C OWN ADDRESS REGISTER 1 (0x08)
	volatile uint32_t I2C_OAR2;		//I2C OWN ADDRESS REGISTER 2 (0x0C)
	volatile uint32_t I2C_DR;		//I2C DATA REGISTER 1 (0x10)
	volatile uint32_t I2C_SR1;		//I2C STATUS REGISTER 1 (0x14)
	volatile uint32_t I2C_SR2;		//I2C STATUS REGISTER 2 (0x18)
	volatile uint32_t I2C_CCR;		//I2C CLOCK CONTROL REGISTER (0x1C)
	volatile uint32_t I2C_TRISE;	//I2C TRISE REGISTER (0x20)
	volatile uint32_t I2C_FLTR;		//I2C FLTR REGISTER (0x24)
} I2C_RegDef_t;

/*
 * I2C POINTERS
 */

#define I2C1		((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2		((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3		((I2C_RegDef_t*)I2C3_BASEADDR)

/*
 *RCC BASE ADDRESS (APB1 Bus)
 */

#define RCC_BASEADDR		0x40023800U

/*
 * RCC REGISTER STRUCTURE
 */
typedef struct
	{
		volatile uint32_t CR;            // RCC clock control register                    (0x00)
	    volatile uint32_t PLLCFGR;       // RCC PLL configuration register                (0x04)
	    volatile uint32_t CFGR;          // RCC clock configuration register              (0x08)
	    volatile uint32_t CIR;           // RCC clock interrupt register                  (0x0C)
	    volatile uint32_t AHB1RSTR;      // RCC AHB1 peripheral reset register            (0x10)
	    volatile uint32_t AHB2RSTR;      // RCC AHB2 peripheral reset register            (0x14)
	    volatile uint32_t AHB3RSTR;      // RCC AHB3 peripheral reset register            (0x18)
	    volatile uint32_t RESERVED0;     // Reserved                                      (0x1C)
	    volatile uint32_t APB1RSTR;      // RCC APB1 peripheral reset register            (0x20)
	    volatile uint32_t APB2RSTR;      // RCC APB2 peripheral reset register            (0x24)
	    volatile uint32_t RESERVED1[2];  // Reserved                                      (0x28-0x2C)
	    volatile uint32_t AHB1ENR;       // RCC AHB1 peripheral clock enable register     (0x30)
	    volatile uint32_t AHB2ENR;       // RCC AHB2 peripheral clock enable register     (0x34)
	    volatile uint32_t AHB3ENR;       // RCC AHB3 peripheral clock enable register     (0x38)
	    volatile uint32_t RESERVED2;     // Reserved                                      (0x3C)
	    volatile uint32_t APB1ENR;       // RCC APB1 peripheral clock enable register     (0x40)
	    volatile uint32_t APB2ENR;       // RCC APB2 peripheral clock enable register     (0x44)
	    volatile uint32_t RESERVED3[2];  // Reserved                                      (0x48-0x4C)
	    volatile uint32_t AHB1LPENR;     // RCC AHB1 peripheral clock enable in low power (0x50)
	    volatile uint32_t AHB2LPENR;     // RCC AHB2 peripheral clock enable in low power (0x54)
	    volatile uint32_t AHB3LPENR;     // RCC AHB3 peripheral clock enable in low power (0x58)
	    volatile uint32_t RESERVED4;     // Reserved                                      (0x5C)
	    volatile uint32_t APB1LPENR;     // RCC APB1 peripheral clock enable in low power (0x60)
	    volatile uint32_t APB2LPENR;     // RCC APB2 peripheral clock enable in low power (0x64)
	    volatile uint32_t RESERVED5[2];  // Reserved                                      (0x68-0x6C)
	    volatile uint32_t BDCR;          // RCC Backup domain control register            (0x70)
	    volatile uint32_t CSR;           // RCC clock control & status register           (0x74)
	    volatile uint32_t RESERVED6[2];  // Reserved                                      (0x78-0x7C)
	    volatile uint32_t SSCGR;         // RCC spread spectrum clock generation register (0x80)
	    volatile uint32_t PLLI2SCFGR;    // RCC PLLI2S configuration register             (0x84)
	    volatile uint32_t PLLSAICFGR;    // RCC PLLSAI configuration register             (0x88)
	    volatile uint32_t DCKCFGR;       // RCC Dedicated Clocks configuration register   (0x8C)
	    volatile uint32_t CKGATENR;      // RCC clocks gated enable register              (0x90)
	    volatile uint32_t DCKCFGR2;      // RCC Dedicated Clocks configuration register 2 (0x94)
} RCC_RegDef_t;

/*
 * RCC POINTERS
 */

#define RCC		 ((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * CLOCK ENABLE MACROS (APB1 Bus for I2C)
 */

#endif /* STM32F446XX_I2C_H_ */
