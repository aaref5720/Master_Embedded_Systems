################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CAN-CASE-Study-1.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CAN-CASE-Study-1.list \

OBJCOPY_BIN += \
CAN-CASE-Study-1.bin \


# All Target
all: CAN-CASE-Study-1.elf secondary-outputs

# Tool invocations
CAN-CASE-Study-1.elf: $(OBJS) $(USER_OBJS) C:\Users\kinge\STM32CubeIDE\workspace_1.4.0\CAN\CAN-CASE-Study-1\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "CAN-CASE-Study-1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\kinge\STM32CubeIDE\workspace_1.4.0\CAN\CAN-CASE-Study-1\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CAN-CASE-Study-1.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CAN-CASE-Study-1.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CAN-CASE-Study-1.list"
	@echo 'Finished building: $@'
	@echo ' '

CAN-CASE-Study-1.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CAN-CASE-Study-1.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
