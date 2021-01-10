#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int low, int mid, int high)
{
	int size = high + 1;
	int* fArray = (int*)malloc(sizeof(int) * size);
	int i = low , j = mid + 1 , k = 0;
	while(k < size)
	{
		if(i <= mid && j <= high)
		{
			if(A[i] <= A[j])
				fArray[k++] = A[i++];
			else
				fArray[k++] = A[j++];
		}
		else if(i > mid)
		{
			while(j <= high)
				fArray[k++] = A[j++];
		}
		else if(j > high)
		{
			while(i <= mid)
				fArray[k++] = A[i++];
		}
	}
	int a = low;
	for(int m = 0 ; m < size; m++)
	{
		A[a++] = fArray[m];
	}
}

int main(int argc, char** argv)
{
	int size = 10;
	int low = 0;
	int mid = 3;
	int* array = (int*)malloc(sizeof(int) * size);

	int k = 0;
	while(k < size)
	{
		printf("Enter an element for Array 1 : \n");
		scanf("%d", &array[k]);
		k++;
	}

	printf("****** Input Array - 1 ****** \n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	merge(array, low, mid, size - 1);

	printf("\n ****** Merged Array ****** \n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
