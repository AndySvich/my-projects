#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include "dll.h"

void performUserSelection(DoublyLinkedList* list, unsigned int option);
void printOptions();
int get_int(unsigned int *px);

int main(int argc, char** argv)
{
	printf("\n\n*****************************************************\n\n");
	printf("\t\t Doubly Linked List \t\t\n\n");
	printf("*****************************************************\n\n");	
	
	DoublyLinkedList * list = createList();
	
	unsigned int option = 0;
	
	while(option != 10)
	{
		printOptions();
		get_int(&option);
		if(option != 10)
			performUserSelection(list, option);
	}
		
	if(option == 10) 
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
	printf("\t2. Add item to front of list\n");	
	printf("\t3. Add item to back of list\n");	
	printf("\t4. Remove First element from the list\n");	
	printf("\t5. Remove Last element from the list\n");		
	printf("\t6. Display the first element of the list\n");
	printf("\t7. Display the last element of the list\n");
	printf("\t8. Reverse and print the list\n");	
	printf("\t9. Check if list is empty\n");		
	printf("\t10. Exit\n");	
}

void performUserSelection(DoublyLinkedList* list, unsigned int option)
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
			int userInput = 0;
			printf("\nEnter the element to add.\n");
			scanf("%d", &userInput);
			addFront(list, &userInput);
			break;
		}
		case 3:
		{
			int userInput = 0;
			printf("\nEnter the element to add.\n");
			scanf("%d", &userInput);
			addBack(list, &userInput);
			break;
		}		
		case 4:
		{
			removeFront(list);
			break;
		}
		case 5:
		{
			removeBack(list);
			break;
		}		
		case 6:
		{
			const int* firstelement = getFirstItem(list);
			if(firstelement != NULL)
				printf("\nFirst element %d\n", *(firstelement));
			else
				printf("\nList is Empty\n");
			break;
		}
		case 7:
		{
			const int* lastelement = getLastItem(list);
			if(lastelement != NULL)
				printf("\nFirst element %d\n", *(lastelement));
			else
				printf("\nList is Empty\n");
			break;
		}
		case 8:
		{
			printList(reverse(list));
			break;
		}				
		case 9:
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



