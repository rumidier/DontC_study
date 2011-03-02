#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n1, n2;
  int max, min;

  printf("두 수를 입력 해주세요 : ");
  scanf ("%d %d", &n1, &n2);

  if (n1 > n2)
    {
      max = n1;
      min = n2;
    }
  else
    {
      max = n2;
      min = n1;
    }

  printf ("(%d) - (%d) = (%d) 입니다.\n", max, min, max - min);

  return 0;
}
