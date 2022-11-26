#include "system.h"
#include "FIFO.h"
#include<conio.h>

// Global counter for number of students
uint32 GCounter = 0;

//Another APIs for searching and deleting
uint8  FIFO_Search(FIFO_Buffer_t *Buff , union Type_Value value , enum Search_Type type);
void FIFO_Delete_by_Key(FIFO_Buffer_t *Buff, Element_Type* Buffer , union Type_Value value , uint32 Buff_Length);

// System APIs Implementation

void Add_Student_Manually()
{
	uint32 i ;
	// Create temporary structure for the student information
	Element_Type* temp = (&VirtualBuffer)->Base ;
	Element_Type  Temp_Student ;
	if(GCounter == Buffer_Length)
	{
		printf("System is full \n");
		return;
	}
	/* Get the Roll number */
	printf("Enter the Roll Number: ");
	fflush(stdin);	fflush(stdout);	
	scanf("%d", &(Temp_Student.Roll));
	/* Check if it is unique or not 
	   Search for this Roll number through the queue */	
	for (i = 0; (i < (&VirtualBuffer) -> length) ; i++)
		{
			if  (temp -> Roll == Temp_Student.Roll)
			{
				printf("[ERROR] Roll Number %d is already taken\n", Temp_Student.Roll);
				printf("========Failed to add student========\n");
				return ;
			}
			temp++;		
		}

	// If unique then get the other fields 
		printf("Enter the first name of student: ");
		fflush(stdin);	fflush(stdout);
		gets(Temp_Student.fName);
		printf("Enter the last name of student: ");
		fflush(stdin);	fflush(stdout);
		gets(Temp_Student.lName);
		printf("Enter the GPA you obtained: ");
		fflush(stdin);	fflush(stdout);
		scanf("%f", &Temp_Student.GPA);
		printf("Enter the course ID of each course\n");
		for (i = 0 ; i < Number_Of_Courses ; i++)
		{
			printf("Course %d id: ", i+1);
			fflush(stdin);	fflush(stdout);
			scanf("%d", &Temp_Student.Course_ID[i]);
		}

		if(FIFO_enqueue(&VirtualBuffer , Temp_Student) == FIFO_No_Error)
		{
			printf("[INFO] Student's details are added successfully\n"); 
			GCounter++;
			printf("----------------------------------------------\n");
			Total_Students();
			return;
		}

		printf("========Failed to add student========\n");
}

void Add_Student_From_File()
{
	//  Open file in reading mode
	FILE *ptrFile;
	ptrFile = fopen ("text.txt", "r");

	// Check if NULL >> failed to open, else it is opened successfully
	if(ptrFile == NULL)
	{
		printf("Can't open this .txt file \n");
		return;
	}

	char retChar ;
	char tempArr[20] = {0};	
	uint32 i = 0, j = 0 , k = 6 ;

	uint8 flag = 0;
	uint32 z, tempPrint = 0; 
	union Type_Value tempRollNum;
	Element_Type* temp = (&VirtualBuffer) -> Head;
	Element_Type temp1 ;

	while(!feof(ptrFile))
	{
		//Check if Queue is full
		if(GCounter == Buffer_Length)
		{
			printf("System is full \n");
			return;
		}
		// Reading roll number of the student
		fscanf(ptrFile, "%d", &temp1.Roll);

		Element_Type* tempSearch = (&VirtualBuffer) -> Head;
		flag = 0;
		for (i = 0; (i < (&VirtualBuffer) -> length) ; i++)
		{
			if  (tempSearch -> Roll == temp1.Roll)
			{
				printf("[ERROR] Roll Number %d is already taken\n",temp1.Roll);
				printf("========Failed to add student========\n");

				// Ignore the rest of the line
				fscanf(ptrFile, "%*[^\n]");
				flag = 1 ;
				break;
			}
			tempSearch++;		
			}
			if(flag == 1)
			{
				continue;
				fscanf(ptrFile, "%*[^\n]");
			}
			else
			{
				temp -> Roll = temp1.Roll;
				GCounter++;

				fscanf(ptrFile, "%s", temp1.fName);
				strcpy(temp->fName , temp1.fName);

				fscanf(ptrFile, "%s", temp1.lName);
				strcpy(temp->lName , temp1.lName);

				fscanf(ptrFile, "%f", &temp1.GPA);
				temp -> GPA = temp1.GPA;

				for (i = 0; i < Number_Of_Courses; ++i)
				{
					fscanf(ptrFile, "%d", &temp1.Course_ID[i]);
				}

				for (i = 0; i < Number_Of_Courses; ++i)
				{
					temp->Course_ID[i] = temp1.Course_ID[i];
				}
				temp++;
		}
	}

	printf("[INFO] Students details are saved successfully\n");
	printf("----------------------------------------------\n");
	Total_Students();
	// Closing the file
	fclose(ptrFile);
}

