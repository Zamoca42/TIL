#include <stdio.h>
#include <limits.h>


int main()
{
	//unsigned int i = 0;

	//printf("%u\n", sizeof(unsigned int));
	//printf("%u\n", sizeof(i));

	//unsigned int i = 0b11111111111111111111111111111111;
	//unsigned int u = UINT_MAX;

	//printf("%u\n", i);
	//printf("%u\n", u);

	/*unsigned int u_max = UINT_MAX;
	unsigned int u_min = 0;
	signed int i_max = INT_MAX;
	signed int i_min = INT_MIN;

	printf("max of uint = %u\n", u_max);
	printf("min of uint = %u\n", u_min);
	printf("max of int = %d\n", i_max);
	printf("min of int = %d\n", i_min);*/

	unsigned int u_max = UINT_MAX;

	// 1111 + 1 = 10000
	// 0000 - 1 = 1111

	// printf("%u", u_max);

	// i to binary representation
	char buffer[33];
	_itoa(u_max, buffer, 2);

	//print decimal and binary
	printf("decimal: %u\n", u_max);
	printf("binary: %s\n", buffer);

	return 0;
}