/* 2^n승을 구하는 함수를 재귀적으로 구현해 보자 */
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
	printf("정수 입력:");
	scanf("%d", &iNum);
	fflush(stdin);

	printf("2의 %d승은 %d\n", iNum, Multiply(iNum, iAns));
}