void Find_Student_by_Roll_Number()
{
	union Type_Value Temp;
	uint8 flag;

	printf("Enter the Roll number of the student: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d", &(Temp.Roll_U));

	flag = FIFO_Search (&VirtualBuffer, Temp, ByRoll);

	if (flag == 0)
		printf("[ERROR] Roll number %d not found\n", Temp.Roll_U);
	printf("\n--------------------------------\n");
}

void Find_Student_by_First_Name()
{
	union Type_Value Temp;
	uint8 flag;

	printf("Enter the first name of the student: ");
	fflush(stdin);	fflush(stdout);
	gets(Temp.FName_U);

	flag = FIFO_Search (&VirtualBuffer, Temp, ByfName);

	if (flag == 0)
		printf("[ERROR] The student's first name %s not found\n", Temp.FName_U);
	printf("\n--------------------------------\n");
}

void Find_Students_by_Course()
{
	union Type_Value Temp;
	uint8 flag;

	printf("Enter the course ID: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d", &(Temp.Course_U));

	flag = FIFO_Search (&VirtualBuffer, Temp, ByID);
}

void Total_Students()
{
	printf("[INFO] The total number of students is %d\n", GCounter);
	printf("[INFO] You can add up to %d students\n", Buffer_Length);
	printf("[INFO] You can add %d more students\n", Buffer_Length - GCounter);
}

void Delete_Student_by_Roll_Number()
{
	union Type_Value Temp;

	// Get the Roll number from the user 
	printf("Enter the Roll number which you want to delete: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d", &(Temp.Roll_U));

	// Call the function to delete 
	FIFO_Delete_by_Key (&VirtualBuffer , Stu , Temp , Buffer_Length); 
}

