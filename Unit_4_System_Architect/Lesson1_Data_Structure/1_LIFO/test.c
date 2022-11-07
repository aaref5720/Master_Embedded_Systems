#include "lifo.h"

#define LIFO_buf_length 5


#define LIFO_testing(LIFO_function, pass_condition, pass_count, fail_count)		\
		if((LIFO_function) == (pass_condition))									\
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
	LIFO_Buffer_t LIFO_test ;
	element_type test_Buffer[LIFO_buf_length];

	element_type i = 0 , temp = 0 , pass = 0 , fail = 0 ;

	//init
	printf("\ninit test ... \n");
	LIFO_testing(LIFO_init(&LIFO_test , test_Buffer , LIFO_buf_length) , LIFO_No_Error, pass, fail);

	//Push
	printf("\nPushing test ... \n");
	for(i = 0 ; i < LIFO_buf_length ; i++)
	{
		LIFO_testing(LIFO_push(&LIFO_test , i) , LIFO_No_Error, pass, fail);
	}

	//Printing
	printf("\nVerifying pushing with printing ...\n");
	LIFO_testing(LIFO_print(&LIFO_test) , LIFO_No_Error , pass , fail);

	//Check if filled ?
	printf("\nTesting capacity ...\n");
	LIFO_testing(LIFO_is_full(&LIFO_test) , LIFO_Is_Full , pass , fail);

	//Pop
	printf("\nPopping Test ... \n");
	for(i = 0; i < LIFO_buf_length; i++)
	{
		LIFO_testing(LIFO_pop(&LIFO_test , &i) , LIFO_No_Error , pass , fail);
	}

	// Top
	printf("\nTesting top item ... \n");
	LIFO_testing(LIFO_top(&LIFO_test, &temp), LIFO_No_Error, pass, fail);

	// Printing
	printf("\nVerifying popping with printing ... \n");
	LIFO_testing(LIFO_print(&LIFO_test), LIFO_No_Error, pass, fail);

	//Is empty ?!
	printf("\nTesting if LIFO is not empty ... \n");
	LIFO_testing(LIFO_is_empty(&LIFO_test), LIFO_Is_NOT_Empty, pass, fail);

	//Make empty
	printf("\nMaking LIFO empty ... \n");
	LIFO_testing(LIFO_make_empty(&LIFO_test), LIFO_No_Error, pass, fail);

	//Is empty ?!
	printf("\nTesting if LIFO is empty ... \n");
	LIFO_testing(LIFO_is_empty(&LIFO_test), LIFO_Is_Empty, pass, fail);


	printf("\nTest Report:\n");
	printf("Total Cases  : %2d\n", pass + fail);
	printf("Total Passed : %2d\n", pass);
	printf("Total Failed : %d\n", fail);






}

//LIFO_Status LIFO_init(&LIFO_test , test_Buffer , LIFO_buf_length);
//LIFO_Status LIFO_push(&LIFO_test , i);
//LIFO_Status LIFO_print(&LIFO_test);
//LIFO_Status LIFO_pop(&LIFO_test , &i);
//LIFO_Status LIFO_top(&LIFO_test, &temp);
//LIFO_Status LIFO_is_full(&LIFO_test);
//LIFO_Status LIFO_is_empty(&LIFO_test);
//LIFO_Status LIFO_make_empty(&LIFO_test);