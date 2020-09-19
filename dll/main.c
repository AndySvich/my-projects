#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include "dll.h"

void performUserSelection(DoublyLinkedList* list, unsigned int option);
void printOptions();
int get_int(unsigned int *px);

void printListLocal(const DoublyLinkedList* list);

int main(int argc, char** argv)
{
	printf("\n\n*****************************************************\n\n");
	printf("\t\t Doubly Linked List \t\t\n\n");
	printf("*****************************************************\n\n");	
	
	DoublyLinkedList * list = createList();
	
	unsigned int option = 0;
	
	printOptions();
	
	while(option != 10)
	{
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
			printListLocal(list);
			break;
		}
		case 2:
		{
			int* userInput = (int*)malloc(sizeof(int));
			printf("\nEnter the element to add.\n");
			scanf("%d", userInput);
			void* pass = (void*)(userInput);			
			addFront(list, pass);
			break;
		}
		case 3:
		{
			int* userInput = (int*)malloc(sizeof(int));
			printf("\nEnter the element to add.\n");
			scanf("%d", userInput);
			void* pass = (void*)(userInput);
			addBack(list, pass);
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
			int* firstelement = (int*)getFirstItem(list);
			if(firstelement != NULL)
				printf("\nFirst element %d\n", *(firstelement));
			else
				printf("\nList is Empty\n");
			break;
		}
		case 7:
		{
			int* lastelement = (int*)getLastItem(list);
			if(lastelement != NULL)
				printf("\nFirst element %d\n", *(lastelement));
			else
				printf("\nList is Empty\n");
			break;
		}
		case 8:
		{
			printListLocal(reverse(list));
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

void printListLocal(const DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else
	{
		Node* cursor = list->header;	
		while(cursor->next != list->trailer)
		{
			printf("******************************************\n");
			printf("*\t print node : --->   %p \t *\n", cursor->next);			
			printf("*\t print item : --->   %p \t *\n", cursor->next->element);
			printf("*\t print item : --->   %d \t *\n", *(int*)cursor->next->element);			
			printf("******************************************\n");	
			
			cursor = cursor->next;
			
			if(cursor->next != list->trailer)
			{
				printf("\t\t ^ \t  | \t\t\n");
				printf("\t\t | \t  v \t\t\n");
			}
		}
	}
}