void Update_Student_by_Roll_Number()
{
	Element_Type* temp = (&VirtualBuffer)->Base;
	uint32 i , j , tempRoll ;
	uint8 Option;

	printf("Enter the Roll number to update the entry: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&tempRoll);

	for(i = 0 ; i < (&VirtualBuffer)->length ; i++)
	{
		if(temp->Roll == tempRoll)
		{
			printf("Select a Number to edit \n");
			printf("1. First name\n2. Last name\n3. Roll number\n4. GPA\n5. Courses\n");
			fflush(stdin);	fflush(stdout);
			scanf("%d", &Option);

			switch(Option)
			{
				case 1:	
					printf("Enter the first name: ");
					fflush(stdin);	fflush(stdout);
					gets(temp -> fName);
					break;
				case 2: 
					printf("Enter the last name: ");
					fflush(stdin);	fflush(stdout);
					gets(temp -> lName);
					break;
				case 3: 
					printf("Enter the Roll number: ");
					fflush(stdin);	fflush(stdout);
					scanf("%d", &(temp -> Roll));
					break;
				case 4: 
					printf("Enter the GPA: ");
					fflush(stdin);	fflush(stdout);
					scanf("%f", &(temp -> GPA));
					break;
				case 5: 
					printf("Enter the courses' IDs:\n");
					fflush(stdin);	fflush(stdout);
						for (j = 0; j < 5; j++)
						{
							printf("Course %d ID is : ", (j+1));
							fflush(stdin);  fflush(stdout);
							scanf("%d", &(temp -> Course_ID[j]));
						}
					break;
			}

			printf("[INFO] UPDATED SUCCESSFULLY.\n");
			return;
		}
			
		else
			temp++;
	}

	printf("[ERROR] This Roll number %d not found\n", tempRoll);

}

void Show_Students_Info()
{
	FIFO_print(&VirtualBuffer);
}

uint8 FIFO_Search(FIFO_Buffer_t* Buff , union Type_Value value , enum Search_Type type)
{
	/* Input: 1. Pointer to buffer
			  2. Data to search for
			  3. Type of data
	*/
	Element_Type* temp = Buff -> Base;
	uint32 i;
	uint32 j , Counter = 0 ;

	switch(type)
	{
		case ByRoll :	// Roll number
			for(i = 0 ; i < Buff->length ; i++)
			{
				if(temp->Roll == value.Roll_U)
				{
					// Print student information
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The GPA is %.2f\nThe courses IDs are:",temp->fName , temp->lName , temp->GPA);
						for(j = 0 ; j < Number_Of_Courses ; j++)
						{
							printf("%d ", temp->Course_ID[j]);
						}
						return 1;
				}
				else
					temp++;
			}
			break;

		/*case ByGPA :	// GPA
			for(i = 0 ; i < Buff->length ; i++)
			{
				if(temp->GPA == value.GPA_U)
				{
					// Print student information
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The Roll number is %d \nThe GPA is %.2f\nThe courses IDs are:",temp->fName , temp->lName , temp->Roll , temp->GPA);
						for(j = 0 ; j < Number_Of_Courses ; j++)
						{
							printf("%d ", temp->Course_ID[j]);
						}
						return ;
				}
				else
					temp++;
			}
			break;*/

		case ByfName :	// First Name
			for(i = 0 ; i < Buff->length ; i++)
			{
				if( !strcmp(temp->fName , value.FName_U))
				{
					// Print student information
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The Roll number is %d \nThe GPA is %.2f\nThe courses IDs are:",temp->fName , temp->lName , temp->Roll , temp->GPA);
						for(j = 0 ; j < Number_Of_Courses ; j++)
						{
							printf("%d ", temp->Course_ID[j]);
						}
						return 1;
				}
				else
					temp++;
			}
			break;

		case ByID :	// Course ID
			for(i = 0 ; i < Buff->length ; i++)
			{
				for(j = 0 ; j < Number_Of_Courses ; j++)
				{	
					if(temp -> Course_ID[j] == value.Course_U)
					{
						Counter++;
						// Print all students information
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The Roll number is %d \nThe GPA is %.2f\n",temp->fName , temp->lName , temp->Roll , temp->GPA);
					}
				}	
				temp++;	
			}
			if(Counter == 0)
			{
				printf("[ERROR] course id %d not found\n", value.Course_U);
				printf("\n--------------------------------\n");
				return 0 ;
			}
			else
			{
				printf("[INFO] Total number of students enRolled: %d\n", Counter);
				printf("\n--------------------------------\n");
				return 1 ;
			}
			break;
	}

	// If not founded
	return 0;
}

void FIFO_Delete_by_Key(FIFO_Buffer_t* Buff, Element_Type* Buffer, union Type_Value value , uint32 Buff_Length)
{
	Element_Type* temp = Buff -> Base;
	uint32 temp1 = 0;
	uint32 i;
	for(i = 0 ; i < Buff->length ; i++)
	{
		if(temp->Roll == value.Roll_U)
		{
			temp1 = i;
			break ;
		}
			
		else
			temp++;
	}

	if(i >= Buff->length)
	{
		printf("[ERROR] This Roll number %d not found\n", value.Roll_U);
		return;
	}

	Buff_Length = Buff_Length - 1 ;

	for (temp1 = i; temp1 < Buff_Length; temp1++)
	{
		Buffer[temp1] = Buffer[temp1 + 1];  
	}

	// Decrement the buffer Head 
	(Buff->Head)--;

	// Decrease the global counter by one to decrease the number of students
	GCounter--;
	printf("[INFO] The Roll number %d is removed successfully\n", value.Roll_U);
}