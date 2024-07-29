/*
 ============================================================================
 Name        : EX2_C_Program_To_Find_The_Length_of_a_String.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char stri[100] = {0};
	int length = 0 , i = 0;
	printf("Enter a string : ");
	fflush(stdin);  fflush(stdout);
	gets(stri);
	for(i = 0 ; i < sizeof(stri) ; i++)
	{
		if(( stri[i] >= 65 && stri[i] <= 90) || ( stri[i] >= 97 && stri[i] <= 122))
			length ++ ;
	}
	printf("The length of the string is : %d ",length);
	return EXIT_SUCCESS;
}
