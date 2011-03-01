#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  printf ("실수형 나눗셈 결과 : %f\n", (float) 10 / 3);
  printf ("정수형 나눗셈 결과 : 몫 %d, 나머지 %d\n", 10 / 3, 10 % 3);

  return 0;
}
