#ifndef _Queue_H
#define _Queue_H

#include "cll.h"

//typedef CircularlyLinkedList Queue;

typedef struct Queue
{
	CircularlyLinkedList* QueueList;
	int size_of_queue;
}Queue;

Queue* init_queue();

_Bool is_queue_empty(Queue* queue);

void enqueue(Queue* queue, void* element);

void dequeue(Queue* queue);

void* front_of_queue(Queue* queue);

void* back_of_queue(Queue* queue);

int size_of_queue(Queue* queue);

void print_queue(Queue* queue);

void destroy_queue(Queue* queue);

#endif
