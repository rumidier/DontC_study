#ifndef   LIST_HEAD_H
#define   LIST_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define     LIST_FUNC_MAX_LEN     256
#define     LIST_FUNC_CSV         "linked-phone.csv" 
#define     LIST_FUNC_DELIM       ","
#define     ADD         "add"
#define     DEL         "del"
#define     CHANGE      "change"
#define     SEARCH      "search"

typedef struct _ListFuncPerson
{
  char *eig_no;
  char *ko_name;
  char *en_name;
  char *nick_name;
  char *my_phone;
  char *home_tel;
  char *work_tel;
  char *home_addr;
  char *work_addr;
  char *home_email;
  char *work_email;
  char *homepage;
  char *twitter;

  struct _ListFuncPerson *next;
} ListFuncPerson;

typedef struct _ListFuncPhonePoint
{
  int list_size;

  struct _ListFuncPerson *head;
  struct _ListFuncPerson *tail;
} ListFuncPhonePoint;

void
list_init (ListFuncPhonePoint *point);

char *
list_insert_link (ListFuncPhonePoint *point, ListFuncPerson *list_head, char *data);

int
list_cat_command (int, char **);

char **
list_cat_csv ();

char **
list_line_save_in_lines (char **lines, char *line);

void
list_insert_data (char **in_data, char *data, int count);

ListFuncPhonePoint *fir_point;
#endif
