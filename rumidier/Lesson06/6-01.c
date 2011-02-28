#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n1 = 7;
  int n2 = 3;

  int result = n1 + n2;

  printf ("덧셈 결과 : %d \n", result);

  result = n1 - n2;
  printf ("뺄셈 결과 : %d \n", result);

  printf ("곱셈 결과 : %d \n", n1 * n2);
  printf ("나눗셈 결과 : %d \n", n1 / n2);
  printf ("나머지 결과 : %d \n", n1 % n2);

  return 0;
}
