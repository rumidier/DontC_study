/* 2^k <= n ���� ������ �����ϴ� ������ ��n�� ���� �ִ� k�� */
#include <stdio.h>

void main()
{
	int iNumber = 0;
	int i = 0;
	printf("������ ���� n�� �Է� �ϼ���:");
	scanf("%d", &iNumber);
	fflush(stdin);

	for(i = 1; ;++i)
	{
		iNumber = iNumber/2;
		if(iNumber == 1)
			break;
	}
	printf("������ �����ϴ� k = %d\n", i);
}