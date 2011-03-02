#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num;
  printf ("정수 입력 (1이상 30미만) : ");
  scanf ("%d", &num);

  if (num == 2 || num == 3 || num == 5 || num == 7)
    printf ("1이상, 10미만의 소수입니다. \n");
  else if (num == 11 || num == 13 || num == 17 || num == 19)
    printf ("10이상, 20미만의 소수입니다. \n");
  else if (num == 23 || num == 29)
    printf ("20이상, 30미만의 소수입니다. \n");
  else
    {
      printf ("소수가 아닙니다. \n");
      printf ("또는 0이하이거나 30이상의 수입니다. \n");
    }

  return 0;
}
