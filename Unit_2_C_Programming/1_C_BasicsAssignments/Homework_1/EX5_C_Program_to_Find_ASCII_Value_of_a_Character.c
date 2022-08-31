/*
 ============================================================================
 Name        : EX5_C_Program_to_Find_ASCII_Value_of_a_Character.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x = 0;
	printf("Enter a character: ");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of G = %d",x);
	return EXIT_SUCCESS;
}
