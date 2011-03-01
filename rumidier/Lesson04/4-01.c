#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n8 = 010; // 8진수 숫자 표현
  int n10 = 10; // 10진수 숫자 표현
  int n16 = 0x10; // 16진수 숫자 표현

  printf ("8진수 초기화 변수 값 : %d \n", n8);
  printf ("10진수 초기화 변수 값 : %d \n", n10);
  printf ("16진수 초기화 변수 값 : %d \n", n16);
  printf ("16진수 초기화 변수 값 : %x \n", n16);

  return 0;
}
