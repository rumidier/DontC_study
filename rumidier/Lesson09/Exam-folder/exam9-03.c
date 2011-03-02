#include <stdio.h>
#include <math.h>

int
main (int   argc,
      char *argv[])
{
  double x_num1, x_num2;
  double y_num1, y_num2;
  double diff_x, diff_y;
  double result_len;

  result_len = 0;
  x_num1 = 0, x_num2 = 0;
  y_num1 = 0, y_num2 = 0;

  printf ("첫 번째 점의 좌표 입력 :");
  scanf ("%lf, %lf", &x_num1, &y_num1);
  printf ("두 번째 점의 좌표 입력 :");
  scanf ("%lf, %lf", &x_num2, &y_num2);

  diff_x = x_num1 - x_num2;
  diff_y = y_num1 - y_num2;
  //result_len = sqrt ((x_num1 - x_num2) * (x_num1 - x_num2) + (y_num1 - y_num2) * (y_num1 - y_num2));
  result_len = sqrt (diff_x * diff_x + diff_y * diff_y);

  printf ("%lf\n", result_len);



  return 0;
}
