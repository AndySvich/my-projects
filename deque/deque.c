#include<stdio.h>
#include<stdlib.h>

#include "deque.h"
#include "dll.h"

Deque* create_deque()
{
	Deque* deque = (Deque*)malloc(sizeof(Deque));
	if(deque == NULL)
	{
		printf("Memory allocation failed...");
		return NULL;
	}
	deque->dequeList = createList();
	deque->size_of_deque = 0;
	
	return deque;
}

int size_of_deque(Deque* deque)
{
	return deque->size_of_deque;
}

_Bool is_deque_empty(Deque* deque)
{
	return deque->size_of_deque == 0;
}

void addFront_deque(Deque* deque, void* element)
{
	addFront(deque->dequeList, element);
}

void addBack_deque(Deque* deque, void* element)
{
	addBack(deque->dequeList, element);
}

void removeFront_deque(Deque* deque)
{
	removeFront(deque->dequeList);
}

void removeBack_deque(Deque* deque)
{
	removeBack(deque->dequeList);
}

void* front_of_deque(Deque* deque)
{
	getFirstItem(deque->dequeList);
}

void* back_of_deque(Deque* deque)
{
	getLastItem(deque->dequeList);
}

void register_print_for_deque(Deque* deque, void (*print_item)(void*))
{
	register_print_function(deque->dequeList, print_item);
}

void print_deque(Deque* deque)
{
	print_dll(deque->dequeList);
}

void destroy_deque(Deque* deque)
{
	destroyList(deque->dequeList);
	free(deque);
	
}
