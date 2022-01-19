#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main()
{
	double avg_years[YEARS][MONTHS] = { {-3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2},
		{-1.8,-0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9},
		{-4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6}};

	/*
	1. Use 2D array
	2. print data
	3. Calculate and print yearly average temperatures of 3 years
	4. Calculate and print monthly average temperatures of 3 years
	*/

	printf("[Temperature Data]\n");

	for (int j = 0; j < YEARS; ++j)
	{
		for (int i = 0; i < MONTHS; ++i)
			printf("%.1f\t", avg_years[j][i]);
		
		printf("\n");
	}
	printf("\n");

	printf("[Yearly average temperatures of 3 years]\n");
	for (int j = 0; j < YEARS; ++j)
	{
		double avg_temp = 0.0;

		for (int i = 0; i < MONTHS; ++i)
		{
			avg_temp += avg_years[j][i];
		}
		avg_temp /= (double)MONTHS;
		
		printf("Year %d : average temperature = %.1f\n", j, avg_temp);
	}
	printf("\n");

	printf("[Monthly average temperatures for 3 years]\n");
	
	for (int i = 0; i < MONTHS; ++i)
	{
		double avg_temp = 0.0;

		for (int j = 0; j < YEARS; ++j)
		{
			avg_temp += avg_years[j][i];
		}
		avg_temp /= (double)YEARS;
		printf("\t%.1f",avg_temp);
	}
	printf("\n");


	return 0;
}