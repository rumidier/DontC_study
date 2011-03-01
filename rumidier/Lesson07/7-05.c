#include <stdio.h>

static int
in_crement (int n);

int
main (int   argc,
      char *argv[])
{
  int num = 2;

  int in_crement (int n);  /* in_crement 함수의 선언 */

  num = in_crement (num);
  printf ("num : %d \n", num);

  num = in_crement (num);
  printf ("num : %d \n", num);

  num = in_crement (num);
  printf ("num : %d \n", num);

  return 0;
}

static int
in_crement (int n)
{
  n++;
  return n;
}
