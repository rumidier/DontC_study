#include <stdio.h>

static int
increment (int n)
{
  n++;
  return n;
}

int
main (int   argc,
      char *argv[])
{
  int num = 2;

  num = increment (num);
  printf ("num : %d \n", num);

  num = increment (num);
  printf ("num : %d \n", num);

  num = increment (num);
  printf ("num : %d \n", num);

  return 0;
}
