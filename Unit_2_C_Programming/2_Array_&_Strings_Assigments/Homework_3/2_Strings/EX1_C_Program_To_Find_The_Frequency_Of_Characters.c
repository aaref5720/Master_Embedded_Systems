/*
 ============================================================================
 Name        : EX1_C_Program_To_Find_The_Frequency_Of_Characters.c
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
	char str[100];
	printf("Enter a string : ");
	fflush(stdin);  fflush(stdout);
	gets(str);
	int length  = 0;
	length  = strlen(str);
	int i = 0 , counter = 0;
	char c = 0;
	printf("Enter a character to find frequency  : ");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&c);

	for(i = 0 ; i < length ; i++)
	{
		if(str[i] == c)
			counter++;
	}
	printf("Frequency of %c = %d ",c,counter);
	return EXIT_SUCCESS;
}
