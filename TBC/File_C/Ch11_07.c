#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Selection Sort Algorithm
	https://www.geeksforgeeks.org/selection-sort/

	64 25 12 22 11 (min_idx = 0)

*/

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);


int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);	// ascending order

	printArray(arr, n);


	return 0;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int min_index = 0;

	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		swap(&arr[min_index], &arr[i]);
	}
}