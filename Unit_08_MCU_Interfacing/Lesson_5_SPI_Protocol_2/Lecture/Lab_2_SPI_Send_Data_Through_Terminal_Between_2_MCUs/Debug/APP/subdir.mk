################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/SPI_Transmitter_between_2MCU.c 

OBJS += \
./APP/SPI_Transmitter_between_2MCU.o 

C_DEPS += \
./APP/SPI_Transmitter_between_2MCU.d 


# Each subdirectory must supply rules for building sources it contributes
APP/SPI_Transmitter_between_2MCU.o: ../APP/SPI_Transmitter_between_2MCU.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"APP/SPI_Transmitter_between_2MCU.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

