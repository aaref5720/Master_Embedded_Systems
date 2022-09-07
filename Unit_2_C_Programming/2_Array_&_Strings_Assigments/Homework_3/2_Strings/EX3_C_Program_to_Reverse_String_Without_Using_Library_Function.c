/*
 ============================================================================
 Name        : EX3_C_Program_to_Reverse_String_Without_Using_Library_Function.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char stri[100]  ;
	printf("Enter the string : ");
	fflush(stdin);  fflush(stdout);
	gets(stri);
	int length = strlen(stri) , i = 0, j = 0 ;
	char stri1[length];

		for(j = length - 1 ; j >= 0 ; j--)
		{
			stri1[i] = stri[j];
			i++;
		}
	printf("Reverse string is : %s",stri1);
	return EXIT_SUCCESS;
}
