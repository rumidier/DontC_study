#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct name
{
  char *ko_name;
  char *en_name;
  char *nick_name;
} Name;

typedef struct phone_num
{
  int *phone_number;
  int *home_number;
  int *work_number;
} Phone;

typedef struct address
{
  char *home_addre;
  char *work_addre;
  char *my_email;
  char *work_email;
  char *e_home;
  char *twitter;
} Address;

typedef struct phone_list
{
  int eig_no;

  Name *in_name;
  Phone *in_phone;
  Address *in_addr;

  struct phone_list *next;
} PhoneList;

typedef struct phone_point
{
  int list_size;

  PhoneList *head;
  PhoneList *tail;
} PhonePoint;

PhonePoint *fir_point;

void
list_init (PhonePoint *point);

void
list_insert (PhonePoint *point, PhoneList *list_head, char *data);

int
main (int   argc,
      char *argv[])
{
  fir_point = (PhonePoint *) malloc (sizeof (PhonePoint));
  list_init (fir_point);

  list_insert (fir_point, fir_point -> head, "data");

  return 0;
}

void
list_init (PhonePoint *point)
{
  point -> list_size = 0;
  point -> head = NULL;
  point -> tail = NULL;
}

void
list_insert (PhonePoint *point, PhoneList *list_head, char *data)
{
  printf ("윙?\n");
}
