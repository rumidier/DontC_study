#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num;

  printf ("정수 입력 : ");
  scanf ("%d", &num);

  if (num < 0)
    {
      printf ("입력된 숫자는 0 미만. \n");
      return 0;
    }

  if (num >= 0 && num < 10)
    {
      printf ("입력된 숫자는 0이상 10미만. \n");
      return 0;
    }

  if (num >= 10 && num < 20);
    {
      printf ("입력된 숫자는 10이상 20미만. \n");
      return 0;
    }

  if (num >= 20)
    {
      printf ("입력된 숫자는 20이상. \n");
      return 0;
    }

  return 0;
}
