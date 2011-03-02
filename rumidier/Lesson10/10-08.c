#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num;
  printf ("정수 입력 (1이상 30미만) : ");
  scanf ("%d", &num);

  switch (num)
    {
    case 2 : case 3 : case 5 : case 7 :
      printf ("1이상, 10미만의 소수입니다. \n");
      break;
    case 11 : case 13 : case 17 : case 19 :
      printf ("1이상, 10미만의 소수입니다. \n");
      break;
    case 23 : case 29:
      printf ("1이상, 10미만의 소수입니다. \n");
      break;

    default:
      printf ("소수가 아닙니다. \n");
      printf ("또는 0이하이거나 30이상의 수입니다. \n");
    }

  return 0;
}
