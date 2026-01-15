################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Power_Aware_Interrupt_System _Mini Project
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Power_Aware_Interrupt_System\ _Mini\ Project.elf \

MAP_FILES += \
Power_Aware_Interrupt_System\ _Mini\ Project.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Power_Aware_Interrupt_System\ _Mini\ Project.list \


# All Target
all: main-build

# Main-build Target
main-build: Power_Aware_Interrupt_System\ _Mini\ Project.elf secondary-outputs

# Tool invocations
Power_Aware_Interrupt_System\ _Mini\ Project.elf Power_Aware_Interrupt_System\ _Mini\ Project.map: $(OBJS) $(USER_OBJS) C:\Users\HP\Documents\C\ Programming\STM32\Project\Power_Aware_Interrupt_System\ _Mini\ Project\STM32F446RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Power_Aware_Interrupt_System _Mini Project.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\HP\Documents\C Programming\STM32\Project\Power_Aware_Interrupt_System _Mini Project\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Power_Aware_Interrupt_System _Mini Project.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Power_Aware_Interrupt_System\ _Mini\ Project.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Power_Aware_Interrupt_System _Mini Project.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Power_Aware_Interrupt_System\ _Mini\ Project.elf Power_Aware_Interrupt_System\ _Mini\ Project.list Power_Aware_Interrupt_System\ _Mini\ Project.map Power_Aware_Interrupt_System\\ _Mini\\ Project.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
