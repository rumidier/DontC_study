/* 사용자로 부터 두개의 숫자를 입력받아 구구단을 출력 하는 프로그램 */
#include <stdio.h>
#include <conio.h>
void Multiplication(int iSmall, int iBig)
{
	int i;
	for( ; iSmall <= iBig; ++iSmall)
	{
		printf("[%d 단]\n", iSmall);
		for(i = 1; i < 10; ++i)
		{
			printf("%d X %d = %d\n", iSmall, i, iSmall*i);
		}
		
	}

}
void main()
{
	int iFrist = 0;
	int iSecond = 0;
	int i = 0;

	while(1)
	{
		printf("첫번째 수 : ");
		scanf("%d", &iFrist);
		fflush(stdin);
		
		printf("두번째 수 : ");
		scanf("%d", &iSecond);
		fflush(stdin);
		if(iFrist == 0 || iSecond == 0)
		{
			puts("0은 입력할수 없습니다. 다시 입력 하세요.");
		}
		else
		{
			if(iFrist < iSecond)
			{
				Multiplication(iFrist, iSecond);
			}
			else
			{
				Multiplication(iSecond, iFrist);
			}
		}
		puts("Enter키를 누르세요.");
		getchar();
		system("cls");
	}	
}