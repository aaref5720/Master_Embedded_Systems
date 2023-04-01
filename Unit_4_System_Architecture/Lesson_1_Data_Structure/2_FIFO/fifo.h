#ifndef FIFO_H_
#define FIFO_H_

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
	element_type* Tail;
	unsigned int length;
	unsigned int counter;

}FIFO_Buffer_t;

typedef enum
{
	FIFO_No_Error,
	FIFO_Is_Full,
	FIFO_Is_NOT_Full,
	FIFO_Is_Empty,
	FIFO_Is_NOT_Empty,
	FIFO_Is_Null,
	
}FIFO_Status;

//APIs

//Initialize FIFO Given an array buffer and a buffer length
FIFO_Status FIFO_init(FIFO_Buffer_t *FIFO_buf, element_type *item_buf, unsigned int buf_len);

//Push item in the FIFO given a data item
FIFO_Status FIFO_enqueue(FIFO_Buffer_t *FIFO_buf, element_type item);

//Pop item from the FIFO given the address of the item holder
FIFO_Status FIFO_dequeue(FIFO_Buffer_t *FIFO_buf, element_type *item);

//Print the FIFO buffer content
FIFO_Status FIFO_print(FIFO_Buffer_t *FIFO_buf);

//IS the FIFO full ?
FIFO_Status FIFO_is_full(FIFO_Buffer_t *FIFO_buf);

//IS the FIFO empty ?
FIFO_Status FIFO_is_empty(FIFO_Buffer_t *FIFO_buf);

//Erase all data items inside the FIFO (Reset a FIFO buffer)
FIFO_Status FIFO_make_empty(FIFO_Buffer_t *FIFO_buf);

#endif