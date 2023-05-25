################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/EEPROM.c \
../APP/I2C_EEPROM.c 

OBJS += \
./APP/EEPROM.o \
./APP/I2C_EEPROM.o 

C_DEPS += \
./APP/EEPROM.d \
./APP/I2C_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
APP/EEPROM.o: ../APP/EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"APP/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
APP/I2C_EEPROM.o: ../APP/I2C_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"APP/I2C_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

