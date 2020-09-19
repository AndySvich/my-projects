#include<stdio.h>

typedef struct Node
{
	void* element;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct DoubleLinkedList
{
	Node* header;
	Node* trailer;
}DoublyLinkedList;


DoublyLinkedList* createList();

_Bool IsEmpty(const DoublyLinkedList* list);

Node* createNode();

void addFront(DoublyLinkedList* list, void* value);

void addBack(DoublyLinkedList* list, void* value);

void removeFront(DoublyLinkedList* list);

void removeBack(DoublyLinkedList* list);

void* getFirstItem(DoublyLinkedList* list);

void* getLastItem(DoublyLinkedList* list);

DoublyLinkedList* reverse(DoublyLinkedList* list);

void destroyList(DoublyLinkedList* list);
