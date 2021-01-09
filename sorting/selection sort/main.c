#include<stdio.h>
#include<stdlib.h>

void selectionSort(int A[], int n, int isAscending)
{
	for(int i = 0; i < n ; i++)
	{
		int j = i, k = i;
		for(j = k+1; j < n ; j++)
		{
			if(isAscending)
			{
				if(A[j] < A[k])
					k = j;
			}
			else
			{
				if(A[j] > A[k])
					k = j;				
			}				
		}
		if(i != k)
		{
			int temp = A[i];
			A[i] = A[k];
			A[k] = temp;			
		}
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

	selectionSort(array, size, 0);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}


	printf("\n\n ****** Sorted Array (Ascending) ****** \n");

	selectionSort(array, size, 1);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}	

	return 0;
}
