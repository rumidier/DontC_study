#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num = 1234;
  printf ("size of num : %d \n\n", sizeof (num));

  printf ("size of 1234 : %d \n", sizeof (1234));
  printf ("size of 1234.0 : %d \n", sizeof (1234.0));
  printf ("size of 0.1234 : %d \n\n", sizeof (0.1234));

  printf ("size of char : %d \n", sizeof (char));
  printf ("size of short : %d \n", sizeof (short));
  printf ("size of double : %d \n\n", sizeof (double));

  return 0;
}
