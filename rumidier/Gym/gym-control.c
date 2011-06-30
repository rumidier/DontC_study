#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#include "list.h"
#include "gym-control.h"
#include "gym.h"

#define       BIN_FILE      "gymcount.bin"
#define       TXT_FILE      "gymList.txt"


/*
 * first menu
 */
void
show_menu (void)
{
  puts ("gnb-gym");
  puts ("1. 신규 등록");
  puts ("2. 회비 관리");
  puts ("3. 회원 프로필");
  puts ("4. 종료");

  printf (">> ");
}

/*
 * exit menu
 */
void
exit_prog (void)
{
  puts ("이용해 주셔서 감사합니다.");
}

/*
 * swtich choice number
 */
int
read_choice (void)
{
  int choice;

  scanf ("%d", &choice);
  getchar ();

  return choice;
}

/*
 * input person data
 */

/*
 * search person (key: person name)
 */
void
search_person (List *list)
{
  char name[SHORT_STR];
  ListElmt *elmt;
  gymperson *person;

  elmt = list->head;

  printf ("찾는 이름 입력 : ");
  scanf ("%s", name);

    if (elmt != NULL)
      {
        while (1)
          {
            person = elmt->data;
            if ( !(strcmp (person->name, name)))
              {
                gym_person_print (person);
                //eig_num.txt open..
                gym_history (person);
              }

            if (elmt->next == NULL)
              break;
            elmt = elmt->next;
          }
      }
}

