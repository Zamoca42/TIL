// #define _CRT_SECURE_NO_WARNINGS
// Property -> preprocessor -> Debug에 _CRT_SECURE_NO_WARNINGS 추가

#include<stdio.h>

int main()
{
	int i = 0, j = 0;
	int sum = 0;

	printf("Input two integers\n");

	scanf("%d%d", &i, &j); //& : ampersand
	//메모리 주소를 직접 접근하기때문에 보안 위험
	//microsoft에서는 scanf_s 권장

	sum = i + j;

	printf("%d Plus %d = %d\n", i, j, sum);

	return 0;
}
