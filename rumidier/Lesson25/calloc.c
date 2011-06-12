#include <stdio.h>
#include <stdlib.h>

char *
read_string (void);

/*
 * 반환형 : char *
 * 함수명 : read_string
 * 전달값 : void (값 없음)
 */
int *
read_integer (void);
/*
 * 반환형 : int *
 * 함수명 : read_integer
 * 전달값 : void (값 없음)
 */

int
main (int   argc,
      char *argv[])
{
  char *str_ptr;
  int *num_ptr;

  str_ptr = read_string ();
  num_ptr = read_integer ();

  if (str_ptr != NULL)
    printf ("읽어 들인 문자열 : %s \n", str_ptr);
  if (num_ptr != NULL)
    printf ("읽어 들인 정수 : %d \n", *num_ptr);

  free (str_ptr);
  str_ptr = NULL;
  free (num_ptr);

  num_ptr = NULL;

  return 0;
}

char *
read_string (void)
{
  char *s_ptr = (char *) calloc (4, sizeof (char) * 5);

  if (s_ptr == NULL)
    return NULL;

  printf ("문자열 입력 : ");
  scanf ("%s", s_ptr);

  return s_ptr;
}

int *
read_integer (void)
{
  int *i_ptr = (int *) calloc (1, sizeof (int) * 1);

  if (i_ptr == NULL)
    return NULL;

  printf ("정수 입력 : ");
  scanf ("%d", i_ptr);

  return i_ptr;
}
