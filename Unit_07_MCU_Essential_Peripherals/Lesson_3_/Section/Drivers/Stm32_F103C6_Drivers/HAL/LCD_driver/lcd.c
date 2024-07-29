/*
 * lcd.c
 *
 * Created: 12/28/2022 6:39:07 PM
 *  Author: Abdelrahman Aref
 */

#include "lcd.h"



void _delay_ms(int t)
{
	int i  , j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}

void LCD_KICK()
{
	MCAL_GPIO_WritePin(LCD_CTRL , E_PIN , HIGH);
	_delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL , E_PIN , LOW);

}



void LCD_INIT()
{
	_delay_ms(20);

	LCDconfig.GPIO_PinNumber = RS_PIN;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = RW_PIN;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = E_PIN;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	//LCD_ISBUSY();
	//LCD_KICK();

#ifdef EIGHT_BIT_MODE

	//for stm32
	LCDconfig.GPIO_PinNumber = GPIO_PIN_0;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_1;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_2;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_3;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL , E_PIN , LOW);

	_delay_ms(15);

	LCD_CLEAR_SCREEN();

	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE

	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);

	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL , E_PIN , LOW);

	_delay_ms(15);

	LCD_CLEAR_SCREEN();
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES_1st_CMD);
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
#endif


	LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_COMMAND(unsigned char command)
{
#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_PORT, ((MCAL_GPIO_ReadPort(LCD_PORT) & 0xFF00) | command));

	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , LOW);

	_delay_ms(1);

	LCD_KICK();
#endif

#ifdef FOUR_BIT_MODE

	MCAL_GPIO_WritePort(LCD_PORT, ((MCAL_GPIO_ReadPort(LCD_PORT) & 0xFF0F) | (command & 0xF0)));

	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , LOW);

	_delay_ms(1);
	LCD_KICK();

	MCAL_GPIO_WritePort(LCD_PORT, ((MCAL_GPIO_ReadPort(LCD_PORT) & 0xFF0F) | ((command & 0x0F) << DATA_SHIFT)));

	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , LOW);

	LCD_KICK();
#endif

}
void LCD_WRITE_CHAR(unsigned char character)
{
#ifdef EIGHT_BIT_MODE

	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , HIGH);
	MCAL_GPIO_WritePort(LCD_PORT, ((MCAL_GPIO_ReadPort(LCD_PORT) & 0xFF00) | character));
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , HIGH);
	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	LCD_KICK();

#endif

#ifdef FOUR_BIT_MODE
	MCAL_GPIO_WritePort(LCD_PORT, ((MCAL_GPIO_ReadPort(LCD_PORT) & 0xFF0F) | (character & 0xF0)));
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , HIGH);
	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	LCD_KICK();

	MCAL_GPIO_WritePort(LCD_PORT, ((MCAL_GPIO_ReadPort(LCD_PORT) & 0xFF0F) | ((character & 0x0F) << DATA_SHIFT)));
	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , HIGH);
	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
	LCD_KICK();

#endif
}

void LCD_WRITE_STRING(char* string)
{
	volatile static char counter = 0;
	while(*string != 0)
	{
		if(counter == 16)
		{
			LCD_GOTO_XY(LCD_SECOND_LINE, LCD_FIRST_COLUMN);
		}

		LCD_WRITE_CHAR(*string ++);
		counter++;

		if(counter > 31)
		{
			LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
			LCD_GOTO_XY(LCD_FIRST_LINE, LCD_FIRST_COLUMN);
			counter = 0 ;
		}

	}
}

void LCD_CLEAR_SCREEN()
{
	LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	else if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}

}

//void LCD_ISBUSY()
//{
//
//#ifdef EIGHT_BIT_MODE
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_0;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_1;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_2;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_3;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , HIGH);
//	MCAL_GPIO_WritePin(LCD_CTRL , RS_PIN , LOW);
//
//	LCD_KICK();
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_0;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_1;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_2;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_3;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//#endif
//
//#ifdef FOUR_BIT_MODE
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Input_FLO;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , HIGH);
//	MCAL_GPIO_WritePin(LCD_CTRL , E_PIN , LOW);
//
//	LCD_KICK();
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//
//	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
//	LCDconfig.GPIO_MODE = GPIO_MODE_Output_pp;
//	LCDconfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
//	MCAL_GPIO_Init(LCD_PORT, &LCDconfig);
//#endif
//
//	MCAL_GPIO_WritePin(LCD_CTRL , RW_PIN , LOW);
//}
