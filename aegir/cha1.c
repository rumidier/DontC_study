/* 10���� ������ �Է� �޾Ƽ� 16������ ����ϴ� ���α׷� */
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char ch;
	while(1)
	{
		printf("10���� : ");
		gets(&ch);
		
		if(ch == '\n' || ch < '1')
		{
			puts("�ٽ� �Է� �ϼ���.");
			fflush(stdin);
		}
		else
		{
			printf("16���� : %x\n", atoi(&ch));
			fflush(stdin);
		}
		puts("----------");
	}
}