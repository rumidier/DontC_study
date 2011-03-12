/* 소수 출력 프로그램 */

void main()
{
	int iPrimeNum = 0;
	int iCnt = 0;
	for(iPrimeNum = 1, iCnt = 0; iCnt < 10; ++iPrimeNum)
	{
		if(iPrimeNum/2 == 1 || iPrimeNum/3 ==1 && iPrimeNum < 5)
		{
			printf("%d ", iPrimeNum);
			++iCnt;
		}
		if(iPrimeNum%2 != 0 && iPrimeNum%3 != 0 && iPrimeNum != 1)
		{
			printf("%d ",iPrimeNum);
			++iCnt;
		}
	}
}