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
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0                   0
#define GPIO_PIN_NO_1                   1
#define GPIO_PIN_NO_2                   2
#define GPIO_PIN_NO_3                   3
#define GPIO_PIN_NO_4                   4
#define GPIO_PIN_NO_5                   5
#define GPIO_PIN_NO_6                   6
#define GPIO_PIN_NO_7                   7
#define GPIO_PIN_NO_8                   8
#define GPIO_PIN_NO_9                   9
#define GPIO_PIN_NO_10                  10
#define GPIO_PIN_NO_11                  11
#define GPIO_PIN_NO_12                  12
#define GPIO_PIN_NO_13                  13
#define GPIO_PIN_NO_14                  14
#define GPIO_PIN_NO_15                  15
#define GPIO_PIN_NO_16                  16
#define GPIO_PIN_NO_17                  17
#define GPIO_PIN_NO_18                  18
#define GPIO_PIN_NO_19                  19
#define GPIO_PIN_NO_20                  20
#define GPIO_PIN_NO_21                  21
#define GPIO_PIN_NO_22                  22
#define GPIO_PIN_NO_23                  23
#define GPIO_PIN_NO_24                  24
#define GPIO_PIN_NO_25                  25
#define GPIO_PIN_NO_26                  26
#define GPIO_PIN_NO_27                  27
#define GPIO_PIN_NO_28                  28
#define GPIO_PIN_NO_29                  29
#define GPIO_PIN_NO_30                  30
#define GPIO_PIN_NO_31                  31
#define GPIO_PIN_NO_32                  32
#define GPIO_PIN_NO_33                  33
#define GPIO_PIN_NO_34                  34
#define GPIO_PIN_NO_35                  35
#define GPIO_PIN_NO_36                  36
#define GPIO_PIN_NO_37                  37
#define GPIO_PIN_NO_38                  38
#define GPIO_PIN_NO_39                  39
#define GPIO_PIN_NO_40                  40
#define GPIO_PIN_NO_41                  41
#define GPIO_PIN_NO_42                  42
#define GPIO_PIN_NO_43                  43
#define GPIO_PIN_NO_44                  44
#define GPIO_PIN_NO_45                  45
#define GPIO_PIN_NO_46                  46
#define GPIO_PIN_NO_47                  47
#define GPIO_PIN_NO_48                  48
#define GPIO_PIN_NO_49                  49
#define GPIO_PIN_NO_50                  50
#define GPIO_PIN_NO_51                  51
#define GPIO_PIN_NO_52                  52
#define GPIO_PIN_NO_53                  53
#define GPIO_PIN_NO_54                  54
#define GPIO_PIN_NO_55                  55
#define GPIO_PIN_NO_56                  56
#define GPIO_PIN_NO_57                  57
#define GPIO_PIN_NO_58                  58
#define GPIO_PIN_NO_59                  59
#define GPIO_PIN_NO_60                  60
#define GPIO_PIN_NO_61                  61
#define GPIO_PIN_NO_62                  62
#define GPIO_PIN_NO_63                  63
#define GPIO_PIN_NO_64                  64
#define GPIO_PIN_NO_65                  65
#define GPIO_PIN_NO_66                  66
#define GPIO_PIN_NO_67                  67
#define GPIO_PIN_NO_68                  68
#define GPIO_PIN_NO_69                  69
#define GPIO_PIN_NO_70                  70
#define GPIO_PIN_NO_71                  71
#define GPIO_PIN_NO_72                  72
#define GPIO_PIN_NO_73                  73
#define GPIO_PIN_NO_74                  74
#define GPIO_PIN_NO_75                  75
#define GPIO_PIN_NO_76                  76

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
