#include<stdio.h>
#include<stdlib.h>

int partitionArray(int A[], int low, int high)
{
	int i = low;
	int j = high;
	int pivot = A[low];
	do{
		do
		{ 
			i++;
		}while(i < high && A[i] <= pivot);

		do
		{
			j--;
		}while(j >= 0 && A[j] > pivot);

		if(i < j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(i < j);

	printf("\n\nElement At i = %d and Element At j = %d are swapped \n", i , j);

	int temp = A[low];
	A[low] = A[j];
	A[j] = temp;

	printf("Elements after swap\n");
	for(int k = 0 ; k < high ; k++)
	{
		printf("%d ", A[k]);
	}

	return j;
}

void QuickSort(int A[], int low, int high)
{
	int i = 0;
	if(low < high)
	{
		i = partitionArray(A, low, high);
		QuickSort(A, low, i);
		QuickSort(A, i + 1, high);
	}
}

int main(int argc, char** argv)
{
	int size = 10;
	int* array = (int*)malloc(sizeof(int) * size);

	int i = 0;
	while(i < size)
	{
		printf("Enter an element : \n");
		scanf("%d", &array[i]);
		i++;
	}

	printf("****** Input Array ****** \n");

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	QuickSort(array, 0, size);
	printf("\n\n ****** Sorted Array (Ascending) ****** \n");

	printf("\n\n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}	

	return 0;
}
