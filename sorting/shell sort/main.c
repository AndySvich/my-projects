#include<stdio.h>
#include<stdlib.h>

void swap(int* one, int* two)
{
	int temp = *one;
	*one = *two;
	*two = temp;
}

void swapItems(int A[], int i, int j, int currentStep)
{
	while(i >= 0)
	{
		if(A[j] < A[i])
		{
			swap(&A[i], &A[j]);
			j = i;
			i -= currentStep;
		}
		else
			break;
		
	}
}

void insertionSort(int A[], int n)
{
	int currentStep = n / 2;
	for(currentStep; currentStep > 0; currentStep /= 2)
	{
		int i = 0, j = i + currentStep;
		while(j < n)
		{
			swapItems(A, i, j, currentStep);
			i++;
			j++;
		}
	}
}

int main(int argc, char** argv)
{
	int size = 9;
	int* array = (int*)malloc(sizeof(int) * size);

	int i = 0;
	while(i < size)
	{
		printf("Enter an element : \n");
		scanf("%d", &array[i]);
		i++;
	}

	printf("\n\n****** Input Array ****** \n");

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n\n****** Sorted Array (Ascending) ****** \n");

	insertionSort(array, size);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}	

	return 0;
}
