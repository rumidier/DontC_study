#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

static int
dal_left_print (int **, int, int, int);
static int
dal_right_print (int **, int, int, int);

int
main (int   argc,
      char *argv[])
{
  int left_max;
  int left_min;
  int right_max;
  int right_cir;
  int cir_value;
  int ev_value;
  int count_p = 1;
  int input;
  int i, j;
  int cir = 0;

  static int num = 1;
  int **dal = NULL;

  fpits ("입력 : ", stdout);
  scanf ("%d", &input);

  cir = (input / 2) - 1;
  cir_value = input - 2;
  right_max = input - 1;
  left_max = right_max;
  left_min  = 0;
  ev_value = input % 2;

  dal = (int **) malloc (input * sizeof (int *));
  for (i = 0; i < input; i++)
    {
      dal[i] = (int *) malloc (input * sizeof (int));
    }

  for (j = 0; j < input; j++)
    {
      dal[input - input][j] = num++;
    }
 
  for (i = cir; i > 0; i--)
    {
      num = dal_left_print (dal, count_p, left_max, left_min, num);
      num = dal_right_print (dal, right_cir, count_p, right_max, num);

      right_max--;
      right_cir--;
      left_max--;
      left_min = count_p;
      count_p++;

      if (ev_value && (i == 1))
        {
          num = dal_left_print (dal, count_p, left_max, left_min, num);
        }
    }

  if (ev_value == 1)
    {
      dal[cir_value][cir_value - 1] = num++;
      dal[cir_value][cir_value] = num++;
    }
  else
    {
      dal[cir_value][cir_value] = num++;
      dal[cir_
    }

}
