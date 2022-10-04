/*
 ============================================================================
 Name        : EX5_C_Program_to_Show_a_Pointer_to_an_Array_Which_Contents_are_Pointer_to_Structure.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Semployee
{
	char name[15];
	int ID;

};

int main(void) {
	struct Semployee employee1 = {"Abdelrahman" , 1211} ,
	employee2 = {"Aref" , 2711} , employee3 = {"Nadi" , 5720};

	//pointer to structure
	struct Semployee* ptr[] = {&employee1 , &employee2 , &employee3};
	printf("Employee Name : %s\n",ptr[0]->name);
	printf("Employee ID : %d\n",ptr[0]->ID);

	printf("\n");

	//]pointer to Array to structure
	struct Semployee* (*ptrArr)[3] = &ptr;
	printf("Employee Name : %s\n",(*(*ptrArr))->name);
	printf("Employee ID : %d\n",(*(*ptrArr))->ID);

	return EXIT_SUCCESS;
}