void
in_last_date (char       *save_month_ptr,
              gymperson  *read)
{
  //int i;
  char month[4];
  char save_month[10];

  printf ("납입내역(납일개월수) : ");
  scanf ("%s", month);
  strcpy (save_month, save_month_ptr);

  if (strlen (month) == 1)
    {
      if (month[0] == '0')
        {
          strcpy (read->last_date, save_month);
        }
      else if('1' <= month[0] && month[0] <= '9')
        {
          /*
           * 01~09월
           */
          if (save_month[5] == '0')
            {
              if (save_month[6] <= '3')
                {
                  save_month[6] += month[0];

                  if (save_month[6] >= 106)
                    {
                      save_month[5]++;
                      save_month[6] -= 58;
                      strcpy (read->last_date, save_month);
                    }
                  else
                    {
                      save_month[6] -= 48;
                      strcpy (read->last_date, save_month);
                    }
                }
              else
                {
                  save_month[6] += month[0];

                  if (save_month[6] <= 105)
                    {
                      save_month[6] -= 48;
                      strcpy (read->last_date, save_month);
                    }
                  else if (save_month[6] < 109)
                    {
                      save_month[5]++;
                      save_month[6] -= 58;
                      strcpy (read->last_date, save_month);
                    }
                  else
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[6] -= 60;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[6] -= 60;
                          strcpy (read->last_date, save_month);
                        }
                    }
                }
            }
          /*
           *내역일이 10~12월
           */
          else if (save_month[5] == '1')
            {
              save_month[6] += month[0];

              if (save_month[6] <= 97 || save_month[6] == 98)
                {
                  strcpy (read->last_date, save_month);
                }
              else if (98 < save_month[6] && save_month[6] <= 107)
                {
                  save_month[3]++;
                  if (save_month[3] >= 58)
                    {
                      save_month[2]++;
                      save_month[3] -= 10;
                      save_month[5]--;
                      save_month[6] -= 50;
                      strcpy (read->last_date, save_month);
                    }
                  else
                    {
                      save_month[5]--;
                      save_month[6] -= 50;
                      strcpy (read->last_date, save_month);
                    }
                }
              else
                {
                  printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[1]\n");
                  strcpy (read->last_date, save_month);
                }
            }
          /*
           * 납입내역이 이상할때 디폴트 입관일
           */
          else
            {
              printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[2]\n");
              strcpy (read->last_date, save_month);
            }
        }
      else
        {
          printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[3]\n");
          strcpy (read->last_date, save_month);
        }
    }
  else if (strlen (month) == 2)
    {
      /*
       * input month 10~12
       */

      /*
       * input month over num 2
       * print error message
       */
      if (month[0] >= '2')
        {
          printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[4]\n");
          strcpy (read->last_date, save_month);
        }
      /*
       * input month ten array '1' 
       */
      else if (month[0] == '1')
        {
          /*
           * input month one array '0' or '1'
           */
          if ('0' <= month[1] && month[1] <= '1')
            {
              if (month[1] == '0') /* one array '0' */
                {
                  /*
                   * input 10 save_month 01~02
                   */
                  if ('0' == save_month[5] && ('1' <= save_month[6] && save_month[6] <= '2'))
                    {
                      save_month[5]++;
                      strcpy (read->last_date, save_month);
                    }
                  /*
                   * input 10 save_month 03~09
                   */
                  else if ('0' == save_month[5] && ('3' <= save_month[6] && save_month[6] <= '9'))
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[6] -= 2;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[6] -= 2;
                          strcpy (read->last_date, save_month);
                        }
                    }
                  /*
                   * input 10 save_month 10~11
                   */
                  else if ('1' == save_month[5] && ('0' <= save_month[6] && save_month[6] <= '1'))
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[6] += 8;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[6] += 8;
                          strcpy (read->last_date, save_month);
                        }
                    }
                  /*
                   * input 10 save_month 12
                   */
                  else if ('1' == save_month[5] && ('2' == save_month[6]))
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[6] -= 2;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[6] -= 2;
                          strcpy (read->last_date, save_month);
                        }
                    }
                  else
                    {
                      printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[5]\n");
                      strcpy (read->last_date, save_month);
                    }
                }
              else if (month[1] == '1')
                {
                  /*
                   * input 11 save_month 01~02
                   */
                  if ('0' == save_month[5] && ('1' == save_month[6]))
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[5] += 1;
                          save_month[6] += 1;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[5] += 1;
                          save_month[6] += 1;
                          strcpy (read->last_date, save_month);
                        }
                    }
                  /*
                   * input 11 save_month 02~09, 11,12
                   */
                  else if ('0' != save_month[6] && ('2' <= save_month[6] && save_month[6] <= '9'))
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[6] -= 1;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[6] -= 1;
                          strcpy (read->last_date, save_month);
                        }
                    }
                  /*
                   * input 11 save_month 10~11
                   */
                  else if ('1' == save_month[5] && ('0' == save_month[6]))
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[5]--;
                          save_month[6] += 8;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[5]--;
                          save_month[6] += 8;
                          strcpy (read->last_date, save_month);
                        }
                    }
                  /*
                   * input 11 save_month 12
                   */
                  else if ('1' == save_month[5] && ('2' == save_month[6]))
                    {
                      save_month[3]++;
                      if (save_month[3] >= 58)
                        {
                          save_month[2]++;
                          save_month[3] -= 10;
                          save_month[6] -= 2;
                          strcpy (read->last_date, save_month);
                        }
                      else
                        {
                          save_month[6] -= 2;
                          strcpy (read->last_date, save_month);
                        }
                    }
                  else
                    {
                      printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[5]\n");
                      strcpy (read->last_date, save_month);
                    }
                }
            }
          else if (month[1] == '2')
            {
              save_month[3]++;
              if (save_month[3] >= 58)
                {
                  save_month[2]++;
                  save_month[3] -= 10;
                  strcpy (read->last_date, save_month);
                }
              else
                {
                  strcpy (read->last_date, save_month);
                }
            }
          else
            {
              printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[7]\n");
              strcpy (read->last_date, save_month);
            }
        }
      else
        {
          printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[8]\n");
          strcpy (read->last_date, save_month);
        }
    }
  else
    {
      printf ("납입내역이 올바르지 않게 입력되었습니다 확인해 주세요[9]\n");
      strcpy (read->last_date, save_month);
    }
}

void
no_insert_money (gymperson    *gym_list,
                 int          data_count)
{
  char input_date[20];
  int i;

  printf ("오늘 날짜를 입력해 주세요: ");
  scanf ("%s", input_date);

  for (i = 0; i < data_count; i++)
    {
      if (1 <= strcmp (input_date, gym_list[i].last_date))
        {
          printf ("[[[%s]]\n", gym_list[i].last_date);
        }
    }

}

gymperson *
gym_list (char *str)
{
  gymperson *person;
  int str_len;
  int count = 1;

  person = (gymperson *) malloc (sizeof (gymperson) * 1);

  while ((str = strtok (str, ",")) != NULL)
    {
      str_len = strlen (str);

      switch (count)
        {
        case 1:
            {
              strcpy (person->name_num, str);
              break;
            }
        case 2:
            {
              strcpy (person->name, str);
              break;
            }
        case 3:
            {
              strcpy (person->start_date, str);
              break;
            }
        case 4:
            {
              strcpy (person->phone, str);
              break;
            }
        case 5:
            {
              strcpy (person->addr, str);
              break;
            }
        case 6:
            {
              strcpy (person->age, str);
              break;
            }
        case 7:
            {
              strcpy (person->weight, str);
              break;
            }
        case 8:
            {
              strcpy (person->height, str);
              break;
            }
        case 9:
            {
              strcpy (person->last_date, str);
              break;
            }
        }

      str = NULL;
      count++;
    }

  return person;
}

