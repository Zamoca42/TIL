#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("Input array length : ");
	scanf("%d", &n);

	float my_arr[n];

	for (int i = 0; i < n; ++i)
		my_arr[i] = (float)i;
	for (int i = 0; i < n; ++i)
		printf("%f\n", my_arr[i]);

	return 0;
}