#include <stdio.h>

#include "list.h"
#include "gym-control.h"
#include "gym.h"

enum {NEW = 1, MONEY = 2, PERSON = 3, EXIT = 4};

int
main (int   argc,
      char *argv[])
{
  int choice;
  int i;
  char **cat_lines;

  gymperson *person;
  List list;
  ListElmt *elmt;

  cat_lines = gym_cat_csv ();
  list_init (&list, NULL);
  for (i = 0; cat_lines[i] != NULL; ++i)
    {
      char *token;

      token = cat_lines[i];

      person = gym_list (token);
      elmt = list.head;
      list_ins_next (&list, elmt, person);
    }
  gym_sort (&list);

  while (1)
    {
      show_menu ();
      choice = read_choice ();

      if (choice == EXIT)
      {
        //       store_file (gym_list, data_count);
        exit_prog ();
        break;
      }

      switch (choice)
        {
        case NEW:
          gym_new_input (&list);
          gym_sort (&list);

          elmt = list.head;
          gym_print (elmt);
          break;
        case MONEY:
          gym_money (&list);
          break;
        case PERSON:
          search_person (&list);
          break;
        }
    }

  return 0;
}
