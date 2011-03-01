#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int val;
#if 0
  /*
  val = 1 + 2;  /* 덧셈과 대입 연산 */
  printf ("1 + 2 = %d \n", val);
  */
#endif
// 올바른 주석 처리방법
    /*
     * val = 1 + 2; // 덧셈과 대입 연산
     * printf ("1 + 2 = %d \n", val);
     */

    val = 2 + 3;
  printf ("2 + 3 = %d /* 5가 출력 */ \n", val);
  printf ("프로그램 종료! \n" /* 프로그램이 종료됨을 알림 */);

  return 0;
}
