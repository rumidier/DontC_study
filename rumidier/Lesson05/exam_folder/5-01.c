#include <stdio.h>

int
main (int   argc,
      char *argv[])

{
  long long n1 = +2147483647; //int 형 변수의 최대 값
  long long n2 = -2147483646; //int 형 변수의 최소 값

  printf ("오버플로우 발생 전 : %lld \n", n1);
 
  n1 = n1 + 100; // 오버플로우 발생
  printf ("오버플로우 발생 후 : %lld \n\n", n1);

  printf ("언더플로우 발생 전 : %lld \n", n2);
  n2 = n2 - 100; // 언더 플로우 발생
  printf ("언더플로우 발생 후 : %lld \n", n2);

  return 0;
}
