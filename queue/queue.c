#include<stdio.h>
#include<stdlib.h>

#include "cll.h"
#include "queue.h"


Queue* init_queue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if(queue == NULL)
	{
		printf("Memory allocation failed\n");
		return NULL;
	}
	
	queue->QueueList =  createList();
	queue->size_of_queue = 0;
	
	return queue;
}


_Bool is_queue_empty(Queue* queue)
{
	return queue->size_of_queue == 0;
}

void enqueue(Queue* queue, void* element)
{
	addItem(queue->QueueList, (int*)element);
	advance(queue->QueueList);
	queue->size_of_queue++;
}

void dequeue(Queue* queue)
{
	removeItem(queue->QueueList);
	queue->size_of_queue--;
}

void* front_of_queue(Queue* queue)
{
	Node* node = front(queue->QueueList);
	return node->element;
}

void* back_of_queue(Queue* queue)
{
	Node* node = back(queue->QueueList);
	return node->element;
}

int size_of_queue(Queue* queue)
{
	return queue->size_of_queue;
}


void destroy_queue(Queue* queue)
{
	destroyList(queue->QueueList);
	free(queue);
}


void print_queue(Queue* queue)
{
	printList(queue->QueueList);
}





