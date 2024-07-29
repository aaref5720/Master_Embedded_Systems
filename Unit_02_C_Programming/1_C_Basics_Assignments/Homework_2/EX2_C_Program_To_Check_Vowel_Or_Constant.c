/*
 ============================================================================
 Name        : EXC_Program_To_Check_Vowel_Or_Constant.c
 Author      : Abdelrahman aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c = 0 ;
	printf("Enter An alphabet : ");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&c);
	if(c == 'i' || c == 'I' || c == 'a'|| c == 'A' || c == 'e' || c =='E' || c =='u' || c == 'U')
	{
		printf("%c is a vowel",c);
	}
	else
	{
		printf("%c is a constant",c);
	}
}
