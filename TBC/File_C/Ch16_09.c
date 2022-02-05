#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#pragma pack(1)
_Pragma("pack(1)") // destringizing : remove first and last ", \" -> "
//#define PACK1 _Pragma("pack(1)")
//PACK1

//#pragma warning ( disable : 4477)
//#pragma warning ( error : 4477)

struct s {
	int i;
	char ch;
	double d;
};

int main()
{
	struct s A;
	printf("Size of A is : %zd", sizeof(A));


	return 0;
}