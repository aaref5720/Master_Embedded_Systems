/*
 ============================================================================
 Name        : EX5_C_Program_To_Check_Whether_A_Character_Is_An_Alphabet_Or_Not.c
 Author      : Abdelrahman aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x = 0;
	printf("Enter a character : ");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&x);
	if(( x >= 65 && x <= 90) || ( x >= 97 && x <= 122))
	{
		printf("%c is an alphabet ",x);
	}
	else
	{
		printf("%c is not an alphabet ",x);
	}
	return EXIT_SUCCESS;
}
