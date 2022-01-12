#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5


int main()
{
	//int my_arr[SIZE];

	//// prepare for array data
	//for (int i = 0; i < SIZE; ++i) // index
	//	my_arr[i] = i * i;
	//
	//// print array data
	//for (int i = 0; i < SIZE; ++i)
	//	printf("%d ", my_arr[i]);

	////TODO: try debugger

	/* Example */

	// my code

	int num[SIZE];
	int sum = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		printf("Enter %d numbers : ", SIZE);
		scanf("%d", &num[i]);
		sum += num[i];
	}

	
	printf("Sum = %d\n", sum);

	// recommand code
	// 많은 데이터에서는 for문을 쪼개는게 더 좋을 수 있다

	/*
	int numbers[SIZE];
	int sum = 0;
	int i;

	printf("Enter %d numbers : ", SIZE);

	for (i = 0; i < SIZE; ++i)
		scanf("%d", &numbers[i]);

	for (i = 0; i < SIZE; ++i)
		sum += numbers[i];

	printf("Sum = %d\n", sum);
	*/

	return 0;
}