#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char ca = 10;
  char cb = 20;

  short sa = 1025;
  short sb = 4327;

  char add_result_one = ca + cb;
  short add_result_two = sa + sb;

  printf ("char형 변수 덧셈결과 : %d \n", add_result_one);
  printf ("short형 변수 덧셈결과 : %d \n", add_result_two);

  return 0;
}
