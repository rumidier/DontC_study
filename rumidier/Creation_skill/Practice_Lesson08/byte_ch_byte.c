#include <stdio.h>

static int
giga_to_mega (int num);

static int
giga_to_kilo (int num);

static int
multi1024 (int num);

int
main (int   argc,
      char *argv[])
{
  int gi_to_me;
  int gi_to_kil;

  gi_to_me = giga_to_mega (12);
  gi_to_kil = giga_to_kilo (12);

  printf ("%d giga -> %d mega 입니다. \n", 12, gi_to_me);
  printf ("%d giga -> %d kilo 입니다. \n", 12, gi_to_kil);

  return 0;
}

static int
giga_to_mega (int num)
{
  return multi1024(num);
}

static int
giga_to_kilo (int num)
{
  return multi1024 (multi1024 (num));
}

static int
multi1024 (int num)
{
  return num * 1024;
}
