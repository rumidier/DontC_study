#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int option;
  double n1, n2;

  printf ("선택 (덧셈1, 뺄셈2, 곱셈3, 나눗셈4) : ");
  scanf ("%d", &option);

  printf ("두 숫자 입력 (숫자1, 숫자2) : ");
  scanf ("%lf, %lf", &n1, &n2);

  if (option == 1)
    printf ("덧셈 결과 : %f \n", n1 + n2);

  if (option == 2)
    printf ("뺄셈 결과 : %f \n", n1 - n2);

  if (option == 3)
    printf ("곱셈 결과 : %f \n", n1 * n2);

  if (option == 4)
    printf ("나눗셈 결과 : %f \n", n1 / n2);

  printf ("프로그램을 종료합니다. \n");

  return 0;
}
