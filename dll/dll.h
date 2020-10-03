#include<stdio.h>

typedef struct Node
{
	void* element;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct DoublyLinkedList
{
	Node* header;
	Node* trailer;
	int (*key_match)(void*, void*);
	void (*print_item)(void*);
}DoublyLinkedList;


DoublyLinkedList* createList();

_Bool IsEmpty(const DoublyLinkedList* list);

void addFront(DoublyLinkedList* list, void* value);

void addBack(DoublyLinkedList* list, void* value);

void removeFront(DoublyLinkedList* list);

void removeBack(DoublyLinkedList* list);

void* getFirstItem(DoublyLinkedList* list);

void* getLastItem(DoublyLinkedList* list);

DoublyLinkedList* reverse(DoublyLinkedList* list);

void destroyList(DoublyLinkedList* list);

void register_KeyMatch_Function(DoublyLinkedList* list, int (*key_match)(void*, void*));

void register_print_function(DoublyLinkedList* list, void (*print_item)(void*));

void* searchElementByKey(DoublyLinkedList* list, void* key);

void print_dll(DoublyLinkedList* list);
