#include<stdio.h>

typedef struct Node
{
	int element;
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

Node* createNode(const int* value);

void addFront(DoublyLinkedList* list, const int* value);

void addBack(DoublyLinkedList* list, const int* value);

void printList(const DoublyLinkedList* list);

void removeFront(DoublyLinkedList* list);

void removeBack(DoublyLinkedList* list);

const int* getFirstItem(DoublyLinkedList* list);

const int* getLastItem(DoublyLinkedList* list);

DoublyLinkedList* reverse(DoublyLinkedList* list);

void destroyList(DoublyLinkedList* list);
