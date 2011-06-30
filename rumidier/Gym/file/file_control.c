#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "file_control.h"
#include "gym.h"
#include "gym-control.h"
#include "list.h"

#define       BIN_FILE      "gymcount.bin"
#define       TXT_FILE      "gymList.txt"

/*
 * txt file load
 */

char **
gym_cat_csv ()
{
  FILE *fh;
  char *line;
  char *ret; 
  char **lines;
  char buf[100];
  int buf_len = 0;
  int str_len = 0;
  int i;

  /**
   *    * *ret 변수는 읽어온 값의 유무를 관리 한다
   *       * ret으로 파일 이 끝인지 아닌지 와 오류 
   *          * 유무를 확인할수 있기 때문에 필요하다.
   *             */

  line = NULL;
  ret = NULL;
  lines = NULL;

  fh = fopen (TXT_FILE, "r");
  if (fh == NULL)
    {
      printf ("Can not oped file[%s]\n", TXT_FILE);
      return NULL;
    }

  while (1)
    {
      ret = fgets (buf, 100, fh);

      if (!ret)
        {
          if (!feof (fh))
            printf ("can not end file? ||%s||\n", TXT_FILE);
          break;
        }

      buf_len = 0;
      for (i = 0; buf[i] != '\0'; i++)
        {
          if (buf[i] != '\n')
            {
              buf_len++;
            }
          else
            {
              /*
               * lines = save_line;
               * line이 끝나는 지점이다. line에 마지막 저장을 한다.
               */
              if (buf_len)
                {
                  line = (char *) realloc (line, (buf_len + str_len + 1) * sizeof (char));
                  memcpy (line + str_len, buf, buf_len);
                  line[buf_len + str_len] = '\0';

                  str_len = 0;
                  buf_len = 0;
                  lines = phone_save_in_lines (lines, line);
                  free (line);
                  line = NULL;
                  break;
                }
            }
        }

      /*
       * 한 line이 끝나지 않았지만 buf가 꽉 찼다.
       * line에 담아두자.
       */
      if (buf_len)
        {
          if (line)
            {
              line = (char *) realloc (line, (buf_len + str_len + 1) * sizeof (char));
              memcpy (line + str_len, buf, buf_len);
              line[buf_len + str_len] = '\0';
            }
          else
            {
              line = (char *) malloc (buf_len + 1 * sizeof (char));
              memcpy (line, buf, buf_len); 
              line[buf_len] = '\0';
            }

          str_len += buf_len;
        }
    }

  fclose (fh);
  return lines;

}

void
csv_parser_debug_lines (char **lines)
{
  int i;

  if (!lines)
    return;

  for (i = 0; lines[i] != NULL; ++i)
    printf ("\n--[[[%s]]]--\n", lines[i]);
}

char**
phone_save_in_lines (char     **lines,
                     char     *line)
{
  int i;
  char **new_lines;

  if (lines)
    {
      for (i = 0; lines[i] != NULL; ++i)
        ;/* lines count */

      new_lines = (char **) malloc ((i + 2) * sizeof (char *));
      for (i = 0; lines[i] != NULL; i++)
        {
          new_lines[i] = lines[i];
        }

      new_lines[i] = strdup (line);
      new_lines[i + 1] = NULL;

      free (lines);
    }
  else
    {
      new_lines = (char **) malloc ( 2 *sizeof (char *));
      new_lines[0] = strdup (line);
      new_lines[1] = NULL;
    }

  return new_lines;
}

/*
 * txt save file
 */
void
store_file (gymperson   *list,
            int         cnt)
{
  int i;
  FILE *binFP = fopen (BIN_FILE, "wb");
  FILE *txtFP = fopen (TXT_FILE, "wt");

  fwrite ((void *) &cnt, sizeof (int), 1, binFP);
  fclose (binFP);

  for (i = 0; i < cnt; i++)
    {
      fputs (list[i].name, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].start_date, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].phone, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].addr, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].age, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].kg, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].height, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].last_date, txtFP);
      fputs ("\n", txtFP);
    }

  fclose (txtFP);
}
