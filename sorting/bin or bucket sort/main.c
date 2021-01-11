#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int element;
	struct Node* next;
}Node;

int maxElement(int A[], int size)
{
	int max = A[0];
	for(int i = 1 ; i < size; i++)
	{
		if(max < A[i])
			max = A[i];
	}
	return max;
}

void binSort(int A[], int size)
{
	int max = maxElement(A, size);
	Node** fArray = (Node**)malloc(sizeof(Node) * (max + 1));
	for(int i = 0 ; i < max+1; i++)
	{
		fArray[i] = NULL;
	}

	printf("\n\n");

	for(int i = 0 ; i < max+1; i++)
	{
		printf("%p ", fArray[i]);
	}	

	printf("\n\n");

	for(int i = 0 ; i < size; i++)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->element = A[i];
		node->next = NULL;

		Node* x = fArray[A[i]];
		while(x && x->next)
			x = x->next;
		if(x) x->next = node;
		else
			fArray[A[i]] = node;
	}

	printf("\n\n");

	for(int i = 0 ; i < max+1; i++)
	{
		printf("%p ", fArray[i]);
	}	

	printf("\n\n");	

	// for(int i = 0 ; i < max+1; i++)
	// {
	// 	Node* x = fArray[i];
	// 	while(x)
	// 	{
	// 		printf("%d ", x->element);
	// 		x = x->next;
	// 	}
	// }

	// printf("\n\n");

	int index = 0;
	for(int i = 0 ; i < max+1; i++)
	{
		while(fArray[i])
		{
			int number = fArray[i]->element;
			fArray[i] = fArray[i]->next;
			A[index++] = number;
		}
	}
	free(fArray);
}

int main(int argc, char** argv)
{
	int size = 10;
	int* array = (int*)malloc(sizeof(int) * size);

	int k = 0;
	while(k < size)
	{
		printf("Enter an element for Array : \n");
		scanf("%d", &array[k]);
		k++;
	}

	printf("****** Input Array ****** \n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	binSort(array, size);

	printf("\n ****** Bin/Bucket Sort Output ****** \n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
