#ifndef  STUDENT_DB_H_
#define  STUDENT_DB_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"

#define DPRINTF(...) 		{fflush(stdout);fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);fflush(stdin);}


#define Max_Name_Size	40

//Effective data
typedef struct
{
	int ID;
	char name[Max_Name_Size];
	float hight;
}Student_Data_t;

//Linked-list node
struct Student_Node_t
{
	Student_Data_t Student;
	struct Student_Node_t* Next_Student_Ptr;
};

//APIs
void Fill_A_New_Record(struct Student_Node_t *NewStudent);
void Add_Student(void);
void Delete_Student(void);
void View_students(void);
void Delete_All(void);
void Get_Node(unsigned int index);
void Get_Node_From_End(int index);

int Students_Count_Iterative(void);
int Students_Count_Recursive(struct Student_Node_t* head);

void Get_Middle_Student(void);
void Reverse_Students(void);

#endif
