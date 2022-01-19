#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12 // symbolic constants, macro

int main()
{
	/* Basic usage */
	int high[12] = { 2, 5, 11, 18, 23, 26, 29, 30, 26, 20, 12, 6 };
	
	for (int i = 0; i < MONTHS; ++i)
		printf("%d ", high[i]);
	printf("\n");

	float avg = 0.0;
	for (int i = 0; i < MONTHS; ++i)
		avg += high[i];
	printf("Average = %f\n", avg / (float)MONTHS);

	high[0] = 1;
	high[1] = 2;
	//선언이 끝나면 하나씩 입력 해주어야함
	//high[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // not working

	/* Addresses */
	printf("%p %p\n", high, &high[0]);
	for (int i = 0; i < MONTHS; ++i)
		printf("%lld\n", (long long)&high[i]);
	printf("\n");



	return 0;
}