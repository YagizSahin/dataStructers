#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Creating the struct
struct Student
{
	char name[50];
	char gender;
	struct Student* next;
};
struct Student* insertNode(char* name,
	char gender, struct Student* list)
{
	struct Student* s;
	//Allocate memory for node (mallocoperation)
	s = malloc(sizeof(struct Student));
	if (s == NULL)
	{
		printf("Memory allocation failed.");
		return list;
	}
	strcpy(s->name, name);
	s->gender = gender;
	s->next = list; //list is the startof the list
		list = s;

	return list;
}
//Sorting function
struct Student* sortList(struct Student* list)
{
	
	struct Student* cursor2=list;
	struct Student* temp= cursor2;
	struct Student* cursor4, * cursor5, * temp1, * temp2, * temp3;
	//sorting nodes by gender
	while (cursor2!=NULL)
	{
		struct Student* cursor1=list;
		while (cursor1->next!= NULL)
		{
			if (cursor1->next->gender == 'F')
			{
				struct Student* cursor3 = cursor1->next;
				cursor1->next = cursor1->next->next;
				cursor3->next = list;
				list = cursor3;
			}
			cursor1 = cursor1->next;
		}
		cursor2 = cursor2->next;
	}
	//referenced by https://www.youtube.com/watch?v=pdMPvMM12G0
	//sort names alphabetically with separeted genders
	for (cursor4  = NULL;cursor4!=list->next; cursor4=temp1)
	{
		for (cursor5=temp1 = list; temp1->next!=cursor4; cursor5=temp1,temp1=temp1->next)
		{
			temp2 = temp1->next;
			if (strcmp(temp1->name,temp2->name)>0&&temp1->gender=='F'&&temp2->gender=='F')
			{
				temp1->next = temp2->next;
				temp2->next = temp1;
				if (temp1!=list)
				{
					cursor5->next = temp2;
				}
				else
				{
					list = temp2;
				}
				temp3 = temp1;
				temp1 = temp2;
				temp2 = temp3;
			}
			else if (strcmp(temp1->name, temp2->name) < 0 && temp1->gender == 'M' && temp2->gender == 'M')
			{
				temp1->next = temp2->next;
				temp2->next = temp1;
				if (temp1 != list)
				{
					cursor5->next = temp2;
				}
				else
				{
					list = temp2;
				}
				temp3 = temp1;
				temp1 = temp2;
				temp2 = temp3;
			}
		}
	}
	return list;
}

//Printing function
void printList(struct Student* list)
{
	while (list != NULL)
	{
		printf("%s\t%c\n", list->name, list -> gender);
		list = list->next;
	}
}
int main()
{
	//Creating an Initial Node Variable
	struct Student* head = NULL;
	//Call to functions
	head = insertNode("Cenk", 'M', head);
	head = insertNode("Ceyda", 'F', head);
	head = insertNode("Esra", 'F', head);
	head = insertNode("Okan", 'M', head);
	head = insertNode("Tugce", 'F', head);
	head = insertNode("Mehmet", 'M', head);
	head = insertNode("Ayse", 'F', head);
	head = insertNode("Merve", 'F', head);
	head = insertNode("Sedat", 'M', head);
	head = insertNode("Ahmet", 'M', head);
	//call to sorting function
	head = sortList(head);
	printList(head);
}