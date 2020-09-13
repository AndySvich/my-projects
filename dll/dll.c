#include<stdio.h>
#include<stdlib.h>

#include "dll.h"

void removeItem(DoublyLinkedList* list, _Bool isFrontRemoval);
void addItem(DoublyLinkedList* list, const int* value, _Bool isFrontAdd);


DoublyLinkedList* createList()
{
	DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	if(list == NULL)
	{
		printf("Memory allocation failed...try again later\n");
		return NULL;
	}
	
	int value = 0;
	list->header = createNode(&value);
	list->trailer = createNode(&value);
	
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
	
	return list;
}

_Bool IsEmpty(const DoublyLinkedList* list)
{
	return list->header->next == list->trailer;
}

Node* createNode(const int* value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		printf("Memory allocation failed...try again later\n");
		return NULL;
	}
	node->element = *value;
	node->prev = NULL;
	node->next = NULL;
	
	return node;
}

void addFront(DoublyLinkedList* list, const int* value)
{
	addItem(list, value, 1);
}

void addBack(DoublyLinkedList* list, const int* value)
{
	addItem(list, value, 0);
}

void addItem(DoublyLinkedList* list, const int* value, _Bool isFrontAdd)
{
	Node* node = createNode(value);
	if(IsEmpty(list))
	{
		list->header->next = node;
		node->prev = list->header;
		
		list->trailer->prev = node;
		node->next = list->trailer;
	}
	else if(isFrontAdd)
	{
		node->next = list->header->next;
		node->prev = list->header;
		
		list->header->next = node;
		node->next->prev = node;
		
	}
	else
	{
		node->prev = list->trailer->prev;
		list->trailer->prev->next = node;
		
		node->next = list->trailer;
		list->trailer->prev = node;
	}
}

void removeFront(DoublyLinkedList* list)
{
	removeItem(list, 1);
}

void removeBack(DoublyLinkedList* list)
{
	removeItem(list, 0);
}

void removeItem(DoublyLinkedList* list, _Bool isFrontRemoval)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else if(isFrontRemoval)
	{
		Node* firstItem = list->header->next;
		
		list->header->next = firstItem->next;
		firstItem->next->prev = list->header;
		
		free(firstItem);
	}
	else
	{
		Node* lastItem = list->trailer->prev;
		
		list->trailer->prev = lastItem->prev;
		lastItem->prev->next = list->trailer;
		
		free(lastItem);		
	}	
}

const int* getFirstItem(DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return &(list->header->next->element);
	}
}

const int* getLastItem(DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return &(list->trailer->prev->element);
	}
}

void printList(const DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else
	{
		Node* tempCursor = list->header;
		while(tempCursor->next != list->trailer)
		{
			printf("%d ", tempCursor->next->element);
			tempCursor = tempCursor->next;
		}
		printf("\n");
	}
}

DoublyLinkedList* reverse(DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else
	{
		DoublyLinkedList* tempList = createList();
		while(!IsEmpty(list))
		{
			addFront(tempList, getFirstItem(list));
			removeFront(list);
		}
		while(!IsEmpty(tempList))
		{
			addBack(list, getFirstItem(tempList));
			removeFront(tempList);
		}
		destroyList(tempList);
	}
	return list;
}

void destroyList(DoublyLinkedList* list)
{
	while(!IsEmpty(list))
	{
		removeFront(list);
	}
	free(list->header);
	free(list->trailer);	
	free(list);
}




