/* 10진수 정수를 입력 받아서 16진수로 출력하는 프로그램 */
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char ch;
	while(1)
	{
		printf("10진수 : ");
		gets(&ch);
		
		if(ch == '\n' || ch < '1')
		{
			puts("다시 입력 하세요.");
			fflush(stdin);
		}
		else
		{
			printf("16진수 : %x\n", atoi(&ch));
			fflush(stdin);
		}
		puts("----------");
	}
}