#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int low, int mid, int high)
{
	int size = high - low + 1;
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

	free(fArray);
}

void mergeSort(int A[], int size)
{
    int p;
    for (p = 2; p <= size; p = p * 2)
	{
        for (int i = 0; i + p - 1 < size; i = i + p)
		{
            int low = i;
            int high = i + p - 1;
            int mid = (low + high) / 2;
            merge(A, low, mid, high);
        }
    }
    if (p / 2 < size)
	{
        merge(A, 0, p / 2 - 1, size-1);
    }
}

int main(int argc, char** argv)
{
	int size = 9;
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

	mergeSort(array, size);

	printf("\n ****** Merged Array ****** \n");
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
