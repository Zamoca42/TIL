#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count()
{
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
}

void static_count()
{
	static int ct = 0;	// initialized only once!
	printf("static count = %d %lld\n", ct, (long long)& ct);
	ct++;
}

void count_caller()
{
	count();
}

void static_count_caller()
{
	static_count();
}

int main()
{
	count();
	count();
	count_caller();

	static_count();
	static_count();
	static_count_caller();

	return 0;
}