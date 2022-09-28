/*
 ============================================================================
 Name        : EX1_C_Program_to_Store_Information_of_a_Student_Using_Structure.c
 Author      : Abdelrahman Aref
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sstudents
{
	char name[20];
	int roll;
	float marks;
};


struct Sstudents getInformation();
void printInformation(struct Sstudents student);


int main(void) {

	struct Sstudents student[10];
	int i = 0  , j = 1 , counter = 1 ;
	char checker = 0;

	printf("Enter information of students : \n");

	do
	{
		printf("For roll number %d \n",i + 1);

		student[i] = getInformation();
		i++; if(i == 9) break;

		printf("press 'y' to enter another student info or any other key to exit. ");
		fflush(stdin);  fflush(stdout);
		scanf("%c",&checker);

	}while(checker == 'y');

	printf("\nDisplaying information : \n\n");


	for(j = 0 ; j < i ; j++)
	{
		student[j].roll = counter;
		printInformation(student[j]);
		counter++;
	}


	return EXIT_SUCCESS;
}


struct Sstudents getInformation()
{
	struct Sstudents student;

	printf("Enter student name : ");
	fflush(stdin);  fflush(stdout);
	scanf("%s",student.name);

	printf("Enter student marks : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&student.marks);

	return student ;
}

void printInformation(struct Sstudents student)
{
	printf("Information for roll number %d\n",student.roll);
	printf("Student name : %s\n",student.name);
	printf("Student marks : %.2f\n",student.marks);
}
