/**********************************************************************************
 * 사용자로부터 하나의 실수를 입력 받아서 제곱 연산의 결과를 출력하는 프로그램을 작성해 보자.
 * 예를 들어 -2.1을 입력하면 4.41이 출력되어야 한다.
 *********************************************************************************/
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  double num;
  double result_num;

  num = 0.0;
  result_num = 0.0;

  printf ("실수 를 입력해 주세요 : \n");
  scanf ("%lf", &num);
  result_num = num;

  result_num *= result_num;
  printf ("[%4.2lf]의 제곱값은 [%4.2lf]입니다.\n", num, result_num);

  return 0;
}
