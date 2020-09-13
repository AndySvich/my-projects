#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include "sll.h"


void performUserSelection(SinglyLinkedList* list, unsigned int option);
void printOptions();
int get_int(unsigned int *px);

int main(int argc, char** argv)
{
	printf("\n\n*****************************************************\n\n");
	printf("\t\t Singly Linked List \t\t\n\n");
	printf("*****************************************************\n\n");	
	
	SinglyLinkedList * list = createList();
	
	unsigned int option = 0;
	
	while(option != 6)
	{
		printOptions();
		get_int(&option);
		if(option != 6)
			performUserSelection(list, option);
	}
		
	if(option == 6) 
		system("clear");
	return 0;
}

int get_int(unsigned int *px)
{
  while (!scanf("%d",px)&& !isspace((int)*px) && getchar()!= '\n'){
    printf("Please enter an integer value:\n");
  }
 }

void printOptions()
{
	printf("\nPlease select below option...\n");
	printf("\t1. Print the list items\n");
	printf("\t2. Add item to list\n");	
	printf("\t3. Remove First element from the list\n");	
	printf("\t4. Display the first element of the list\n");
	printf("\t5. Check if list is empty\n");		
	printf("\t6. Exit\n");	
}

void performUserSelection(SinglyLinkedList* list, unsigned int option)
{
	switch(option)
	{
		case 1:
		{
			printListItems(list);
			break;
		}
		case 2:
		{
			int userInput = 0;
			printf("\nEnter the element to add.\n");
			scanf("%d", &userInput);
			addFront(list, &userInput);
			break;
		}
		case 3:
		{
			removeFront(list);
			break;
		}
		case 4:
		{
			const int* firselement = frontElement(list);
			if(firselement != NULL)
				printf("\nFirst element %d\n", *(firselement));
			else
				printf("\nList is Empty\n");
			break;
		}
		case 5:
		{
			if(IsEmpty(list))
			{
				printf("\nList is empty\n");
			}
			else
			{
				printf("\nList is not empty\n");
				printf("\n");
			}
			break;
		}
		default:
			printf("\nPlease select apprapriate option...\n");
	}
}



