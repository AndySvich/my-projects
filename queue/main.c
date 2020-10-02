#include<stdio.h>
#include<stdlib.h>

#include "queue.h"

int main(int argc, char** argv)
{
	Queue* queue = init_queue();
	
	int* value_one = (int*)malloc(sizeof(int));
	
	*value_one = 100;
	
	enqueue(queue, value_one);
	
	print_queue(queue);
	
	int* value_two = (int*)malloc(sizeof(int));
	
	*value_two = 200;	
	
	enqueue(queue, value_two);
	
	print_queue(queue);
	

	int* value_three = (int*)malloc(sizeof(int));
	
	*value_three = 300;	
	
	enqueue(queue, value_three);
	
	print_queue(queue);
	
	
	int* value_four = (int*)malloc(sizeof(int));
	
	*value_four = 400;	
	
	enqueue(queue, value_four);
	
	print_queue(queue);
	
	
	dequeue(queue);
	
	print_queue(queue);
	
	dequeue(queue);
	
	print_queue(queue);
	
	dequeue(queue);
	
	print_queue(queue);
	
	
	destroy_queue(queue);
	
	return 0;
}
