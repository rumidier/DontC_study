#include <stdio.h>

#define     STRING_JOB(A, B)      #A "의 직업은" #B "입니다."
#define     PRINT_STR(STR)        puts (STR)

int
main (int   argc,
      char *argv[])
{
  PRINT_STR (STRING_JOB(이동춘, 나무꾼));
  PRINT_STR (STRING_JOB(한상순, 나무꾼));

  return 0;
}
