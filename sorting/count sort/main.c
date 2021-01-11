#include<stdio.h>
#include<stdlib.h>

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

void countSort(int A[], int size)
{
	int max = maxElement(A, size);
	int* fArray = (int*)malloc(sizeof(int) * (max + 1));
	for(int i = 0 ; i < max+1; i++)
	{
		fArray[i] = 0;
	}
	for(int i = 0 ; i < size; i++)
	{
		fArray[A[i]]++;
	}
	int index = 0;
	for(int i = 0 ; i < max+1; i++)
	{
		while(fArray[i] > 0)
		{
			A[index++] = i;
			fArray[i]--;
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

	countSort(array, size);

	printf("\n ****** Iterative Merge Sort Output ****** \n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
