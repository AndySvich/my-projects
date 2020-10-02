#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include "cll.h"

void performUserSelection(CircularlyLinkedList* list, unsigned int option);
void printOptions();
int get_int(unsigned int *px);

int main(int argc, char** argv)
{
	printf("\n\n*****************************************************\n\n");
	printf("\t\t Circularly Linked List \t\t\n\n");
	printf("*****************************************************\n\n");	
	
	CircularlyLinkedList* list = createList();
	
	unsigned int option = 0;
	
	printOptions();
	
	while(option != 8)
	{
		//printOptions();
		get_int(&option);
		if(option != 8)
			performUserSelection(list, option);
	}
		
	if(option == 8) 
		system("clear");
	
	destroyList(list);
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
	printf("\t5. Display the last element of the list\n");
	printf("\t6. Advance the cursor\n");
	printf("\t7. Check if list is empty\n");		
	printf("\t8. Exit\n");	
}

void performUserSelection(CircularlyLinkedList* list, unsigned int option)
{
	switch(option)
	{
		case 1:
		{
			printList(list);
			break;
		}
		case 2:
		{
			int* userInput = (int*)malloc(sizeof(int));
			printf("\nEnter the element to add.\n");
			scanf("%d", userInput);
			addItem(list, userInput);
			break;
		}
		case 3:
		{
			removeItem(list);
			break;
		}
		case 4:
		{
			Node* firselement = front(list);
			if(firselement != NULL)
				printf("\nFirst element %d\n", *(int*)(firselement->element));
			else
				printf("\nList is Empty\n");
			break;
		}
		case 5:
		{
			Node* lastelement = back(list);
			if(lastelement != NULL)
				printf("\nLast element %d\n", *(int*)(lastelement->element));
			else
				printf("\nList is Empty\n");
			break;
		}
		case 6:
		{
			advance(list);
			break;
		}		
		case 7:
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



