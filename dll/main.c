#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include "dll.h"

void performUserSelection(DoublyLinkedList* list, unsigned int option);
void printOptions();
int get_int(unsigned int *px);

int key_match_proton(void* element, void* key);

void print_proton(void* protonItem);

void print_integer(void* intItem);

typedef struct proton
{
	unsigned int id;
	char symbol;
}proton;


int main(int argc, char** argv)
{
	printf("\n\n*****************************************************\n\n");
	printf("\t\t Doubly Linked List \t\t\n\n");
	printf("*****************************************************\n\n");	
	
	DoublyLinkedList * list = createList();
	
	register_print_function(list, print_integer);
	//register_print_function(list, print_proton);	
	register_KeyMatch_Function(list, key_match_proton);
	
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
	//printf("\t11. Find element by key :\n");
	printf("\t10. Exit\n");	
}

void performUserSelection(DoublyLinkedList* list, unsigned int option)
{
	switch(option)
	{
		case 1:
		{
			print_dll(list);
			break;
		}
		case 2:
		{
			int* userInput = (int*)malloc(sizeof(int));
			printf("\nEnter the element to add.\n");
			scanf("%d", userInput);
			void* pass = (void*)(userInput);
			
			//********
			
			//proton* proton_one = (proton*)malloc(sizeof(proton));
			//proton_one->id = 454;
			//proton_one->symbol = 'T';
			
			//proton* proton_two = (proton*)malloc(sizeof(proton));
			//proton_two->id = 600;
			//proton_two->symbol = 'X';
			
			//proton* proton_three = (proton*)malloc(sizeof(proton));
			//proton_three->id = 999;
			//proton_three->symbol = 'S';	
					
			//addFront(list, proton_one);
			//addFront(list, proton_two);
			//addFront(list, proton_three);
			
			//********
						
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
			print_dll(reverse(list));
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
		case 11:
		{
			unsigned int* searchKey = (unsigned int*)malloc(sizeof(unsigned int));
			*searchKey = 999;
			
			proton* resultItem = (proton*)searchElementByKey(list, (void*)searchKey);
			if(resultItem)
				print_proton(resultItem);
			else
				printf("\nList is empty\n");				
			break;
		}
		default:
			printf("\nPlease select apprapriate option...\n");
	}
}

void print_integer(void* intItem)
{
	int* intItem_local = (int*)intItem;
	printf("\nproton Id : %u \n", *intItem_local);	
}


void print_proton(void* protonItem)
{
	proton* proton_local = (proton*)protonItem;
	printf("\nproton Id : %u \n", proton_local->id);
	printf("proton Symbol : %c \n\n", proton_local->symbol);	
}


int key_match_proton(void* element, void* key)
{
	proton* proton_local = (proton*)element;
	unsigned int* key_local = (unsigned int*)key;
	
	if(proton_local->id == *key_local)
		return 1;
	else 
		return 0;
}







