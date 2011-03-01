#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i = 0;
  float real;

  real = 0;
  for (i = 0; i < 30; i++)
    {
      real = real + 0.1;
    }
  printf ("0.1을 30회 더한 결과 : %f \n", real);

  real = 0;

  for (i = 0; i < 50; i++)
    {
      real = real + 0.1;
    }
  printf ("0.1을 50회 더한 결과 : %f \n", real);

  real = 0;

  for (i = 0; i < 100; i++)
    {
      real = real + 0.1;
    }
  printf ("0.1을 100회 더한 결과 : %f \n", real);

  return 0;
}
