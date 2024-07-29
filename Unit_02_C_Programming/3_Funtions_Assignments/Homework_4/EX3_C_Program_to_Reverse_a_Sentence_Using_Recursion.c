/*
 ============================================================================
 Name        : EX3_C_Program_to_Reverse_a_Sentence_Using_Recursion.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void SentenceReverse();

int main()
{


	printf ("Enter a sentence: ");
	fflush(stdin);	fflush(stdout);
	SentenceReverse();

	return EXIT_SUCCESS;
}


void SentenceReverse()
{
	char c;
	scanf("%c", &c);
	if (c != '\n')
	{
		SentenceReverse();
		printf("%c", c);
	}
}
