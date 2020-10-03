#include<stdio.h>
#include<stdlib.h>

#include "deque.h"


void print_integer(void* intItem)
{
	int* intItem_local = (int*)intItem;
	printf("\nitem : %u \n", *intItem_local);	
}

int main(int argc, char** argv)
{
	Deque* deque = create_deque();
	register_print_for_deque(deque, print_integer);
	
	int* valueOne = (int*)malloc(sizeof(int));
	*valueOne = 100;

	addFront_deque(deque, valueOne);
	
	print_deque(deque);



	int* valuetwo = (int*)malloc(sizeof(int));
	*valuetwo = 200;

	addFront_deque(deque, valuetwo);
	
	print_deque(deque);
	
	
	int* valuethree = (int*)malloc(sizeof(int));
	*valuethree = 300;

	addFront_deque(deque, valuethree);
	
	print_deque(deque);
	
	
	printf("front of queue %d\n", *(int*)front_of_deque(deque));
	printf("back of queue %d\n", *(int*)back_of_deque(deque));
	
	
	removeFront_deque(deque);
	print_deque(deque);
	removeBack_deque(deque);
	print_deque(deque);
	
	
	
	destroy_deque(deque);
	return 0;
}
