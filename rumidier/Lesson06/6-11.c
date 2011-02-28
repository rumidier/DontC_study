#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int a = 1, b = 2;

  a++, b++, printf ("postfix ++ 연산 실행 \n");
  printf ("a : %d, ", a), printf ("b : %d \n", b);

  return 0;
}
