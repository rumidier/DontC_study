#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num;

  printf ("12345\n");
  num = printf ("67890\n");

  printf ("함수의 반환 값 1 : %d \n", num);
  printf ("함수의 반환 값 2 : %d \n", printf ("Before or After\n"));

  return 0;
}
