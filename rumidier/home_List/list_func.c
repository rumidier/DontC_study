#include "list_head.h"

void
csv_parser_debug_lines (char **lines);

int
list_cat_command (int argc_count, char **argv_str)
{
  int i;

  for (i = 0; i < argc_count; i++)
    {
      if (strcmp (argv_str[i], ADD))
          return 1;
      else if (strcmp (argv_str[i], DEL))
        return 2;
      else if (strcmp (argv_str[i], SEARCH))
        return 3;
      else if (strcmp (argv_str[i], CHANGE))
        return 4;
      else
        return 0;
    }

  return 0;
}

/**
 * FILE 연다.
 * 파일을 줄단위로 읽는다 (buf)
 * 개인별로 나눈다. (line)
 * 각 개인별을 합친다 (lines)
 * lines 를 리턴 한다.
 */

char **
list_cat_csv ()
{
  FILE *fh;

  int i;
  int buf_len = 0;
  int str_len = 0;

  char *line;
  char *ret; 
  char **lines;
  char buf[100];
  /* 
   * ret *변수는 읽어온 값의 유무를 관리 한다
   * ret 으로 파일 이 끝인지 아닌지 와 오류 
   * 유무를 확인할수 있기 때문에 필요하다.
   */

  line = NULL;
  ret = NULL;
  lines = NULL;
             

  fh = fopen (LIST_FUNC_CSV, "r");
  if (fh == NULL)
    {
      printf ("Can not oped file[%s]\n", LIST_FUNC_CSV);
      return NULL;
    }

  while (1)
    {
      ret = fgets (buf, 100, fh);

      if (!ret)
        {
          if (!feof (fh))
            printf ("can not end file? ||%s||\n", LIST_FUNC_CSV);
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
              lines = save_line;
              line이 끝나는 지점이다. line에 마지막 저장을 한다.
              */
              if (buf_len)
                {
                  line = (char *) realloc (line, (buf_len + str_len + 1) * sizeof (char));
                  memcpy (line + str_len, buf, buf_len);
                  line[buf_len + str_len] = '\0';

                  str_len = 0;
                  buf_len = 0;
                  lines = list_line_save_in_lines (lines, line);
                  free (line);
                  line = NULL;
                  break;
                }
            }
        }

      if (buf_len) /* 한 line이 끝나지 않았지만 buf가 꽉 찼다. line에 담아두자. */
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

  return lines;
}

int
list_cat_extend (char *cat_list, int str_len, int buf_len)
{
  cat_list = (char *) realloc (cat_list, (str_len + buf_len) * sizeof (char)); 

  return str_len + buf_len;
}

void
list_init (ListFuncPhonePoint *point)
{
  point -> list_size = 0;
  point -> head = NULL;
  point -> tail = NULL;
}
char **
list_line_save_in_lines (char **lines, char *line)
{
  int i;
  char **new_lines;


  if (lines)
    {
      for (i = 0; lines[i] != NULL; ++i)
        ;

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

void
csv_parser_debug_lines (char **lines)
{
  int i;

  if (!lines)
    return;

  for (i = 0; lines[i] != NULL; ++i)
    printf ("\n--[[[%s]]]--\n", lines[i]);
}

char *
list_insert_link (ListFuncPhonePoint *point, ListFuncPerson *list_head, char *token)
{
  int count = 1;

  if (list_head == NULL)
    {
      ListFuncPerson *new_list;
      new_list = (ListFuncPerson *) malloc (sizeof (ListFuncPerson));

      token = strtok (token, LIST_FUNC_DELIM);
      if (token != NULL)
        new_list -> eig_no = atoi (token);

      while ((token = strtok (NULL, LIST_FUNC_DELIM)) != NULL)
        {
          list_insert_data (new_list -> in_data, token, count);
          token = NULL;
          count++;
        }
      new_list -> next_ptr = point -> tail;
    }
  else
    {
      while ((token = strtok (token, LIST_FUNC_DELIM)) != NULL)
        {
          printf ("%s\n", token);
          token = NULL;
        }
      printf ("\n---------------------------\n\n");
    }

  return NULL;
}

void
list_insert_data (char **in_data, char *data, int count)
{
  int data_len;
  int i;

  data_len = strlen (data);

  if (count == 1)
    {
      in_data = (char **) malloc (sizeof (char *) * count + 1);
      in_data[count - 1] = (char *) malloc (sizeof (char) * data_len + 1);

      for (i = 0; i < data_len; ++i)
        {
          in_data[count - 1][i] = data[i];
        }
      in_data[count - 1][i] = '\0';
      in_data[count] = NULL;
    }
  else if (1 < count && count < 13)
    {
      in_data = (char **) realloc (in_data, sizeof (char *) * count + 1);
      in_data[count - 1] = (char *) malloc (sizeof (char) * data_len + 1);

      for (i = 0; i < data_len; ++i)
        {
          in_data[count - 1][i] = data[i];
        }
      in_data[count - 1][i] = '\0';
      in_data[count] = NULL;
    }
}
