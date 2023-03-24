/*
 * GPIO.c
 *
 * Created: 1/9/2023 7:51:15 PM
 *  Author: Abdelrahman Aref
 */ 

/*******************************************************************************
                                     Includes
 *******************************************************************************/
#include "Inc/GPIO.h"

/*******************************************************************************
 * Fn                -pinMode
 * Brief             -Set the PORTx PINy Nether INPUT , INPUT_PULLUP or Output.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -PIN: set pin number according @ref 3 .
 *
 *
 * Param [in]        -mode: Mode which wanted to be the pin mode .
 *
 *
 * Retval            -None.
 *
 */
void pinMode(PORTS PORT , PINS PIN , uint8_t mode)
{
	switch(PORT)
	{
		case PORT_A :
		switch(mode)
		{
			case INPUT:
			Reset_Bit(DDRA,PIN);
			break;
			
			case OUTPUT:
			Set_Bit(DDRA,PIN);
			break;
			
			case INPUT_PULLUP:
			Reset_Bit(DDRA,PIN);
			Set_Bit(PORTA,PIN);
			break;
			
		}
		break;
		
		case PORT_B :
		switch(mode)
		{
			case INPUT:
			Reset_Bit(DDRB,PIN);
			break;
			
			case OUTPUT:
			Set_Bit(DDRB,PIN);
			break;
			
			case INPUT_PULLUP:
			Reset_Bit(DDRB,PIN);
			Set_Bit(PORTB,PIN);
			break;
			
		}
		break;
		
		
		case PORT_C :
		switch(mode)
		{
			case INPUT:
			Reset_Bit(DDRC,PIN);
			break;
			
			case OUTPUT:
			Set_Bit(DDRC,PIN);
			break;
			
			case INPUT_PULLUP:
			Reset_Bit(DDRC,PIN);
			Set_Bit(PORTC,PIN);
			break;
			
		}
		break;
		
		case PORT_D :
		switch(mode)
		{
			case INPUT:
			Reset_Bit(DDRD,PIN);
			break;
			
			case OUTPUT:
			Set_Bit(DDRD,PIN);
			break;
			
			case INPUT_PULLUP:
			Reset_Bit(DDRD,PIN);
			Set_Bit(PORTD,PIN);
			break;
			
		}
		break;
	}	
}

/*******************************************************************************
 * Fn                -digitalWrite
 *
 * Brief             -Write on specific PIN.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -PIN: set pin number according @ref 3
 *
 *
 * Param [in]        -value: value which wanted set .
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void digitalWrite(PORTS PORT , PINS PIN , uint8_t value)
{
	switch(PORT)
	{
		case PORT_A :
		switch(value)
		{
			case LOW:
			Reset_Bit(PORTA,PIN);
			break;
			
			case HIGH:
			Set_Bit(PORTA,PIN);
			break;
			
		}
		break;
		
		case PORT_B :
		switch(value)
		{
			case LOW:
			Reset_Bit(PORTB,PIN);
			break;
			
			case HIGH:
			Set_Bit(PORTB,PIN);
			break;
			
		}
		break;
		
		
		case PORT_C :
		switch(value)
		{
			case LOW:
			Reset_Bit(PORTC,PIN);
			break;
			
			case HIGH:
			Set_Bit(PORTC,PIN);
			break;
			
			
		}
		break;
		
		case PORT_D :
		switch(value)
		{
			case LOW:
			Reset_Bit(PORTD,PIN);
			break;
			
			case HIGH:
			Set_Bit(PORTD,PIN);
			break;
			
		}
		break;
	}
}

/*******************************************************************************
 * Fn                -digitalToggle
 *
 * Brief             -Toggle a specific pin in PORTx.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the PORT Peripheral.
 *
 * Param [in]        -PIN: specifies the port pin to toggle it, set pin
 *                    number according @ref 3.
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void digitalToggle(PORTS PORT , PINS PIN)
{
	switch(PORT)
	{
		case PORT_A :
		Toggle_Bit(PORTA,PIN);
		break;
		
		case PORT_B :
		Toggle_Bit(PORTB,PIN);
		break;
		
		
		case PORT_C :
		Toggle_Bit(PORTC,PIN);
		break;
		
		case PORT_D :
		Toggle_Bit(PORTD,PIN);
		break;
	}	
}
/*******************************************************************************
 * Fn                -digitalRead
 *
 * Brief             -Read specific PIN.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the PORT Peripheral.
 *
 * Param [in]        -PIN: set pin number according @ref 3 .
 *
 * Retval            -The input pin value.
 *
 * Note              -None.
 */
