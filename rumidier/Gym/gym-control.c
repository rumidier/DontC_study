#include <stdio.h>
#include <string.h>
#include "gym-control.h"
#include "gym.h"


/*
 * first menu
 */
void
show_menu (void)
{
  puts ("gnb-gym");
  puts ("1. 신규 등록");
  puts ("2. 회비 관리(미구현)");
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
void
insert_data (gymperson arr[],
             int      *cntPtr)
{
  int i;
  int cnt = *cntPtr;

  gymperson read;

  printf ("이름 : ");
  gets (read.name);
  printf ("입관일 : ");
  gets (read.start_date);
  printf ("전화번호 : ");
  gets (read.phone);
  printf ("주소 : ");
  gets (read.addr);
  printf ("나이 : ");
  gets (read.age);
  printf ("체중 : ");
  gets (read.kg);
  printf ("신장 : ");
  gets (read.height);
  in_last_date (read.start_date, &read);

  for (i = 0; i < cnt; i++)
    {
      if (!strcmp (read.name, arr[i].name)
          && !strcmp (read.phone, arr[i].phone))
        {
          puts ("동일인의 정보가 입력 되었습니다. \n");

          return;
        }
    }

  arr[cnt] = read;
  (*cntPtr)++;
  printf ("\n");
}

/*
 * search person (key: person name)
 */
void
search_data (gymperson arr[],
             int       cnt)
{
  int i;
  char name[SHORT_STR];

  printf ("찾고자 하는 이름 입력 : ");
  gets (name);

  for (i = 0; i < cnt; i++)
    {
      if (!strcmp (name, arr[i].name))
        {
          printf ("이름 : ");
          puts (arr[i].name);

          printf ("입관일 : ");
          puts (arr[i].start_date);

          printf ("전화번호 : ");
          puts (arr[i].phone);

          printf ("주소 : ");
          puts (arr[i].addr);

          printf ("나이 : ");
          puts (arr[i].age);

          printf ("체중 : ");
          puts (arr[i].kg);

          printf ("신장 : ");
          puts (arr[i].height);

          printf ("납입내역 : ");
          puts (arr[i].last_date);

        }
    }

  printf ("\n");
}

void
in_last_date (char       *save_month_ptr,
              gymperson  *read)
{
  //int i;
  char month[4];
  char save_month[10];

  printf ("납입내역(납일개월수) : ");
  gets (month);
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
sort_data (gymperson    *gym_list,
           int          data_count)
{
  int i, j;
  gymperson temp_gym;

  for (i = 0; i < (data_count - 1); i++)
    {
      for (j = 0; j < (data_count - i) - 1; j++)
        {
          if (0 > strcmp (gym_list[j].last_date, gym_list[j + 1].last_date))
            {
              temp_gym = gym_list[j];
              gym_list[j] = gym_list[j + 1];
              gym_list[j + 1] = temp_gym;
            }
        }
    }
}

void
no_insert_money (gymperson    *gym_list,
                 int          data_count)
{
  char input_date[20];
  int i;

  printf ("오늘 날짜를 입력해 주세요: ");
  gets (input_date);

  for (i = 0; i < data_count; i++)
    {
      if (1 <= strcmp (input_date, gym_list[i].last_date))
        {
          printf ("[[[%s]]\n", gym_list[i].last_date);
        }
    }

}
