#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char n1 = 127;
  short n2 = 32767;
  long long n3 = 922337203685477587;

  printf ("char형 변수 최대 값 : %d \n", n1);
  printf ("short형 변수 최대 값 : %d \n", n2);
  printf ("long long 형 변수 최대 값 : %d \n", n3);

  return 0;
}
