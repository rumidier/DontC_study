/* 입력받은 초를 [시,분,초]의 형태로 출력하는 프로그램 */
#include <stdio.h>

void main()
{
	int iHourRes = 0;
	int iMinRes = 0;
	int iSecRes = 0;
	int iSec = 0;
	
	while(1)
	{
		printf("초(second)를 입력 하세요:(0:종료)");
		scanf("%d", &iSec);
		fflush(stdin);
		
		if(iSec == 0)
		{
			printf("종료!\n");
			return;
		}
		else if(iSec < 0)
		{
			printf("-값을 입력 하셨습니다.\n");
		}
		else
		{
			iHourRes = iSec/3600;
			iMinRes = (iSec%3600)/60;
			iSecRes = (iSec%3600)%60;
			
			printf("[%d시 %d분 %d초]\n", iHourRes, iMinRes, iSecRes);
		}
	}
}