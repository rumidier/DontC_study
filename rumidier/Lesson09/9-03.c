#include <stdio.h>

void
print_int (int n);

int
main (int   argc,
      char *argv[])
{
  char n1 = 127;
  short n2 = 32767;
  long long n3 = 9223423453234;

  printf ("char형 변수 최대 값 : ");
  print_int (n1);

  printf ("short형 변수 최대 값 : ");
  print_int (n2);

  printf ("long long형 변수 최대 값 : ");
  print_int (n3);

  return 0;
}

void
print_int (int n)
{
  printf ("%d \n", n);
}
