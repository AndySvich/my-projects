#include<stdio.h>
#include<stdlib.h>

void insertionSort(int A[], int n, int isAscending)
{
	for(int i = 1; i < n ; i++)
	{
		int temp = A[i];
		int k = i;
		for(int j = i - 1; j >= 0 ; j--)
		{
			if(isAscending)
			{
				if(temp < A[j])
				{
					A[i] = A[j];
					i--;
				}
			}
			else
			{
				if(temp > A[j])
				{
					A[i] = A[j];
					i--;
				}				
			}
			
		}
		A[i] = temp;
		i = k;
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

	insertionSort(array, size, 0);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}


	printf("\n\n ****** Sorted Array (Ascending) ****** \n");

	insertionSort(array, size, 1);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}	

	return 0;
}
