#include "lifo.h"

LIFO_Status LIFO_init(LIFO_Buffer_t *lifo_buf, element_type *item_buf, unsigned int buf_len)
{
	//Check if buffer is null
	if(lifo_buf == NULL || item_buf == NULL || buf_len == 0)
	{
		printf("LIFO initialization failed: NULL pointer or zero length is passed \n");
		return LIFO_Is_Null;
	}
	// Init LIFO  
	lifo_buf->Base = item_buf;
	lifo_buf->Head = lifo_buf->Base;
	lifo_buf->length = buf_len;
	lifo_buf->counter = 0;

	printf("LIFO initialization passed:\n");
	printf("Element Type Configuration : element_type \n");

	return LIFO_No_Error;
}


LIFO_Status LIFO_push(LIFO_Buffer_t *lifo_buf, element_type item)
{
	//Check if buffer is null
	if(lifo_buf == NULL || lifo_buf->Base == NULL || lifo_buf->Head == NULL)
	{
		printf("LIFO push failed: NULL is passed\n");
		return LIFO_Is_Null;
	}
	//Check if buffer is full
	if(LIFO_is_full(lifo_buf) == LIFO_Is_Full)
	{
		printf("LIFO is full\n");
		return LIFO_Is_Full;
	}

	//Add Item
	*(lifo_buf->Head) = item;
	lifo_buf->Head++;
	lifo_buf->counter++;

	return LIFO_No_Error;
}


LIFO_Status LIFO_pop(LIFO_Buffer_t *lifo_buf, element_type *item)
{
	//Check if buffer is null
	if(lifo_buf == NULL || lifo_buf->Base == NULL || lifo_buf->Head == NULL || item == NULL)
	{
		printf("LIFO pop failed: NULL is passed\n");
		return LIFO_Is_Null;
	}

	//Check if buffer is empty
	if(LIFO_is_empty(lifo_buf) == LIFO_Is_Empty)
	{
		printf("LIFO is empty\n");
		return LIFO_Is_Empty;
	}

	//Get item
	lifo_buf->Head--;
	*item = *(lifo_buf->Head);
	lifo_buf->counter--;

	return LIFO_No_Error;
}


LIFO_Status LIFO_top(LIFO_Buffer_t *lifo_buf, element_type *item)
{
	//Check if buffer is null
	if(lifo_buf == NULL || lifo_buf->Base == NULL || lifo_buf->Head == NULL || item == NULL)
	{
		printf("LIFO top failed: NULL is passed\n");
		return LIFO_Is_Null;
	}

	//Check if buffer is empty
	if(LIFO_is_empty(lifo_buf) == LIFO_Is_Empty)
	{
		printf("There is no top; LIFO is empty\n");
		return LIFO_Is_Empty;
	}

	// Top = head - 1; We always increment head by 1 after adding any element
	*item = *(lifo_buf->Head - 1);
	printf("The top of the LIFO is %d\n",*item);
	
	return LIFO_No_Error;
}


LIFO_Status LIFO_print(LIFO_Buffer_t *lifo_buf)
{
	element_type *item_ptr;

	//Check if buffer is null
	if(lifo_buf == NULL || lifo_buf->Base == NULL || lifo_buf->Head == NULL)
	{
		printf("LIFO print failed: NULL is passed\n");
		return LIFO_Is_Null;
	}

	if(LIFO_is_empty(lifo_buf) == LIFO_Is_Empty)
	{
		printf("There is no element to print; LIFO is empty\n");
		return LIFO_Is_Empty;
	}

	printf("=======LIFO print=======\n");

	for (item_ptr = lifo_buf->Base ; item_ptr < lifo_buf->Head ; item_ptr++)
	{
		printf("\t %d \n",*item_ptr);
	}

	return LIFO_No_Error;

}


LIFO_Status LIFO_is_full(LIFO_Buffer_t *lifo_buf)
{
	//Check if buffer is null
	if(lifo_buf == NULL || lifo_buf->Base == NULL || lifo_buf->Head == NULL)
	{
		printf("LIFO is full failed: NULL is passed\n");
		return LIFO_Is_Null;
	}

	if(lifo_buf->counter == lifo_buf->length)
	{
		printf("LIFO is full \n");
		return LIFO_Is_Full;
	}

	printf("LIFO is not full \n");
	return LIFO_Is_NOT_FULL;

}


LIFO_Status LIFO_is_empty(LIFO_Buffer_t *lifo_buf)
{
	//Check if buffer is null
	if(lifo_buf == NULL || lifo_buf->Base == NULL || lifo_buf->Head == NULL)
	{
		printf("LIFO is empty failed: NULL is passed\n");
		return LIFO_Is_Null;
	}

	if(lifo_buf->counter == 0)
	{
		printf("LIFO is empty\n");
		return LIFO_Is_Empty;
	}

	printf("LIFO is not empty\n");
	return LIFO_Is_NOT_Empty;
}


LIFO_Status LIFO_make_empty(LIFO_Buffer_t *lifo_buf)
{
	//Check if buffer is null
	if(lifo_buf == NULL || lifo_buf->Base == NULL || lifo_buf->Head == NULL)
	{
		printf("LIFO make empty failed: NULL is passed\n");
		return LIFO_Is_Null;
	}

	//reset all 
	lifo_buf->Head = lifo_buf->Base;
	lifo_buf->counter = 0;

	return LIFO_No_Error;
}