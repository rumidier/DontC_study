#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num;
  printf ("숫자 입력 : ");
  scanf ("%d", &num);

  if (num < 0)
    goto AAA;
  else if (num == 0)
    goto BBB;
  else
    goto CCC;

AAA:
  printf ("음수를 입력하셨습니다. \n");
  goto END;
BBB:
  printf ("0을 입력하셨습니다. \n");
  goto END;
CCC:
  printf ("양수를 입력하셨습니다. \n");
END:
  printf ("프로그램을 종료합니다. \n");

  return 0;
}
