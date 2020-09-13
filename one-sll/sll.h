#include<stdio.h>


typedef struct Node
{
	int element;
	struct Node* next;
}Node;


typedef struct
{
	struct Node* currentItem;
}SinglyLinkedList;


SinglyLinkedList* createList();

void addFront(SinglyLinkedList* list, const int* value);

void removeFront(SinglyLinkedList* list);

_Bool IsEmpty(const SinglyLinkedList* list);

const int* frontElement(const SinglyLinkedList* list);

void printListItems(const SinglyLinkedList* list);
