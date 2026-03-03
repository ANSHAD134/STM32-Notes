/*
 * RA6M1_gpio_driver.h
 *
 *  Created on: 03-Mar-2026
 *      Author: HP
 */

#ifndef INC_RA6M1_GPIO_DRIVER_H_
#define INC_RA6M1_GPIO_DRIVER_H_

#include <RA6M1.h>

/*
 * This is a Configuration structure for a GPIO pin
 */
typedef struct
{
    uint8_t GPIO_PinNumber;             /*!< Possible values from @GPIO_PIN_NUMBERS */
    uint8_t GPIO_PinMode;               /*!< Possible values from @GPIO_PIN_MODES */
    uint8_t GPIO_PinSpeed;              /*!< Possible values from @GPIO_PIN_SPEED */
    uint8_t GPIO_PinPuPdControl;        /*!< Possible values from @GPIO_PIN_PUPD */
    uint8_t GPIO_PinOPType;             /*!< Possible values from @GPIO_PIN_OP_TYPE */
    uint8_t GPIO_PinAltFunMode;         /*!< Alternate function mode (AF0-AF15) */
} GPIO_PinConfig_t;

/*
 * This is a Handle structure for a GPIO pin
 */
typedef struct
{
    GPIO_RegDef_t *pGPIOx;              /*!< This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t GPIO_PinConfig;    /*!< This holds GPIO pin configuration settings */
} GPIO_Handle_t;


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN                    0   /*!< Input mode */
#define GPIO_MODE_OUT                   1   /*!< General purpose output mode */
#define GPIO_MODE_ALTFN                 2   /*!< Alternate function mode */
#define GPIO_MODE_ANALOG                3   /*!< Analog mode */
#define GPIO_MODE_IT_FT                 4   /*!< Interrupt falling edge trigger */
#define GPIO_MODE_IT_RT                 5   /*!< Interrupt rising edge trigger */
#define GPIO_MODE_IT_RFT                6   /*!< Interrupt rising and falling edge trigger */

/*
 * @GPIO_PIN_OP_TYPE
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP                 0   /*!< Push-pull output */
#define GPIO_OP_TYPE_OD                 1   /*!< Open-drain output */

/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW                  0   /*!< Low speed */
#define GPIO_SPEED_MEDIUM               1   /*!< Medium speed */
#define GPIO_SPEED_FAST                 2   /*!< Fast speed */
#define GPIO_SPEED_HIGH                 3   /*!< High speed */


/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull-up and pull-down configuration macros
 */
#define GPIO_NO_PUPD                    0   /*!< No pull-up, no pull-down */
#define GPIO_PIN_PU                     1   /*!< Pull-up */
#define GPIO_PIN_PD                     2   /*!< Pull-down */



#endif /* INC_RA6M1_GPIO_DRIVER_H_ */
