################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/Src/EXIT.c \
../Stm32_F103C6_Drivers/Src/GPIO.c \
../Stm32_F103C6_Drivers/Src/I2C.c \
../Stm32_F103C6_Drivers/Src/RCC.c \
../Stm32_F103C6_Drivers/Src/SPI.c \
../Stm32_F103C6_Drivers/Src/USART.c 

OBJS += \
./Stm32_F103C6_Drivers/Src/EXIT.o \
./Stm32_F103C6_Drivers/Src/GPIO.o \
./Stm32_F103C6_Drivers/Src/I2C.o \
./Stm32_F103C6_Drivers/Src/RCC.o \
./Stm32_F103C6_Drivers/Src/SPI.o \
./Stm32_F103C6_Drivers/Src/USART.o 

C_DEPS += \
./Stm32_F103C6_Drivers/Src/EXIT.d \
./Stm32_F103C6_Drivers/Src/GPIO.d \
./Stm32_F103C6_Drivers/Src/I2C.d \
./Stm32_F103C6_Drivers/Src/RCC.d \
./Stm32_F103C6_Drivers/Src/SPI.d \
./Stm32_F103C6_Drivers/Src/USART.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/Src/EXIT.o: ../Stm32_F103C6_Drivers/Src/EXIT.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Src/EXIT.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Src/GPIO.o: ../Stm32_F103C6_Drivers/Src/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Src/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Src/I2C.o: ../Stm32_F103C6_Drivers/Src/I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Src/I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Src/RCC.o: ../Stm32_F103C6_Drivers/Src/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Src/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Src/SPI.o: ../Stm32_F103C6_Drivers/Src/SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Src/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/Src/USART.o: ../Stm32_F103C6_Drivers/Src/USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/Keypad_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/HAL/LCD_driver" -I"C:/Users/kinge/STM32CubeIDE/workspace_1.4.0/unit7/LAB_1_Lesson3/Drivers/Stm32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/Src/USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

