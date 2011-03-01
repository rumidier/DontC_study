#include <stdio.h>

static void
yun_value (int year);
static void
yun_print (int num, int year);

int
main (int   argc,
      char *argv[])
{
  yun_value (2000);
  yun_value (2012);
  yun_value (2015);

  return 0;
}

static void
yun_value (int year)
{
  int value;

  value = 0;

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
      value = 1;
    }

  yun_print (value, year);
}

static void
yun_print (int num, int year)
{
  if (num == 0)
    {
      printf ("%d년도는 윤년이 아닙니다.\n", year);
    }
  else
    {
      printf ("%d년도는 윤년 입니다.\n", year);
    }
}
