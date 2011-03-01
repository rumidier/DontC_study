#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1 = 10;
  int num2 = 12;

  int result1, result2;

  result1 = (num1 == num2); // 동등 비교
  result2 = (num1 <= num2); // 대소 비교

  printf ("같은가? %d \n", result1);
  printf ("같거나 작은가? %d \n", result2);

  return 0;
}
