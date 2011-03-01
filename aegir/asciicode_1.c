#include <stdio.h>

void main()
{
	int i = 0, j = 0, k = 0, l = 0;
	for( l = 0; l < 6; ++l)
	{
		printf("16: 10:c | ");
	}
	printf("\n");
	printf("---------+");
	
	for( l = 0; l < 5; ++l)
	{
		printf("----------+");
	}
	printf("\n");

	for( k = 0; k < 16; ++k)
	{
		j = 32 + k;
		for(i = 0; i < 6; ++i)
		{
			printf("%X:%3d:%c | ", j, j, j);
			j = j + 16;
		}
		printf("\n");
	}
}
