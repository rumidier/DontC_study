/**
 * csv-parser.c
 *
 * csv 파일을 읽어들여 화면에 출력합니다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_PARSER_INPUT_FILE   "linked-phone.csv"
#define CSV_PARSER_BUF_SIZE     10

void
csv_parser_debug_lines (char **lines)
{
  int i;

  if (!lines)
    return;

  for (i = 0; lines[i] != NULL; ++i)
    printf ("--[[[%s]]]--\n", lines[i]);
}

char **
csv_parser_save_lines (char       **lines,
                       const char  *line)
{
  char **new_lines;
  int i;

  if (lines)
    {
      for (i = 0; lines[i] != NULL; ++i)
        ;
      /*
       * 2차원 lines 의 갯수를 샌다
       */

      new_lines = (char **) malloc (sizeof (char *) * (i + 2));
      for (i = 0; lines[i] != NULL; ++i)
        new_lines[i] = lines[i];
      new_lines[i] = strdup (line);
      new_lines[i + 1] = NULL;
      /*
       * 첫 line이면 두개를 선언 하여 복사와 NULL 구간은 만들어주고
       * free 해제 한다
       */

      free (lines);
    }
  else
    {
      new_lines = (char **) malloc (sizeof (char *) * 2);
      new_lines[0] = strdup (line);
      new_lines[1] = NULL;
    }

  return new_lines;
}

char **
csv_parser_get_lines (const char *file)
{
  FILE *fh;
  char **lines;
  char *line;
  int line_len;

  fh = fopen (file, "r");
  if (fh == NULL)
    {
      printf ("cannot open [%s] file\n", file);
      return NULL;
    }

  line_len = 0;
  line = NULL;
  lines = NULL;
  while (1)
    {
      char *ret;
      char buf[CSV_PARSER_BUF_SIZE];
      int len;
      int i;


      ret = fgets (buf, CSV_PARSER_BUF_SIZE, fh);
      if (!ret)
        {
          if (!feof (fh))
            printf ("cannot read file [%s]\n", file);
          break;
        }

      len = 0;
      for (i = 0; buf[i] != '\0'; i++)
        {
          if (buf[i] != '\n')
            {
              ++len;
            }
          else
            {
              if (len)
                {
                  if (line)
                    {
                      line = (char *) realloc (line, sizeof (char) * (line_len + len + 1));
                      memcpy (line + line_len, buf, len);
                      line[line_len + len] = '\0';
                    }
                  else
                    {
                      line = (char *) malloc (sizeof (char) * (len + 1));
                      memcpy (line, buf, len);
                      line[len] = '\0';
                    }
                  line_len += len;
                }

              /**
               * save the lines
               */
              lines = csv_parser_save_lines (lines, line);

              free (line);
              line = NULL;
              line_len = 0;
              len = 0;

              break;
            }
        }

      if (len)
        {
          if (line)
            {
              line = (char *) realloc (line, sizeof (char) * (line_len + len + 1));
              memcpy (line + line_len, buf, len);
              line[line_len + len] = '\0';
            }
          else
            {
              line = (char *) malloc (sizeof (char) * (len + 1));
              memcpy (line, buf, len);
              line[len] = '\0';
            }
          line_len += len;
        }
    }

  if (line)
    {
      /**
       * save the lines
       */
      lines = csv_parser_save_lines (lines, line);

      free (line);
      line = NULL;
      line_len = 0;
    }

  fclose (fh);

  return lines;
}

int
main (int    argc,
      char **argv)
{
  char **lines;
  int i;

  lines = csv_parser_get_lines (CSV_PARSER_INPUT_FILE);
  if (!lines)
    {
      printf ("cannot parse csv file\n");
      exit (EXIT_FAILURE);
    }

  //csv_parser_debug_lines (lines);

  for (i = 0; lines[i] != NULL; ++i)
    {
      char *token;

      token = lines[i];
      printf ("Item %d:\n", i);

      while ((token = strtok (token, ",")) != NULL)
        {
          printf ("\t%s\n", token);
          token = NULL;
        }
    }

  if (lines)
    {
      for (i = 0; lines[i] != NULL; ++i)
        free (lines[i]);
      free (lines);
    }

  return 0;
}
