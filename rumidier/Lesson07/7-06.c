#include <stdio.h>

int in_crement (int n);
int two_increment (int n);

int
main (int   argc,
      char *argv[])
{
  int num = 2;

  num = in_crement (num);
  printf ("num : %d \n", num);

  num = two_increment (num);
  printf ("num : %d \n", num);

  return 0;
}

int
two_increment (int n)
{
  n = in_crement (n);
  n = in_crement (n);

  return n;
}

int
in_crement (int n)
{
  n++;

  return n;
}
