#include<stdio.h>
#include<stdlib.h>

#include "cll.h"


CircularlyLinkedList* createList()
{
	CircularlyLinkedList* list = (CircularlyLinkedList*)malloc(sizeof(CircularlyLinkedList));
	if(list == NULL)
	{
		return NULL;
	}
	list->cursor = NULL;
	
	return list;	
}

Node* createNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		return NULL;
	}
	
	node->element = NULL;
	node->next = NULL;
	
	return node;
}

_Bool IsEmpty(CircularlyLinkedList* list)
{
	return list->cursor == NULL;
}

void addItem(CircularlyLinkedList* list, void* value)
{
	Node* newNode = createNode();
	newNode->element = value;
	
	if(IsEmpty(list))
	{
		list->cursor = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = list->cursor->next;
		list->cursor->next = newNode;
	}
}

void removeItem(CircularlyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		Node* frontItem = front(list);
		if(frontItem == list->cursor)
		{
			free(frontItem->element);
			free(frontItem);
			list->cursor = NULL;
		}
		else
		{
			list->cursor->next = frontItem->next;
			free(frontItem->element);
			free(frontItem);
		}
	}
}

void advance(CircularlyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		list->cursor = list->cursor->next;
	}
}

Node* front(CircularlyLinkedList* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return list->cursor->next;
	}
}

Node* back(CircularlyLinkedList* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return list->cursor;
	}
}

void printList(CircularlyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		Node* tempCursor = list->cursor->next;
		do
		{
			printf("%d ", *(int*)tempCursor->element); // deferencing to integer pointer as testing for integer values
			// use function pointers for custom data printing...
			tempCursor = tempCursor->next;
		}while(tempCursor != list->cursor->next);
		
		printf("\n");
	}
}

void destroyList(CircularlyLinkedList* list)
{
	while(!IsEmpty(list))
	{
		removeItem(list);
	}
	free(list);
}
