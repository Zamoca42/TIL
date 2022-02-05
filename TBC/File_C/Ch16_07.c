#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

/*
	#undef
*/

//#define LIMIT 400
//#undef LIMIT	// It's ok to undefine previously NOT defined macro.

#undef NON_DEFINE

//#define TYPE 1

//#if TYPE == 1
//#include "my_function_1.h"
//#elif TYPE == 2
//#include "my_function_2.h"
//#else
//static void my_function()
//{
//	printf("Wrong compile option!");
//}
//#endif

#define REPORT

int sum(int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; ++k)
	{
		s += k;

#ifdef REPORT
		printf("%d %d\n", s, k);
#endif
	}

	return s;
}


int main()
{
	//printf("%d\n", LIMIT);
	printf("\n %d \n", sum(1, 10));

	return 0;
}