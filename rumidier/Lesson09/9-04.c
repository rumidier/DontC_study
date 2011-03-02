#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n1, n2, n3;
  double d1, d2, d3;

  printf ("세 개의 정수 입력 : ");
  scanf ("%d %d %d", &n1, &n2, &n3);
  printf ("입력된 정수 출력 : %d, %d, %d \n\n", n1, n2, n3);

  printf ("세 개의 실수 입력 : ");
  scanf ("%lf %lf %lf", &d1, &d2, &d3);
  printf ("입력된 실수 출력 : %f, %f, %f \n\n", d1, d2, d3);

  return 0;
}
