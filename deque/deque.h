#ifndef _DEQUE_H
#define _DEQUE_H

#include "dll.h"


typedef struct Deque
{
	DoublyLinkedList* dequeList;
	int size_of_deque;
}Deque;

Deque* create_deque();

int size_of_deque(Deque* deque);

_Bool is_deque_empty(Deque* deque);

void addFront_deque(Deque* deque, void* element);

void addBack_deque(Deque* deque, void* element);

void removeFront_deque(Deque* deque);

void removeBack_deque(Deque* deque);

void* front_of_deque(Deque* deque);

void* back_of_deque(Deque* deque);

void print_deque(Deque* deque);

void register_print_for_deque(Deque* deque, void (*print_item)(void*));

void destroy_deque(Deque* deque);

#endif
