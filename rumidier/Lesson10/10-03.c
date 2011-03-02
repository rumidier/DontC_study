#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num;

  printf ("정수 입력 : ");
  scanf ("%d", &num);

  if (!(num % 2))
    printf ("입력된 수는 짝수 입니다. \n");
  else
    printf ("입력된 수는 홀수 입니다. \n");

  if (num < 0)
    {
      printf ("그리고 음수 입니다. \n");
    }
  else
    {
      if (num == 0)
        printf ("다름아닌 0입니다. \n");
      else
        printf ("그리고 양수입니다. \n");
    }

  return 0;
}
