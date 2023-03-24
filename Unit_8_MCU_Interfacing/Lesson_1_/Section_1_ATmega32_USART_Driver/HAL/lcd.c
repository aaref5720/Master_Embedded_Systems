/*
 * lcd.c
 *
 * Created: 12/28/2022 6:39:07 PM
 *  Author: Abdelrahman Aref
 */ 

#include "lcd.h"

void LCD_KICK()
{
	LCD_CTRL &= ~(1<<E_PIN);
	_delay_ms(50);
	LCD_CTRL |=(1<<E_PIN);
}

void LCD_ISBUSY()
{
	DataDir_LCD_PORT &= ~(0xFF<<DATA_SHIFT);
	LCD_CTRL		 |=  (1 << RW_PIN);
	LCD_CTRL		 &= ~(1 << RS_PIN);
	LCD_KICK();
	#ifdef EIGHT_BIT_MODE
	DataDir_LCD_PORT |=  (0xFF<<DATA_SHIFT);
	#endif
	
	#ifdef FOUR_BIT_MODE
	DataDir_LCD_PORT |=  (0xF0<<DATA_SHIFT);
	#endif
	
	LCD_CTRL		 &= ~(1 << RW_PIN);
}

void LCD_INIT()
{
	_delay_ms(20);
	LCD_ISBUSY();
	DataDir_LCD_CTRL |=  ((1 << RS_PIN) | (1 << RW_PIN) | (1 << E_PIN)); 
	LCD_CTRL		 &= ~((1 << RW_PIN) | (1 << RS_PIN) | (1 << E_PIN));
	LCD_KICK();
	_delay_ms(15);
	LCD_CLEAR_SCREEN();
	
	#ifdef EIGHT_BIT_MODE
		DataDir_LCD_PORT |=  (0xFF<<DATA_SHIFT);
		LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
	#endif

	#ifdef FOUR_BIT_MODE
		DataDir_LCD_PORT |=  (0xF0<<DATA_SHIFT);
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
		LCD_ISBUSY();
		LCD_PORT = command;
		LCD_CTRL &= ~(1<<RW_PIN)|(1<<RS_PIN);
		LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
		//LCD_ISBUSY();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		LCD_CTRL &= ~ ((1<<RW_PIN)|(1<<RS_PIN));
		LCD_KICK();
		
		_delay_ms(100);
		LCD_PORT = (LCD_PORT & 0x0F) | (command << DATA_SHIFT);
		LCD_CTRL &= ~ ((1<<RW_PIN)|(1<<RS_PIN));
		LCD_KICK();
	#endif
		
}
void LCD_WRITE_CHAR(unsigned char character)
{
	#ifdef EIGHT_BIT_MODE
		LCD_ISBUSY();
		LCD_CTRL |=   (1<<RS_PIN);
		LCD_PORT = ((character) << (DATA_SHIFT));
		LCD_CTRL |=   (1<<RS_PIN);
		LCD_CTRL &= ~ (1<<RW_PIN);
		LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
		LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_CTRL &= ~(1<<RW_PIN); // Turn RW OFF for write mode
		LCD_KICK();
		LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_CTRL &= ~(1<<RW_PIN); // Turn RW OFF for write mode
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
