#include "FIFO.h"

FIFO_Status FIFO_init(FIFO_Buffer_t *FIFO_buf, element_type *item_buf, unsigned int buf_len)
{
	if(FIFO_buf == NULL || item_buf == NULL || buf_len == 0)
	{
		printf("FIFO Initialization failed: Null pointer or zero length is passed\n");
		return FIFO_Is_Null;
	}

	FIFO_buf->Base = item_buf;
	FIFO_buf->Head = FIFO_buf->Base;
	FIFO_buf->Tail = FIFO_buf->Head;
	FIFO_buf->length = buf_len;
	FIFO_buf->counter = 0;

	return FIFO_No_Error;
}

FIFO_Status FIFO_enqueue(FIFO_Buffer_t *FIFO_buf, element_type item)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO Enqueue failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if((FIFO_is_full(FIFO_buf)) == FIFO_Is_Full)
	{
		printf("Enqueue failed: FIFO is full\n");
		return FIFO_Is_Full;
	}

	*(FIFO_buf->Head) = item;

	if((FIFO_buf->Head + 1) == (FIFO_buf->Base + (FIFO_buf->length * sizeof(element_type))))
	{
		FIFO_buf->Head = FIFO_buf->Base;
	}
	else
	{
		FIFO_buf->Head++;
	}

	FIFO_buf->counter++;

	return FIFO_No_Error;
}

FIFO_Status FIFO_dequeue(FIFO_Buffer_t *FIFO_buf, element_type *item)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO Dequeue failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if((FIFO_is_empty(FIFO_buf)) == FIFO_Is_Empty)
	{
		printf("Dequeue failed: FIFO is empty\n");
		return FIFO_Is_Empty;
	}

	*(item) = *(FIFO_buf->Tail);

	if((FIFO_buf->Tail + 1) == (FIFO_buf->Base + (FIFO_buf->length * sizeof(element_type))))
	{
		FIFO_buf->Tail = FIFO_buf->Base;
	}
	else
	{
		FIFO_buf->Tail++;
	}

	FIFO_buf->counter--;

	return FIFO_No_Error;
}

FIFO_Status FIFO_print(FIFO_Buffer_t *FIFO_buf)
{
	element_type* temp;
	unsigned int i;

	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO print failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if((FIFO_is_empty(FIFO_buf)) == FIFO_Is_Empty)
	{
		printf("FIFO print failed: FIFO is empty\n");
		return FIFO_Is_Empty;
	}

	temp = FIFO_buf->Tail;
	printf("=======FIFO print=======\n");
	for(i = 0 ; i < FIFO_buf->counter ; i++)
	{
		printf("\t%d\n", *temp);

		if((temp + 1) == (FIFO_buf->Base + (FIFO_buf->length * sizeof(element_type))))
		{
			temp = FIFO_buf->Base;
		}
		else
		{
			temp++;
		}
	}
	return FIFO_No_Error;
}

FIFO_Status FIFO_is_full(FIFO_Buffer_t *FIFO_buf)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO is full test failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if(FIFO_buf->counter == FIFO_buf->length)
	{
		printf("FIFO is full \n");
		return FIFO_Is_Full;
	}

	return FIFO_Is_NOT_Full;
}

FIFO_Status FIFO_is_empty(FIFO_Buffer_t *FIFO_buf)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO is empty test failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if(FIFO_buf->counter == 0)
	{
		printf("FIFO is empty \n");
		return FIFO_Is_Empty;
	}

	return FIFO_Is_NOT_Empty;
}

FIFO_Status FIFO_make_empty(FIFO_Buffer_t *FIFO_buf)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO make empty failed: Null is passed\n");
		return FIFO_Is_Null;
	}
	FIFO_buf->Head = FIFO_buf->Base;
	FIFO_buf->Tail = FIFO_buf->Head;
	FIFO_buf->counter = 0;

	return FIFO_No_Error;
}