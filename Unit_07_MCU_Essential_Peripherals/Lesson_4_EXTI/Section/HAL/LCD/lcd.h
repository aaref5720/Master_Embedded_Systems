/*
 * lcd.h
 *
 * Created: 12/28/2022 6:39:22 PM
 *  Author: Abdelrahman Aref
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "util/delay.h"
#include "GPIO.h"

#define F_CPU 1000000UL

#define LCD_PORT			PORTA
#define DataDir_LCD_PORT	DDRA

#define LCD_CTRL			PORTB
#define DataDir_LCD_CTRL	DDRB



#define DATA_SHIFT			(4) // 0:4 bit date mode | 4:8 bit data mode

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

// Options for LCD
#define RS_PIN										(1)
#define	RW_PIN										(2)
#define E_PIN										(3)
#define LCD_FIRST_LINE								(0)
#define LCD_SECOND_LINE								(1)
#define LCD_FIRST_COLUMN							(0)

// Commands of LCD
#define LCD_CMD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_CMD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_CMD_FUNCTION_4BIT_2LINES_1st_CMD 			(0x02)
#define LCD_CMD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_CMD_MOVE_DISP_LEFT   						(0x18)
#define LCD_CMD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_CMD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_CMD_DISP_OFF   								(0x08)
#define LCD_CMD_DISP_ON_CURSOR   						(0x0E)
#define LCD_CMD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_CMD_DISP_ON_BLINK   						(0x0D)
#define LCD_CMD_DISP_ON   								(0x0C)
#define LCD_CMD_ENTRY_DEC   							(0x04)
#define LCD_CMD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_CMD_ENTRY_INC_   							(0x06)
#define LCD_CMD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_CMD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_CMD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CMD_CLEAR_SCREEN							(0x01)
#define LCD_CMD_ENTRY_MODE								(0x06)

void LCD_INIT();
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(char* string);
void LCD_ISBUSY();
void LCD_CLEAR_SCREEN();
void LCD_GOTO_XY(unsigned char line, unsigned char position);
void LCD_KICK();


#endif /* LCD_H_ */