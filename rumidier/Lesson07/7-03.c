#include <stdio.h>

static int
add (int n1, int n2)
{
  int result = n1 + n2;

  return result;  /* return문 case 1 */
}

static int
min (int n1, int n2)
{
  return n1 - n2;  /* return문 case 2 */
}

int
main (int   argc,
      char *argv[])
{
  int add_result;

  /* 함수 호출 case 1 */
  add_result = add (3, 5);
  printf ("덧셈 결과 : %d \n", add_result);

  /* 함수 호출 case 2 */
  printf ("뺄셈 결과 : %d \n", min (5, 2));

  return 0;
}
