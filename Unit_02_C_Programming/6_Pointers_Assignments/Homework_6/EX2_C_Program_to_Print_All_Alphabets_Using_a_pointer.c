/*
 ============================================================================
 Name        : EX2_C_Program_to_Print_All_Alphabets_Using_a_pointer.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//The Code can only display the alphabets.
//If you try to change any value by pointer, it may cause a crash.

int main(void) {
	char* p = 'A';
	//*p = 'A';
	int i;
	printf("The Alphabets are :\n");
	for(i = 0 ; i < 26 ; i++)
	{
		printf("%c  ",p);
		p++;
	}
	return EXIT_SUCCESS;
}
