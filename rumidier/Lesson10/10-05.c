#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num;

  printf ("1에서 3 사이의 정수 입력 : ");
  scanf ("%d", &num);

  switch (num)
    {
    case 1:
      printf ("A1 ");
      printf ("A2 ");
    case 2:
      printf ("B1 ");
      printf ("B2 ");
    case 3:
      printf ("C1 ");
      printf ("C2 ");
    default:
      printf ("Default! \n");
    }

  return 0;
}
