#include <stdio.h>
#include <string.h>
#include "namecard.h"

void
show_menu (void)
{
  puts ("선택하세요");
  puts ("1. 정보 입력");
  puts ("2. 정보 검색");
  puts ("3. 종료");

  printf (">> ");
}

int
read_choice (void)
{
  int choice;
  scanf ("%d", &choice);
  getchar ();

  return choice;
}

void
insert_data (namecard arr[],
             int      *cntPtr)
{
  int i;
  int cnt = *cntPtr;

  namecard read;

  printf ("이름 : ");
  gets (read.name);
  printf ("회사 : ");
  gets (read.company);
  printf ("직급 : ");
  gets (read.position);
  printf ("전화번호 : ");
  gets (read.phone);

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

void
search_data (namecard arr[],
             int      cnt)
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
          printf ("회사 : ");
          puts (arr[i].company);
          printf ("직급 : ");
          puts (arr[i].position);
          printf ("전화번호 : ");
          puts (arr[i].phone);

        }
    }

  printf ("\n");
}

void
exit_prog (void)
{
  puts ("이용해 주셔서 감사합니다.");
}
