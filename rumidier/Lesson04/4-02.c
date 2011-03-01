#include <stdio.h>

int
main (int   argc,
      char *argv[])
{


  double real_one = 12.345678;
  double real_two = 0.123456;

  double add_result = real_one + real_two;
  double min_result = real_one - real_two;

  printf ("실수의 덧셈 결과 : %f \n", add_result);
  printf ("실수의 뺄셈 결과 : %f \n", min_result);

  return 0;
}