uint8_t digitalRead(PORTS PORT , PINS PIN)
{
	switch(PORT)
	{
		case PORT_A :
		return Reset_Bit(PINA,PIN);
		break;
		
		case PORT_B :
		return Reset_Bit(PINB,PIN);
		break;
		
		
		case PORT_C :
		return Reset_Bit(PINC,PIN);
		break;
		
		case PORT_D :
		return Reset_Bit(PIND,PIN);
		break;
	}	
	return 0 ;
}

/*******************************************************************************
 * Fn                -portMode.
 *
 * Brief             -Set the PORTx Nether INPUT , INPUT_PULLUP or Output.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -mode: Mode which wanted to be the port mode ..
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void portMode(PORTS PORT , uint8_t mode)
{
		switch(PORT)
		{
			case PORT_A :
			switch(mode)
			{
				case INPUT:
				DDRA = 0x00;
				break;
				
				case OUTPUT:
				DDRA = 0xFF;
				break;
				
				case INPUT_PULLUP:
				DDRA = 0x00;
				PORTA = 0xFF;
				break;	
			}
			break;
			
			case PORT_B :
			switch(mode)
			{
				case INPUT:
				DDRB = 0x00;
				break;
				
				case OUTPUT:
				DDRB = 0xFF;
				break;
				
				case INPUT_PULLUP:
				DDRB = 0x00;
				PORTB = 0xFF;
				break;
			}
			break;
			
			
			case PORT_C :
			switch(mode)
			{
				case INPUT:
				DDRC = 0x00;
				break;
				
				case OUTPUT:
				DDRC = 0xFF;
				break;
				
				case INPUT_PULLUP:
				DDRC = 0x00;
				PORTC = 0xFF;
				break;
			}
			break;
			
			case PORT_D :
			switch(mode)
			{
				case INPUT:
				DDRD = 0x00;
				break;
				
				case OUTPUT:
				DDRD = 0xFF;
				break;
				
				case INPUT_PULLUP:
				DDRD = 0x00;
				PORTD = 0xFF;
				break;
			}
			break;
		}
}
/*******************************************************************************
 * Fn                -portWrite.
 *
 * Brief             -Write on specific PORT.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -Value: Port value.
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void portWrite(PORTS PORT , uint8_t value)
{
switch(PORT)
{
	case PORT_A :
	switch(value)
	{
		case LOW:
		PORTA = 0x00;
		break;
		
		case HIGH:
		PORTA = 0xFF;
		break;
		
	}
	break;
	
	case PORT_B :
	switch(value)
	{
		case LOW:
		PORTB = 0x00;
		break;
		
		case HIGH:
		PORTB = 0xFF;
		break;
		
	}
	break;
	
	
	case PORT_C :
	switch(value)
	{
		case LOW:
		PORTC = 0x00;
		break;
		
		case HIGH:
		PORTC = 0xFF;
		break;
		
		
	}
	break;
	
	case PORT_D :
	switch(value)
	{
		case LOW:
		PORTD = 0x00;
		break;
		
		case HIGH:
		PORTD = 0xFF;
		break;
		
	}
	break;
}
}
/*******************************************************************************
 * Fn                -portToggle
 *
 * Brief             -Toggle PORTx .
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the PORT Peripheral.
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void portToggle(PORTS PORT)
{
	switch(PORT)
	{
		case PORT_A :
		PORTA ^= PORTA;
		break;
		
		case PORT_B :
		PORTB ^= PORTB;
		break;
		
		
		case PORT_C :
		PORTC ^= PORTC;
		break;
		
		case PORT_D :
		PORTD ^= PORTD;
		break;
	}
}
/*******************************************************************************
 * Fn                -portRead.
 *
 * Brief             -Read specific PORT.
 *
 * Param [in]        -GPIOx: where x can be (A..E depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Retval            -The input port value.
 *
 * Note              -None.
 */
