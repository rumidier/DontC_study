#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1 = 7;
  int num2, num3;

  num2 = num1++; // 이전 예제와 차이 나는 부분 1
  num3 = num1--; // 이전 예제와 차이 나는 부분 2

  printf ("num1 : %d \n", num1);
  printf ("num2 : %d \n", num2);
  printf ("num3 : %d \n", num3);

  return 0;
}
