/* 2^n���� ���ϴ� �Լ��� ��������� ������ ���� */
#include <stdio.h>
int Multiply(int iNum, int iAns)
{
	if(iNum == 1)
	{
		return iAns;								
	}

	iAns = iAns*2;
	Multiply(iNum-1, iAns);
}
void main()
{
	int iNum = 0;
	int iAns = 2;
	printf("���� �Է�:");
	scanf("%d", &iNum);
	fflush(stdin);

	printf("2�� %d���� %d\n", iNum, Multiply(iNum, iAns));
}