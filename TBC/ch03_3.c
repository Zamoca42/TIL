// #define _CRT_SECURE_NO_WARNINGS
// Property -> preprocessor -> Debug�� _CRT_SECURE_NO_WARNINGS �߰�

#include<stdio.h>

int main()
{
	int i = 0, j = 0;
	int sum = 0;

	printf("Input two integers\n");

	scanf("%d%d", &i, &j); //& : ampersand
	//�޸� �ּҸ� ���� �����ϱ⶧���� ���� ����
	//microsoft������ scanf_s ����

	sum = i + j;

	printf("%d Plus %d = %d\n", i, j, sum);

	return 0;
}