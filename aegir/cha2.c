/* ����ڷ� ���� �ΰ��� ���ڸ� �Է¹޾� �������� ��� �ϴ� ���α׷� */
#include <stdio.h>
#include <conio.h>
void Multiplication(int iSmall, int iBig)
{
	int i;
	for( ; iSmall <= iBig; ++iSmall)
	{
		printf("[%d ��]\n", iSmall);
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
		printf("ù��° �� : ");
		scanf("%d", &iFrist);
		fflush(stdin);
		
		printf("�ι�° �� : ");
		scanf("%d", &iSecond);
		fflush(stdin);
		if(iFrist == 0 || iSecond == 0)
		{
			puts("0�� �Է��Ҽ� �����ϴ�. �ٽ� �Է� �ϼ���.");
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
		puts("EnterŰ�� ��������.");
		getchar();
		system("cls");
	}	
}