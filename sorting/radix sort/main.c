#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

int digitsInElement(int number)
{
	int i = 0;
	while(number > 10)
	{
		number = number / 10;
		i++;
	}
	return i + 1;
}

void PrintArray(int A[], int size)
{
	for(int i = 0 ; i < size; i++)
	{
		printf("%d ", A[i]);
	}
}

void radixSort(int A[], int size)
{
	Node* fArray[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	int max = maxElement(A, size);
	int count = digitsInElement(max);

	printf("\n %d and %d \n", max, count);

	for(int k = 0 ; k < count; k++)
	{
		for(int i = 0 ; i < size; i++)
		{
			int digit = (A[i] / (int)pow(10, k)) % 10;
			Node* n1 = (Node*)malloc(sizeof(Node));
			n1->element = A[i];
			n1->next = NULL;

			Node* x = fArray[digit];
			while(x && x->next)
				x = x->next;
			if(x) x->next = n1;
			else
				fArray[digit] = n1;
		}

		// for(int i = 0 ; i < 10; i++)
		// {
		// 	Node* x = fArray[i];
		// 	while(x)
		// 	{
		// 		printf("%d ", x->element);
		// 		x = x->next;
		// 	}
		// }
		int index = 0;
		for(int i = 0 ; i < 10; i++)
		{
			while(fArray[i])
			{
				int number = fArray[i]->element;
				fArray[i] = fArray[i]->next;
				A[index++] = number;
			}
		}

		PrintArray(A, size);
		printf("\n\n");
	}
}

int main(int argc, char** argv)
{
	int size = 8;
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

	radixSort(array, size);

	printf("\n ****** Radix Sort Output ****** \n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
