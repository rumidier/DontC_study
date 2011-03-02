#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n1;
  double n2;

  printf ("정수 입력 : ");
  scanf ("%d", &n1);

  printf ("실수 입력 : ");
  scanf("%lf", &n2);

  printf ("입력된 두 개의 데이터 : %d, %f \n", n1, n2);

  return 0;
}
