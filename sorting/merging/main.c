#include<stdio.h>
#include<stdlib.h>

int * merge(int A[], int B[], int m, int n)
{
	int size = m + n;
	int* fArray = (int*)malloc(sizeof(int) * size);
	int i = 0 , j = 0 , k = 0;
	while(k < size)
	{
		if(i < m && j < n)
		{
			if(A[i] <= B[j])
				fArray[k++] = A[i++];
			else
				fArray[k++] = B[j++];
		}
		else if(i >= m)
		{
			while(j < n)
				fArray[k++] = B[j++];
		}
		else if(j >= n)
		{
			while(i < n)
				fArray[k++] = A[i++];
		}
	}
	return fArray;
}

int main(int argc, char** argv)
{
	int size1 = 4;
	int size2 = 6;
	int* array1 = (int*)malloc(sizeof(int) * size1);
	int* array2 = (int*)malloc(sizeof(int) * size2);

	int k = 0;
	while(k < size1)
	{
		printf("Enter an element for Array 1 : \n");
		scanf("%d", &array1[k]);
		k++;
	}

	int j = 0;
	while(j < size2)
	{
		printf("Enter an element for Array 2 : \n");
		scanf("%d", &array2[j]);
		j++;
	}

	printf("****** Input Array - 1 ****** \n");
	for(int i = 0 ; i < size1 ; i++)
	{
		printf("%d ", array1[i]);
	}	


	printf("\n ****** Input Array - 2 ****** \n");
	for(int m = 0 ; m < size2 ; m++)
	{
		printf("%d ", array2[m]);
	}

	int* fArray = merge(array1, array2, size1, size2);

	printf("\n ****** Merged Array ****** \n");
	for(int i = 0 ; i < (size1 + size2) ; i++)
	{
		printf("%d ", fArray[i]);
	}

	return 0;
}
