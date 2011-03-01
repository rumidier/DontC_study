#include <stdio.h>

static double
inch_to_cm (double  inch);
static double
cm_to_inch (double cm);

int
main (int   argc,
      char *argv[])
{
  /* 1inch == 2.54cm */
  double inch;
  double cm;

  cm = inch_to_cm (3.24);
  inch = cm_to_inch (12.7);

  printf ("3.24inch 는 %fcm 입니다.\n", cm);
  printf ("12.7cm은 %finch 입니다.\n", inch);

  return 0;
}

static double
inch_to_cm (double  inch)
{
  return inch * 2.54;
}

static double
cm_to_inch (double cm)
{
  return cm / 2.54;
}