uint8_t portRead(PORTS PORT)
{
	switch(PORT)
	{
		case PORT_A :
		return PINA;
		break;
		
		case PORT_B :
		return PINB;
		break;
		
		
		case PORT_C :
		return PINC;
		break;
		
		case PORT_D :
		return PIND;
		break;
	}
	return 0 ;
}

/*******************************************************************************
 * Fn                -MSB_portMode.
 *
 * Brief             -Set the most significant bits in PORTx Nether INPUT , INPUT_PULLUP or Output.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -mode: Mode which wanted to be the port mode ..
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void MSB_portMode(PORTS PORT , uint8_t mode)
{
		switch(PORT)
		{
			case PORT_A :
			switch(mode)
			{
				case INPUT:
				DDRA &= 0x0F;
				break;
				
				case OUTPUT:
				DDRA |= 0xF0;
				break;
				
				case INPUT_PULLUP:
				DDRA &= 0x0F;
				PORTA |= 0xF0;;
				break;
			}
			break;
			
			case PORT_B :
			switch(mode)
			{
				case INPUT:
				DDRB &= 0x0F;
				break;
				
				case OUTPUT:
				DDRB |= 0xF0;
				break;
				
				case INPUT_PULLUP:
				DDRB &= 0x0F;
				PORTB |= 0xF0;;
				break;
			}
			break;
			
			
			case PORT_C :
			switch(mode)
			{
				case INPUT:
				DDRC &= 0x0F;
				break;
				
				case OUTPUT:
				DDRC |= 0xF0;
				break;
				
				case INPUT_PULLUP:
				DDRC &= 0x0F;
				PORTC |= 0xF0;;
				break;
			}
			break;
			
			case PORT_D :
			switch(mode)
			{
				case INPUT:
				DDRD &= 0x0F;
				break;
				
				case OUTPUT:
				DDRD |= 0xF0;
				break;
				
				case INPUT_PULLUP:
				DDRD &= 0x0F;
				PORTD |= 0xF0;;
				break;
			}
			break;
		}
}
/*******************************************************************************
 * Fn                -MSB_portWrite.
 *
 * Brief             -Write on the most significant bits in  PORTx.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -Value: Port value.
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void MSB_portWrite(PORTS PORT , uint8_t value)
{	
	switch(PORT)
	{
	case PORT_A :
		PORTA &= 0x0F;
		PORTA |= (value << 4);
	break;
	
	case PORT_B :
		PORTB &= 0x0F;
		PORTB |= (value << 4);
	break;
	
	
	case PORT_C :
		PORTC &= 0x0F;
		PORTC |= (value << 4);
	break;
	
	case PORT_D :
		PORTD &= 0x0F;
		PORTD |= (value << 4);
	break;
}
}

/*******************************************************************************
 * Fn                -MSB_portRead.
 *
 * Brief             -Read the most significant bits in PORTx.
 *
 * Param [in]        -GPIOx: where x can be (A..E depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Retval            -The input port value.
 *
 * Note              -None.
 */