void
gym_print (ListElmt *elmt)
{
  gymperson *person;

  if (elmt != NULL)
    {
      while (1)
        {
          person = elmt->data;
          gym_person_print (person);

          if (elmt->next == NULL)
            break;
          elmt = elmt->next;
        }
    }
}

void
gym_person_print (gymperson *person)
{
  printf ("--------------------------------------------------------------------------\n");
  printf ("| 회원번호 | %-s\n", person->name_num);
  printf ("| 회원이름 | %-s\n", person->name);
  printf ("|  입관일  | %-s\n", person->start_date);
  printf ("| 전화번호 | %-s\n", person->phone);
  printf ("|   주소   | %-s\n", person->addr);
  printf ("|   나이   | %-s\n", person->age);
  printf ("|  몸무게  | %-s\n", person->weight);
  printf ("|    키    | %-s\n", person->height);
  printf ("|다음납부일| %-s\n", person->last_date);
  printf ("--------------------------------------------------------------------------\n");

  return;
}

void
gym_sort (List *list)
{
  gymperson *cur_person;
  gymperson *next_person;
  ListElmt *cur_elmt;
  ListElmt *next_elmt;
  ListElmt *past_elmt;

  int i;
  int size;

  size = list->size;

  for (i = 0; i < size - 1; ++i)
    {
      /**
       * list의 값이 1개 이하 일때는 동작 하지 않는다.
       * cur_elmt - 처음 시작
       * past_elmt - 처음 시작
       **/
      cur_elmt = list->head;
      past_elmt = list->head;
      next_elmt = cur_elmt->next;

      cur_person = cur_elmt->data;
      next_person = next_elmt->data;

      if (next_elmt->next == NULL)
        {
          if (cur_person->name_num > next_person->name_num)
            {
              next_elmt->next = past_elmt;
              past_elmt->next = next_elmt;
              cur_elmt->next = NULL;
              list->head = next_elmt;
              list->tail = cur_elmt;
            }
        }
      else
        {
          while (1)
            {
              /*
               * cur > next
               */
              if (atoi(cur_person->name_num) > atoi(next_person->name_num))
                {
                  if (cur_elmt == list->head)
                    {
                      cur_elmt->next = next_elmt->next;
                      next_elmt->next = list->head;
                      list->head = next_elmt;
                    }
                  else if (next_elmt == list->tail)
                    {
                      next_elmt->next = past_elmt->next;
                      past_elmt->next = next_elmt;
                      cur_elmt->next = NULL;
                      list->tail = cur_elmt;
                    }
                  else
                    {
                      cur_elmt->next = next_elmt->next;
                      next_elmt->next = cur_elmt;
                      past_elmt->next = next_elmt;
                    }

                  past_elmt = next_elmt;
                  next_elmt = cur_elmt -> next;

                  if (next_elmt == NULL)
                    break;
                  cur_person = cur_elmt->data;
                  next_person = next_elmt->data;
                }
              else
                {
                  past_elmt = cur_elmt;
                  cur_elmt = next_elmt;
                  next_elmt = cur_elmt -> next;

                  if (next_elmt == NULL)
                    break;
                  cur_person = cur_elmt->data;
                  next_person = next_elmt->data;
                }
            }
        }
    }
}


