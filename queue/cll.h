#ifndef _CLL_H
#define _CLL_H

typedef struct Node
{
	void* element;
	struct Node* next;
}Node;

typedef struct CircularlyLinkedList
{
	Node* cursor;
}CircularlyLinkedList;


CircularlyLinkedList* createList();

Node* createNode();

_Bool IsEmpty(CircularlyLinkedList* list);

void addItem(CircularlyLinkedList* list, void* value);

void removeItem(CircularlyLinkedList* list);

void advance(CircularlyLinkedList* list);

Node* front(CircularlyLinkedList* list);

Node* back(CircularlyLinkedList* list);

void printList(CircularlyLinkedList* list);

void destroyList(CircularlyLinkedList* list);

#endif
