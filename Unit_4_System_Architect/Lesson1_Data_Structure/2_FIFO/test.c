#include "fifo.h"

#define FIFO_buf_length	5

#define FIFO_testing(FIFO_function, pass_condition, pass_count, fail_count)		\
		if((FIFO_function) == (pass_condition))									\
		{																		\
			(pass_count)++;														\
			printf("Test passed\n");											\
		}																		\
		else																	\
		{																		\
			(fail_count)++;														\
			printf("Test failed\n");											\
		}


void main()
{
	element_type test_Buffer[FIFO_buf_length];
	FIFO_Buffer_t FIFO_test;

	element_type i = 0, pass = 0, fail = 0;

	//init
	printf("\ninit test ... \n");
	FIFO_testing(FIFO_init(&FIFO_test , test_Buffer , FIFO_buf_length) , FIFO_No_Error, pass, fail);

	//Enqueue
	printf("\nenqueue test ... \n");
	for(i = 0 ; i < FIFO_buf_length ; i++)
	{
		FIFO_testing(FIFO_enqueue(&FIFO_test , i) , FIFO_No_Error, pass, fail);
	}

	//Printing
	printf("\nVerifying enqueue with printing ...\n");
	FIFO_testing(FIFO_print(&FIFO_test) , FIFO_No_Error , pass , fail);

	//Check if filled ?
	printf("\nTesting capacity ...\n");
	FIFO_testing(FIFO_is_full(&FIFO_test) , FIFO_Is_Full , pass , fail);

	//Dequeue
	printf("\ndequeue Test ... \n");
	for(i = 0; i < FIFO_buf_length; i++)
	{
		FIFO_testing(FIFO_dequeue(&FIFO_test , &i) , FIFO_No_Error , pass , fail);
	}

	// Printing
	printf("\nVerifying dequeue with printing ... \n");
	FIFO_testing(FIFO_print(&FIFO_test), FIFO_No_Error, pass, fail);

	//Is empty ?!
	printf("\nTesting if FIFO is not empty ... \n");
	FIFO_testing(FIFO_is_empty(&FIFO_test), FIFO_Is_NOT_Empty, pass, fail);

	//Make empty
	printf("\nMaking FIFO empty ... \n");
	FIFO_testing(FIFO_make_empty(&FIFO_test), FIFO_No_Error, pass, fail);

	//Is empty ?!
	printf("\nTesting if FIFO is empty ... \n");
	FIFO_testing(FIFO_is_empty(&FIFO_test), FIFO_Is_Empty, pass, fail);


	printf("\nTest Report:\n");
	printf("Total Cases  : %d\n", pass + fail);
	printf("Total Passed : %d\n", pass);
	printf("Total Failed : %d\n", fail);
	
}
