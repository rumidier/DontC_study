/* 두개의 숫자를 입력 받아 G.C.M(최대 공약수) 구하는 프로그램 */
#include <stdio.h>

void main()
{
	int iFirstNum = 0;
	int iSecondNum = 0;
	int i = 0;
	while(1)
	{
		printf("첫번째 숫자: ");
		scanf("%d", &iFirstNum);
		fflush(stdin);
		
		printf("두번째 숫자: ");
		scanf("%d", &iSecondNum);
		fflush(stdin);
		
		if(iFirstNum == 0 || iSecondNum == 0)
		{
			puts("최대 공약수를 구할수 없습니다. 다시 입력해주세요.");
		}
		else if(iFirstNum < iSecondNum)
		{
			for(i = iFirstNum; ; --i)
			{
				if(iFirstNum % i == 0 && iSecondNum % i == 0)
				{
					printf("G.C.M(최대 공약수) = %d\n", i);
					break;
				}
			}
		}
		else
		{
			for(i = iSecondNum; ; --i)
			{
				if(iFirstNum % i == 0 && iSecondNum % i == 0)
				{
					printf("G.C.M(최대 공약수) = %d\n", i);
					break;
				}
			}
		}
	}
	
	
}