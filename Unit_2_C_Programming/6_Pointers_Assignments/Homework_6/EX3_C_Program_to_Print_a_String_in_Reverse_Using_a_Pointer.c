/*
 ============================================================================
 Name        : EX3_C_Program_to_Print_a_String_in_Reverse_Using_a_Pointer.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void) {
	char str[] = "w3resource";
	char* ptr;
	ptr = str;
	int length = strlen(str);
	int i = 0;
	ptr = ptr + length;

	printf("Input a string : w3resource \n");
	printf("Reverse of the string is : ");

	for(i = length - 1 ; i >= 0 ;i--)
	{
		ptr--;
    	printf("%c",*ptr);
	}
	return EXIT_SUCCESS;
}
