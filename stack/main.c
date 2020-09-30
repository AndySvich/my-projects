#include<stdio.h>

#include "stack.h"

int main(int argc, char** argv)
{
	Stack* stack = init_stack();
	
	int value1 = 100;
	push(stack, &value1);
	printf("Stack size is %d \t top : %d \n", stack->size, *(int*)top(stack)->element);
	
	
	int value2 = 200;
	push(stack, &value2);
	printf("Stack size is %d \t top : %d \n", stack->size, *(int*)top(stack)->element);
	
	pop(stack);
	printf("Stack size is %d \t top : %d \n", stack->size, *(int*)top(stack)->element);
	
	
	int value3 = 300;
	push(stack, &value3);
	printf("Stack size is %d \t top : %d \n", stack->size, *(int*)top(stack)->element);


	printf("Top element in Stack is %d \n", *(int*)top(stack)->element);
	
	printf("Is Stack Empty ? : %d\n", isEmpty(stack));

	destroy_stack(stack);	
	
	return 0;
}
