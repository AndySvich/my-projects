#include<stdio.h>
#include<stdlib.h>

#include "dll.h"

void removeItem(DoublyLinkedList* list, _Bool isFrontRemoval);
void addItem(DoublyLinkedList* list, void* value, _Bool isFrontAdd);
void destroyNode(Node* node);
Node* createNode();


DoublyLinkedList* createList()
{
	DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	if(list == NULL)
	{
		printf("Memory allocation failed...try again later\n");
		return NULL;
	}
	
	list->header = createNode();
	list->trailer = createNode();
	
	list->print_item = NULL;
	list->key_match = NULL;
	
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
	
	return list;
}

_Bool IsEmpty(const DoublyLinkedList* list)
{		
	return list->header->next == list->trailer;
}

Node* createNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		printf("Memory allocation failed...try again later\n");
		return NULL;
	}
	node->element = NULL;
	node->prev = NULL;
	node->next = NULL;
	
	return node;
}

void addFront(DoublyLinkedList* list, void* value)
{
	addItem(list, value, 1);
}

void addBack(DoublyLinkedList* list, void* value)
{
	addItem(list, value, 0);
}

void addItem(DoublyLinkedList* list, void* value, _Bool isFrontAdd)
{
	Node* node = createNode();
	node->element = value;
	
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
		
		destroyNode(firstItem);
	}
	else
	{
		Node* lastItem = list->trailer->prev;
		
		list->trailer->prev = lastItem->prev;
		lastItem->prev->next = list->trailer;
		
		destroyNode(lastItem);		
	}	
}

void* getFirstItem(DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return list->header->next->element;
	}
}

void* getLastItem(DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return list->trailer->prev->element;
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
		Node* frontCursor = list->header->next;
		Node* backCursor = list->trailer->prev;	
		
		while(frontCursor != backCursor)
		{
			void* temp = backCursor->element;
			
			backCursor->element = frontCursor->element;
			frontCursor->element = temp;
			
			if(frontCursor != backCursor)
			{
				frontCursor = frontCursor->next;
				backCursor = backCursor->prev;		
			}
		}
		
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

void destroyNode(Node* node)
{
	if(node != NULL)
	{
		free(node->element);
		free(node);
	}
}

void register_KeyMatch_Function(DoublyLinkedList* list, int (*key_match)(void*, void*))
{
	list->key_match = key_match;
}


void* searchElementByKey(DoublyLinkedList* list, void* key)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		Node* cursor = list->header->next;
		while(cursor != list->trailer)
		{
			if(list->key_match(cursor->element, key) == 1)
			{
				return cursor->element;
			}
			cursor = cursor->next;
		}
		return NULL;
	}
}


void register_print_function(DoublyLinkedList* list, void (*print_item)(void*))
{
	list->print_item = print_item;
}


void print_dll(DoublyLinkedList* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else if(!list->print_item)
	{
		printf("\nprint function is not defined...\n");
	}
	else
	{
		Node* cursor = list->header->next;
		while(cursor != list->trailer)
		{
			list->print_item(cursor->element);
			cursor = cursor->next;
		}
	}
}

