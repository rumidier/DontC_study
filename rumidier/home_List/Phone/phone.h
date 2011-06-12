#ifndef     PHONE_H
#define     PHONE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define     PHONE_MAX_LEN     256
#define     PHONE_CSV         "linked-phone.csv" 
#define     PHONE_DELIM       ","
#define     ADD               "add"
#define     DEL               "del"
#define     CHANGE            "change"
#define     SEARCH            "search"
#define     BIG_INT_USAGE          \
    "Usage:\n" \
    "     phone <command> [ options ]\n" \
    "\n" \
    "Command:\n" \
    "    add <string> <string>\n" \
    "        num1과 num2을 합한 값을 출력합니다.\n" \
    "\n" \
    "    del <string> <string>\n" \
    "        num1에서 numn2를 뺀 값을 출력합니다.\n" \
    "\n" \
    "    larger <num1> [ <num2>, ... ]\n" \
    "        입력한 숫자 중 가장 큰 수를 출력합니다.\n" \
    "\n" \
    "    smaller <num1> [ <num2>, ... ]\n" \
    "        입력한 숫자 중 가장 작은 수를 출력합니다.\n" \
    "\n" \
    "    sort ascend <num1> [ <num2>, ... ]\n" \
    "        입력한 숫자를 오름차순으로 정렬합니다.\n" \
    "\n" \
    "    sort descend <num1> [ <num2>, ... ]\n" \
    "        입력한 숫자를 내림차순으로 정렬합니다.\n" \
    "\n" \
    "    equal <num1> <num2>\n" \
    "        입력한 숫자가 같은지 다른지 여부를 TRUE/FALSE 형태로 출력합니다.\n"

typedef struct _PhonePerson {
  char *eig_no;
  char *ko_name;
  char *en_name;
  char *nick_name;
  char *my_tel;
  char *home_tel;
  char *work_tel;
  char *home_addr;
  char *work_addr;
  char *my_email;
  char *work_email;
  char *my_homepage;
  char *twitter;
} PhonePerson;

int
phone_cat_command (int,
                   char **);

char **
phone_cat_csv ();

char **
phone_save_in_lines (char **lines,
                     char *line);

PhonePerson *
phone_list (char *);

void
phone_destroy (void *data);

void
phone_print (ListElmt *elmt);

void
phone_person_print (PhonePerson *person);

void
phone_sort (List *list);

char **get_str;

void
phone_free_str (void);

void
phone_get_str (int ,
               char **);

ListElmt *
phone_find (ListElmt *elmt);

void
phone_search (List *list);

int
phone_search_str (PhonePerson *person,
                  char        *str);

ListElmt *
phone_past_list (List *list, ListElmt *del_elmt);

char *
phone_eig_find (ListElmt *elmt);

char *
phone_next_eig (char *, char *, int);

#endif
