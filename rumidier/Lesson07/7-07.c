#include <stdio.h>

int
function (int n);

int
main (int   argc,
      char *argv[])
{
  printf ("반환 값 : %d \n", function (5.67));
  return 0;
}

int function (int n)
{
  printf ("입력된 정수 : %d \n", n);
  return 3.15;
}
