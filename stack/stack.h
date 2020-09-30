

typedef struct Node
{
	void* element;
	struct Node* next;
}Node;

typedef struct Stack
{
	Node* top;
	int size;
}Stack;

Stack* init_stack();

int size(Stack* stack);

_Bool isEmpty(Stack* stack);

Node* top(Stack* stack);

void push(Stack* stack, void* element);

void pop(Stack* stack);

void destroy_stack(Stack* stack);
