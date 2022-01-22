#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp()

void swap(char** xp, char** yp);	//Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);

	selectionSort(arr, n); // ascending order

	printStringArray(arr, n);

	return 0;
}

void swap(char** xp, char** yp)
{
	char* temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printStringArray(char* arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		puts(arr[i]);
	printf("\n");
}

void selectionSort(char* arr[], int n)
{
	int min_index = 0;

	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(arr[j], arr[min_index]) < 0)
				min_index = j;
		}
		swap(&arr[min_index], &arr[i]);
	}
}