uint8_t MSB_portRead(PORTS PORT)
{
	switch(PORT)
	{
		case PORT_A :
		return ((PINA & 0xF0) >> 4);
		break;
		
		case PORT_B :
		return ((PINB & 0xF0) >> 4);
		break;
		
		
		case PORT_C :
		return ((PINC & 0xF0) >> 4);
		break;
		
		case PORT_D :
		return ((PIND & 0xF0) >> 4);
		break;
	}
	return 0 ;
}
/*******************************************************************************
 * Fn                -LSB_portMode.
 *
 * Brief             -Set the Lowest significant bits in PORTx Nether INPUT , INPUT_PULLUP or Output.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -mode: Mode which wanted to be the port mode ..
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void LSB_portMode(PORTS PORT , uint8_t mode)
{
		switch(PORT)
		{
			case PORT_A :
			switch(mode)
			{
				case INPUT:
				DDRA &= 0xF0;
				break;
				
				case OUTPUT:
				DDRA |= 0x0F;
				break;
				
				case INPUT_PULLUP:
				DDRA &= 0xF0;
				PORTA |= 0x0F;;
				break;
			}
			break;
			
			case PORT_B :
			switch(mode)
			{
				case INPUT:
				DDRB &= 0xF0;
				break;
				
				case OUTPUT:
				DDRB |= 0x0F;
				break;
				
				case INPUT_PULLUP:
				DDRB &= 0xF0;
				PORTB |= 0x0F;;
				break;
			}
			break;
			
			
			case PORT_C :
			switch(mode)
			{
				case INPUT:
				DDRC &= 0xF0;
				break;
				
				case OUTPUT:
				DDRC |= 0x0F;
				break;
				
				case INPUT_PULLUP:
				DDRC &= 0xF0;
				PORTC |= 0x0F;;
				break;
			}
			break;
			
			case PORT_D :
			switch(mode)
			{
				case INPUT:
				DDRD &= 0xF0;
				break;
				
				case OUTPUT:
				DDRD |= 0x0F;
				break;
				
				case INPUT_PULLUP:
				DDRD &= 0xF0;
				PORTD |= 0x0F;;
				break;
			}
			break;
		}
}
/*******************************************************************************
 * Fn                -LSB_portWrite.
 *
 * Brief             -Write on the Lowest significant bits in  PORTx.
 *
 * Param [in]        -PORTx: where x can be (A..D depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Param [in]        -Value: Port value.
 *
 * Retval            -None.
 *
 * Note              -None.
 */
void LSB_portWrite(PORTS PORT , uint8_t value)
{
		switch(PORT)
		{
			case PORT_A :
	switch(value)
	{
		case LOW:
		PORTA &= 0xF0;
		break;
		
		case HIGH:
		PORTA |= 0x0F;
		break;
	}
	break;
	
	case PORT_B :
	switch(value)
	{
		case LOW:
		PORTB &= 0xF0;
		break;
		
		case HIGH:
		PORTB |= 0x0F;
		break;
	}
	break;
	
	
	case PORT_C :
	switch(value)
	{
		case LOW:
		PORTC &= 0xF0;
		break;
		
		case HIGH:
		PORTC |= 0x0F;
		break;
	}
	break;
	
	case PORT_D :
	switch(value)
	{
		case LOW:
		PORTD &= 0xF0;
		break;
		
		case HIGH:
		PORTD |= 0x0F;
		break;
	}
	break;
}
}
/*******************************************************************************
 * Fn                -LSB_portRead.
 *
 * Brief             -Read the Lowest significant bits inPORTx.
 *
 * Param [in]        -GPIOx: where x can be (A..E depending on device used) to
 *                    select the GPIO Peripheral.
 *
 * Retval            -The input port value.
 *
 * Note              -None.
 */

uint8_t LSB_portRead(PORTS PORT)
{
		switch(PORT)
		{
			case PORT_A :
			return PINA & 0x0F;
			break;
			
			case PORT_B :
			return PINB & 0x0F;
			break;
			
			
			case PORT_C :
			return PINC & 0x0F;
			break;
			
			case PORT_D :
			return PIND & 0x0F;
			break;
		}
		return 0 ;
}