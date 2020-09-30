#include<stdlib.h>
#include<stdio.h>

#include "stack.h"

int size(Stack* stack)
{
	return stack->size;
}

Node* create_node()
{
	Node* node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		return NULL;
	}
	node->element = NULL;
	node->next = NULL;
	
	return node;
}

Stack* init_stack()
{
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	if(newStack == NULL)
	{
		return NULL;		
	}
	newStack->top = NULL;
	newStack->size = 0;

	return newStack;
}

_Bool isEmpty(Stack* stack)
{
	return stack->size == 0;
}

Node* top(Stack* stack)
{
	return stack->top;
}

void push(Stack* stack, void* element)
{
	Node* node = create_node();
	node->element = element;
	if(!isEmpty(stack))
	{
		node->next = stack->top;
	}
	stack->top = node;
	stack->size++;
}

void pop(Stack* stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is empty...\n");
	}
	Node* topElement = top(stack);
	stack->top = topElement->next;
	stack->size--;
	free(topElement);
}

void destroy_stack(Stack* stack)
{
	while(!isEmpty(stack))
	{
		pop(stack);
	}
	free(stack);
}



