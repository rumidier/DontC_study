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
  printf ("납입내역 : ");
  gets (read.last_date);

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
