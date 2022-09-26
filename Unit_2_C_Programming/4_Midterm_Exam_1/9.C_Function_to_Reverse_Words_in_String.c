/*
 ============================================================================
 Name        : C_Function_to_Reverse_Words_in_String.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 100

void nameReverser(char name[]);

int main(void) {
	char name[maxSize];
	printf("Enter your name : ");
	fflush(stdin);  fflush(stdout);
	gets(name);
	nameReverser(name);

}

void nameReverser(char name[])
{
	char temp[maxSize];
	char temp2[maxSize];
	int length = strlen(name);

	int i = 0 , j = 0 , p = 0;
	for(;i<length ; i++)
	{
		if(name[i] == 32)
		{
			temp[i] = '\0';
			break;
		}
		temp[i] = name[i] ;
		p++;
	}
	p++;
	for(i = p ; i < length ; i++)
	{
			temp2[j] = name[i] ;
			j++;
			temp2[j] = 32 ;
	}
	int length1 = strlen(temp); printf("%d\n",length1);
	int length2 = strlen(temp2);
	printf("The reversed name is : ");
	for(i = 0 ; i < length2 ; i++)
	{
		printf("%c",temp2[i]);
	}
	for(i = 0 ; i < length1 ; i++)
	{
		printf("%c",temp[i]);
	}
}
