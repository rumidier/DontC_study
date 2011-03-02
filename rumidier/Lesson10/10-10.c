#include <stdio.h>

int goto_fct (void);

int
main (int   argc,
      char *argv[])
{
  printf ("무조건 가 본다! ");
  goto special;
  printf ("과연 돌아왔을가? ");

  return 0;
}

int
goto_fct (void)
{
special:
  return 123;
}
