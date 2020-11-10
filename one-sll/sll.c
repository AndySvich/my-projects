#include<stdio.h>
#include<stdlib.h>

#include "sll.h"


SinglyLinkedList* createList()
{
	SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	if(list == NULL)
	{
		printf("\nMemory allocation failed...try again later!\n");
		return NULL;
	}
	else
	{
		list->currentItem = NULL;
		return list;
	}
}

void addFront(SinglyLinkedList* list, const int* value)
{
	Node* newElement = (Node*)malloc(sizeof(Node));
	if(newElement == NULL)
	{
		printf("\nAdding new element failed...try again");
		return;
	}
	newElement->element = *value;
	newElement->next = list->currentItem;
	
	list->currentItem = newElement;
	
	printf("\n%d is added to the list.\n", *value);
}

void removeFront(SinglyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty!\n");
	}
	else
	{
		Node* oldItem = list->currentItem;
		list->currentItem = list->currentItem->next;
		free(oldItem);
	}
}

_Bool IsEmpty(const SinglyLinkedList* list)
{
	return list->currentItem == NULL;
}

const int* frontElement(const SinglyLinkedList* list)
{
	return !IsEmpty(list) ? &(list->currentItem->element) : NULL;
}

void printListItems(const SinglyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty!\n");
	}
	else
	{
		Node* temp = list->currentItem;
		
		printf("\nList Items are...\n");
		while(temp != NULL)
		{
			printf("%d ", temp->element);
			temp = temp->next;
		}
		printf("\n");
		temp = NULL;
	}
}



