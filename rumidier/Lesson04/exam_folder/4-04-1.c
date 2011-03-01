#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i = 0;
  float real;


  real = 0;
  for (i = 0; i < 1000; i++)
    {
      real = real + 0.1;
    }
  printf ("0.1을 1000회 더한 결과 : %f \n", real);

  real = 0;
  for (i = 0; i < 10000; i++)
    {
      real = real + 0.1;
    }
  printf ("0.1을 10000회 더한 결과 : %f \n", real);

  return 0;
}
