#include <stdio.h>

static double
fah_to_cen (double fah);

int
main (int   argc,
      char *argv[])
{
  double cen;

  cen = fah_to_cen (124.5);
  printf ("화씨 %f 도를 섭씨로 변화하면 %f도 입니다.\n", 124.5, cen);

  return 0;
}

static double
fah_to_cen (double fah)
{
  return ((double)(5)/ (double) (9) * (double) (fah - 32));
}
