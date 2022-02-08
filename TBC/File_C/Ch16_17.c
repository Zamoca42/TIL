#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdarg.h> // Variable Arguments

double average(int, ...);
double average2(char* format_string, ...);

int main()
{
	double a, b;

	a = average(3, 1.1, 2.2, 3.3);
	b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

	printf("%lf\n, a");
	printf("%lf\n, b");

	return 0;
}

double average(int num, ...)
{
	va_list ap;
	double sum = 0.0;
	int i;

	va_start(ap, num);
	for (i = 0; i < num; i++)
		sum += va_arg(ap, double);
	va_end(ap);

	return sum / (double)num;
}

double average2(char* format_string, ...)
{
	int num = strlen(format_string);

	va_list ap;
	double sum = 0.0;
	int i;

	va_start(ap, format_string);
	for (i = 0; i < num; i++)
		sum += va_arg(ap, double);
	va_end(ap);

	return sum / (double)num;
}