#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n = 5;

  printf ("현재의 n : %d \n", n);
  printf ("-n : %d, +n : %d \n\n", -n, +n);

  n = -n;  // n -= n과 혼동 주의!
  printf ("변경된 n : %d \n", n);
  printf ("-n : %d, +n : %d \n\n", -n, +n);

  return 0;
}