/*
 *********************************************************************************************************
 *********************************************************************************************************
 *********************************************************************************************************
 *********************************************************************************************************
 *********************************************************************************************************
 *  * txt file load
 *   */

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
   *    *    * *ret 변수는 읽어온 값의 유무를 관리 한다
   *       *       * ret으로 파일 이 끝인지 아닌지 와 오류 
   *          *          * 유무를 확인할수 있기 때문에 필요하다.
   *             *             */

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
                  lines = gym_save_in_lines (lines, line);
                  free (line);
                  line = NULL;
                  break;
                }
            }
        }

      /*
       *        * 한 line이 끝나지 않았지만 buf가 꽉 찼다.
       *               * line에 담아두자.
       *                      */
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
gym_save_in_lines (char     **lines,
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
 *  * txt save file
 *   */
/*
void
store_file (gymperson   *list,
            int         cnt)
{
  int i;
  FILE *txtFP = fopen ("sublist.txt", "wt");

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

      fputs (list[i].weight, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].height, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].last_date, txtFP);
      fputs ("\n", txtFP);
    }

  fclose (txtFP);
}
*/

#if 0
char *
gym_merge_string (List      *list,
                  char      *merge_string)
{
  char *eig_num;
  int eig_len;
  ListElmt *elmt;

  elmt = list->head;
  eig_num = gym_eig_find (elmt);

  if (eig_num == NULL)
    {
      return NULL;
    }
  else
    {
      char *new_eig_num;
      char *add_token;
      char *get_str;
      int add_token_len;
      int get_str_len = 0;

      new_eig_num = (char *) malloc (sizeof (char));
      eig_len = strlen (eig_num);
      gym_next_eig (new_eig_num, eig_num, eig_len);

      add_token = strdup (new_eig_num);
      add_token_len = strlen (add_token);
      get_str = gym_new_input ();
      get_str_len = strlen (get_str);

      add_token = (char *) realloc (add_token, \
                                    sizeof (char) * ((add_token_len) + (get_str_len) + 1));
      strcat (add_token, get_str);
      add_token[add_token_len + get_str_len] = '\0';

      person = phone_list (add_token);
      elmt = list.head;
      list_ins_next (&list, elmt, person);
      free (new_eig_num);
    }

  gym_sort (&list);

  return merge_string;
}
#endif

char *
gym_eig_find (ListElmt *elmt)
{
  gymperson *person;
  gymperson *next_person;
  char *eig_num;
  char *next_num;
  int check_num;

  if (elmt->next == NULL)
    {
      eig_num = "0";
      return eig_num;
    }
  else
    {
      while (1)
        {
          if (elmt->next == NULL)
            {
              person = elmt->data;
              eig_num = person->name_num;

              return eig_num;
            }

          person = elmt->data;
          next_person = elmt->next->data;
          eig_num = person->name_num;
          next_num = next_person->name_num;

          check_num = (atoi (next_num) - atoi (eig_num));
          if (check_num != 1)
            {
              return eig_num;
            }

          elmt = elmt->next;
        }
    }

  return NULL;
}

char *
gym_next_eig (char     *eig_num,
              int      eig_len)
{
  int i, j;
  int count = 0;
  int back_len;
  char *back_num;

  back_num = strdup (eig_num);
  back_len = strlen (back_num);
  back_num[back_len - 1]++;

  for (i = eig_len - 1; i >= 0; --i)
    {
      if (back_num[count] >= ':')
        {
          back_num[count] -= 10;

          if (i == 0)
            {
              char *temp_num;
              temp_num = (char *) malloc (sizeof (char) * (back_len + 2));

              temp_num[i] = '1';
              for (j = 0; j < back_len; j++)
                {
                  temp_num[j + 1] = back_num[j];
                }
              temp_num[j] = '\0';
              free (back_num);
              back_num = strdup (temp_num);
              free (temp_num);
            }
          else
            {
              back_num[count + 1] = 49;
            }
        }

      count++;
    }

  return back_num;
}

void
gym_new_input (List *list)
{
  char *eig_num;
  int eig_len;

  ListElmt *elmt;
  gymperson *person;
  person = (gymperson *) malloc (sizeof (gymperson));

  elmt = list->head;
  eig_num = gym_eig_find (elmt);

  if (eig_num == NULL)
    {
      return;
    }
  else
    {
      char month[80];
      char buf_date[20];

      eig_len = strlen (eig_num);
      eig_num = gym_next_eig (eig_num, eig_len);
      strcpy (person->name_num, eig_num);
      free(eig_num);

      printf ("이름을 입력해주세요: ");
      gets (person->name);
      printf ("입관년도(ex:2011): ");
      gets (buf_date);
      strcpy (month, buf_date);
      strcat (month, "-");
      printf ("입관월(ex:01~12): ");
      gets (buf_date);
      strcat (month, buf_date);
      strcat (month, "-");
      printf ("입관일(ex:01~31): ");
      gets (buf_date);
      strcat (month, buf_date);
      strcpy (person->start_date, month);
      printf ("전화번호 입력: ");
      gets (person->phone);
      printf ("주소 입력: ");
      gets (person->addr);
      printf ("나이 입력: ");
      gets (person->age);
      printf ("몸무게 입력: ");
      gets (person->weight);
      printf ("신장 입력: ");
      gets (person->height);
      in_last_date (month, person);
      elmt = list->head;
      list_ins_next (list, elmt, person);
    }

  return;
}

void
gym_history (gymperson *person)
{
  FILE *fp;
  char file_name[SHORT_STR];
  char str[SHORT_STR];

  strcpy (file_name, "history/");
  strcat (file_name, person->name_num);
  strcat (file_name, ".txt");

  fp = fopen (file_name, "r");

  if (fp == NULL)
    {
      fp = fopen (file_name, "w+");
      if (fp == NULL)
        {
          printf ("경로가 잘못 되었습니다 문의 바랍니다.\n");
          return;
        }
      fputs (person->start_date, fp);
      fputc ('~', fp);
      fputs (person->last_date, fp);
      fputc ('\n', fp);
      fclose (fp);

      fp = fopen (file_name, "r");
      if (fp == NULL)
        {
          printf ("경로가 잘못 되었습니다 문의 바랍니다.\n");
          return;
        }
    }

  while ( fgets (str, SHORT_STR, fp) != NULL)
    {
      puts (str);
    }
  fclose (fp);
}

void
gym_money (List *list)
{
  int choice;
  time_t current;
  struct tm *sptime;
  char *buf;
  char current_day[40];
  memset (current_day, 0, 40);

  current = time (NULL);
  sptime = localtime (&current);

  buf = gym_get_current ((sptime->tm_year + 1900), 1000);
  strcat (current_day, buf);
  strcat (current_day, "-");
  free (buf);
  buf = gym_get_current ((sptime->tm_mon + 1), 10);
  strcat (current_day, buf);
  strcat (current_day, "-");
  free (buf);
  buf = gym_get_current ((sptime->tm_mday), 10);
  strcat (current_day, buf);
  strcat (current_day, "\0");
  free (buf);

  printf ("회비 관리\n");
  printf ("1.미납자 명단\n");
  printf ("2.기간 연장(01~12)(미구현)\n");
  printf ("3.추가 연장(2011-01-01)(미구현)\n");
  scanf ("%d", &choice);

  switch (choice)
    {
    case 1:
      gym_unpaid (list, current_day);
      break;
    case 2:
      break;
    case 3:
      break;
    default :
      printf ("입력이 바르지 않습니다.\n");
      break;
    }
}

char *
gym_get_current (int  in_time,
                 int  division)
{
  int i;
  int protion; //몫
  int rest;    //나머지
  char *buf;
  char time[10];
  memset (time, 0, 10);

  rest = in_time;
  for (i = 0; i < 20; i++)
    {
      protion = rest / division;
      rest %= division;
      division /= 10;

      time[i] = (protion + 48);
      if (division == 0)
        break;
    }
  buf = strdup (time);

  return buf;
}

void
gym_unpaid (List *list,
            char *current)
{
  int count = 0;
  char *past_year;
  ListElmt *elmt;
  gymperson *person;

  elmt = list->head;
  past_year = strdup (current);
  past_year[6] -= 2;

  if (past_year[6] <= '0') // 0 !0 5단위가 1 이냐 0이냐의 차이를 알아야 함
    {
      if (past_year[5] == '0')
        {
          if (past_year[3] >= '1')
            {
              past_year[3] -= 1;
            }
          else
            {
              if (past_year[2] >= '1')
                {
                  past_year[2] -= 1;
                  past_year[3] += 9;
                }
              else
                {
                  if (past_year[1] >= '1')
                    {
                      past_year[1] -= 1;
                      past_year[2] += 9;
                      past_year[3] += 9;
                    }
                  else
                    {
                      if (past_year[0] >= '1')
                        {
                          past_year[0] -= 1;
                          past_year[1] += 9;
                          past_year[2] += 9;
                          past_year[3] += 9;
                        }
                      else
                        {
                          printf ("고려시대 입니다 고갱님....\n");
                        }
                    }
                }
            }
          if (past_year[6] == '0')
            {
              past_year[5] = '1';
              past_year[6] = '2';
            }
          else
            {
              past_year[5] = '1';
              past_year[6] = '1';
            }
        }
      else
        {
          if (past_year[6] < '0')
            {
              past_year[5] = '0';
              if (past_year[6] == 47)
                {
                  past_year[6] = '9';
                }
              else
                {
                  past_year[6] = '8';
                }
            }
        }
    }

  printf ("현재 날짜 : %s 부터 %s 2개월 사이 까지 명단\n", current, past_year); 
  while (1)
    {
      if (elmt == NULL)
        break;

      person = elmt->data;
      if (1 <= strcmp (current, person->last_date))
        {
          if (1 <= strcmp (person->last_date, past_year))
            {
              count++;
              printf ("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
              printf ("회원번호 : %s  |  이름 : %s  | 최종납기일 : %s\n",
                      person->name_num, person->name, person->last_date);
              printf ("--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
            }
        }

      elmt = elmt->next;
    }
  printf ("2개월 안의 미납부자 총 %d명 입니다.\n", count);
}
