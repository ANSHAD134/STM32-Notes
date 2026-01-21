################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/stm32f446xx_gpio_driver.c \
../Driver/Src/stm32f446xx_low_power.c \
../Driver/Src/stm32f446xx_rcc_driver.c \
../Driver/Src/stm32f446xx_usart_driver.c 

OBJS += \
./Driver/Src/stm32f446xx_gpio_driver.o \
./Driver/Src/stm32f446xx_low_power.o \
./Driver/Src/stm32f446xx_rcc_driver.o \
./Driver/Src/stm32f446xx_usart_driver.o 

C_DEPS += \
./Driver/Src/stm32f446xx_gpio_driver.d \
./Driver/Src/stm32f446xx_low_power.d \
./Driver/Src/stm32f446xx_rcc_driver.d \
./Driver/Src/stm32f446xx_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"C:/Users/HP/Documents/C Programming/STM32/Project/Power_Aware_Interrupt_System _Mini Project/Driver/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/stm32f446xx_gpio_driver.cyclo ./Driver/Src/stm32f446xx_gpio_driver.d ./Driver/Src/stm32f446xx_gpio_driver.o ./Driver/Src/stm32f446xx_gpio_driver.su ./Driver/Src/stm32f446xx_low_power.cyclo ./Driver/Src/stm32f446xx_low_power.d ./Driver/Src/stm32f446xx_low_power.o ./Driver/Src/stm32f446xx_low_power.su ./Driver/Src/stm32f446xx_rcc_driver.cyclo ./Driver/Src/stm32f446xx_rcc_driver.d ./Driver/Src/stm32f446xx_rcc_driver.o ./Driver/Src/stm32f446xx_rcc_driver.su ./Driver/Src/stm32f446xx_usart_driver.cyclo ./Driver/Src/stm32f446xx_usart_driver.d ./Driver/Src/stm32f446xx_usart_driver.o ./Driver/Src/stm32f446xx_usart_driver.su

.PHONY: clean-Driver-2f-Src

