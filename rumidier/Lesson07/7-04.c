#include <stdio.h>

/* 정수형 나눗셈의 몫 반환 함수 */
static int
quotient (int n1, int n2)
{
  return n1 / n2;
}

/* 정수형 나눗셈의 나머지 반환 함수 */
static int
re_mainder (int n1, int n2)
{
  return n1 % n2;
}

/* 정수형 나눗셈의 계산 및 결과 출력 */
static void
int_divide (int n1, int n2)
{
  printf ("%d / %d의 몫 : %d \n", n1, n2, quotient (n1, n2));
  printf ("%d / %d의 나머지 : %d \n", n1, n2, re_mainder (n1, n2));
}

int
main (int   argc,
      char *argv[])
{
  printf ("5 나누기 2의 결과 **** \n");
  int_divide (5, 2);
  printf ("\n");   // 한 줄 건너 뛰기

  printf ("12 나누기 5의 결과 ***** \n");
  int_divide (12, 5);
  printf ("\n");

  return 0;
}
