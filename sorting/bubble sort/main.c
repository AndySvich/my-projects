#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int A[], int n, int isAscending)
{
	for(int i = 0 ; i < n - 1 ; i++)
	{
		_Bool noSwaps = 1;
		for(int j = 0 ; j < n - 1 - i ; j++)
		{
			if(isAscending)
			{
				if(A[j] > A[j + 1])
				{
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;

					noSwaps = 0;
				}
			}
			else
			{
				if(A[j] < A[j + 1])
				{
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;

					noSwaps = 0;
				}
			}
		}
		if(noSwaps)
			break;
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

	printf("\n\n ****** Sorted Array (Descending) ****** \n");

	bubbleSort(array, size, 0);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}


	printf("\n\n ****** Sorted Array (Ascending) ****** \n");

	bubbleSort(array, size, 1);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}	

	return 0;
}
