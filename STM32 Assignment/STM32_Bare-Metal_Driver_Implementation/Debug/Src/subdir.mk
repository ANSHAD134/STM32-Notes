################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/fonts.c \
../Src/main_spi.c \
../Src/ssd1306.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/fonts.o \
./Src/main_spi.o \
./Src/ssd1306.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/fonts.d \
./Src/main_spi.d \
./Src/ssd1306.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/HP/Documents/C Programming/STM32/STM32 Assignment/STM32_Bare-Metal_Driver_Implementation/Drivers/Inc" -I"C:/Users/HP/Documents/C Programming/STM32/STM32 Assignment/STM32_Bare-Metal_Driver_Implementation/Drivers/Src" -I"C:/Users/HP/Documents/C Programming/STM32/STM32 Assignment/STM32_Bare-Metal_Driver_Implementation/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/fonts.cyclo ./Src/fonts.d ./Src/fonts.o ./Src/fonts.su ./Src/main_spi.cyclo ./Src/main_spi.d ./Src/main_spi.o ./Src/main_spi.su ./Src/ssd1306.cyclo ./Src/ssd1306.d ./Src/ssd1306.o ./Src/ssd1306.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

