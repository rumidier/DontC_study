/* �ΰ��� ���ڸ� �Է� �޾� G.C.M(�ִ� �����) ���ϴ� ���α׷� */
#include <stdio.h>

void main()
{
	int iFirstNum = 0;
	int iSecondNum = 0;
	int i = 0;
	while(1)
	{
		printf("ù��° ����: ");
		scanf("%d", &iFirstNum);
		fflush(stdin);
		
		printf("�ι�° ����: ");
		scanf("%d", &iSecondNum);
		fflush(stdin);
		
		if(iFirstNum == 0 || iSecondNum == 0)
		{
			puts("�ִ� ������� ���Ҽ� �����ϴ�. �ٽ� �Է����ּ���.");
		}
		else if(iFirstNum < iSecondNum)
		{
			for(i = iFirstNum; ; --i)
			{
				if(iFirstNum % i == 0 && iSecondNum % i == 0)
				{
					printf("G.C.M(�ִ� �����) = %d\n", i);
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
					printf("G.C.M(�ִ� �����) = %d\n", i);
					break;
				}
			}
		}
	}
	
	
}