#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdint.h"


//User Configuration
//select the element type (uint8_t, uint16_t, uint32_t, uint64_t)

#define element_type uint8_t

//Type definitions

typedef struct 
{

	element_type* Base;
	element_type* Head;
	unsigned int length;
	unsigned int counter;

}LIFO_Buffer_t;

typedef enum
{

	LIFO_No_Error,
	LIFO_Is_Full,
	LIFO_Is_NOT_FULL,
	LIFO_Is_Empty,
	LIFO_Is_NOT_Empty,
	LIFO_Is_Null,
	
}LIFO_Status;


//APIs

//Initialize LIFO Given an array buffer and a buffer length
LIFO_Status LIFO_init(LIFO_Buffer_t *lifo_buf, element_type *item_buf, unsigned int buf_len);

//Push item in the LIFO given a data item
LIFO_Status LIFO_push(LIFO_Buffer_t *lifo_buf, element_type item);

//Pop item from the LIFO given the address of the item holder
LIFO_Status LIFO_pop(LIFO_Buffer_t *lifo_buf, element_type *item);

//Return the top of the LIFO without erasing it given item holder
LIFO_Status LIFO_top(LIFO_Buffer_t *lifo_buf, element_type *item);

//Print the LIFO buffer content
LIFO_Status LIFO_print(LIFO_Buffer_t *lifo_buf);

//IS the LIFO full ?
LIFO_Status LIFO_is_full(LIFO_Buffer_t *lifo_buf);

//IS the LIFO empty ?
LIFO_Status LIFO_is_empty(LIFO_Buffer_t *lifo_buf);

//Erase all data items inside the LIFO (Reset a LIFO buffer)
LIFO_Status LIFO_make_empty(LIFO_Buffer_t *lifo_buf);





#endif