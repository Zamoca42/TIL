#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>


void int_binary(const int num);

int main()
{
	// 8 bit integer cases
	//											76543210			76543210			76543210
	printf("%hhd\n", 1 << 3);				//  00000001 ->		  0000001???	->		00001000
	printf("%hhd\n", 8 >> 1);				//  00001000 ->         ?00001000	->		00000100

	printf("%hhd\n", -119 >> 3);			//	10001001 ->			???10001001 ->		11110001 (-15)
	printf("%hhd\n",  137 << 3);			//	10001001 ->			???10001001 ->		00010001 (17)

	printf("%hhd\n", -119 << 4);			//  10001001 ->		 10001001????   ->      10010000 (-112)
	printf("%hhd\n",  137 << 4);			//  10001001 ->      10001001????   ->      10010000 (144)

	//Note : the signed result is machine dependent

	int a = 1;
	a <<= 3;
	a >>= 2;

	printf("Unsigned int %u\n", 0xffffffff);
	printf("signed int %d\n", 0xffffffff);
	int_binary(0xffffffff);
	printf("Right shift by 3\n");
	int_binary((signed)0xffffffff >> 3);
	int_binary((unsigned)0xffffffff >> 3);

	printf("\nUnsigned int %u\n", 0x00ffffff);
	printf("\nsigned int %d\n", 0x00ffffff);
	int_binary(0x00ffffff);
	printf("Right shift by 3\n");
	int_binary((signed)0x00ffffff >> 3);
	int_binary((unsigned)0x00ffffff >> 3);

	return 0;
}

void int_binary(const int num)
{
	printf("Decimal  %3d \t== Binary ", num);

	const size_t bit = sizeof(num) * 8;

	for (size_t i = 0; i < bit; ++i)
	{
		const int mask = 1 << (bit - 1 - i);

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}