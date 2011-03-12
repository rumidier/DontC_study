/* 2^k <= n 다음 공식을 만족하는 임의의 값n에 대한 최대 k값 */
#include <stdio.h>

void main()
{
	int iNumber = 0;
	int i = 0;
	printf("임의의 숫자 n을 입력 하세요:");
	scanf("%d", &iNumber);
	fflush(stdin);

	for(i = 1; ;++i)
	{
		iNumber = iNumber/2;
		if(iNumber == 1)
			break;
	}
	printf("공식을 만족하는 k = %d\n", i);
}