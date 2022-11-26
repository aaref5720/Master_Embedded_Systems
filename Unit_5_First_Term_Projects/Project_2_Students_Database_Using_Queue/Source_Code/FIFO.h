#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "Platforms.h"
#include "system.h"

//User Configuration
/*select the element type (uint8, uint16, uint32, uint64)
 as it defined at "Platforms.h" library or as standerd C */
#define Element_Type struct Stuinfo

//Type definitions
typedef struct 
{

	Element_Type* Base;
	Element_Type* Head;
	Element_Type* Tail;
	uint32 length;
	uint32 counter;

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

// Declear Virtual Buffer
FIFO_Buffer_t VirtualBuffer;

//APIs

//Initialize FIFO Given an array buffer and a buffer length
FIFO_Status FIFO_init(FIFO_Buffer_t *FIFO_buf, Element_Type *item_buf, uint32 buf_len);

//Push item in the FIFO given a data item
FIFO_Status FIFO_enqueue(FIFO_Buffer_t *FIFO_buf, Element_Type item);

//Pop item from the FIFO given the address of the item holder
FIFO_Status FIFO_dequeue(FIFO_Buffer_t *FIFO_buf, Element_Type *item);

//Print the FIFO buffer content
FIFO_Status FIFO_print(FIFO_Buffer_t *FIFO_buf);

//IS the FIFO full ?
FIFO_Status FIFO_is_full(FIFO_Buffer_t *FIFO_buf);

//IS the FIFO empty ?
FIFO_Status FIFO_is_empty(FIFO_Buffer_t *FIFO_buf);

//Erase all data items inside the FIFO (Reset a FIFO buffer)
FIFO_Status FIFO_make_empty(FIFO_Buffer_t *FIFO_buf);

extern uint32 GCounter;

#endif