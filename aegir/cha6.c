/* �Է¹��� �ʸ� [��,��,��]�� ���·� ����ϴ� ���α׷� */
#include <stdio.h>

void main()
{
	int iHourRes = 0;
	int iMinRes = 0;
	int iSecRes = 0;
	int iSec = 0;
	
	while(1)
	{
		printf("��(second)�� �Է� �ϼ���:(0:����)");
		scanf("%d", &iSec);
		fflush(stdin);
		
		if(iSec == 0)
		{
			printf("����!\n");
			return;
		}
		else if(iSec < 0)
		{
			printf("-���� �Է� �ϼ̽��ϴ�.\n");
		}
		else
		{
			iHourRes = iSec/3600;
			iMinRes = (iSec%3600)/60;
			iSecRes = (iSec%3600)%60;
			
			printf("[%d�� %d�� %d��]\n", iHourRes, iMinRes, iSecRes);
		}
	}
}