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

	struct Sstudents student/*[studentNum]*/;
	student = getInformation();
	printInformation(student);
	return EXIT_SUCCESS;
}


struct Sstudents getInformation()
{
	struct Sstudents student;

	printf("Enter information of students : \n");

	printf("Enter student name : ");
	fflush(stdin);  fflush(stdout);
	scanf("%s",student.name);

	printf("Enter student roll number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d" ,&student.roll);

	printf("Enter student marks : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&student.marks);

	return student ;
}

void printInformation(struct Sstudents student)
{
	printf("\nDisplaying information : \n");

	printf("Student name : %s\n",student.name);
	printf("Student roll number : %d\n",student.roll);
	printf("Student marks : %.2f\n",student.marks);


}
