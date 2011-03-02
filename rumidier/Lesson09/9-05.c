#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n1, n2;
  double d1, d2;

  printf ("정수 | 정수: ");
  scanf ("%d | %d", &n1, &n2);
  printf ("입력 데이터 출력 : %d, %d \n\n", n1, n2);

  printf ("실수 / 실수 : ");
  scanf ("%lf / %lf", &d1, &d2);
  printf ("입력 데이터 출력 : %f, %f \n\n", d1, d2);

  printf ("정수 *-/ 실수 : ");
  scanf ("%d *-/ %lf", &n1, &d2);
  printf ("입력 데이터 출력 : %d, %f \n\n", n1, d2);

  return 0;
}
