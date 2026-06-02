################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/bmp280.c \
../Src/main_i2c.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/bmp280.o \
./Src/main_i2c.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/bmp280.d \
./Src/main_i2c.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/HP/Documents/C Programming/STM32/STM32 Assignment/STM32_Bare-Metal_Driver_Implementation/Drivers/Inc" -I"C:/Users/HP/Documents/C Programming/STM32/STM32 Assignment/STM32_Bare-Metal_Driver_Implementation/Drivers/Src" -I"C:/Users/HP/Documents/C Programming/STM32/STM32 Assignment/STM32_Bare-Metal_Driver_Implementation/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/bmp280.cyclo ./Src/bmp280.d ./Src/bmp280.o ./Src/bmp280.su ./Src/main_i2c.cyclo ./Src/main_i2c.d ./Src/main_i2c.o ./Src/main_i2c.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

