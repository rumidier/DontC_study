#include <stdio.h>
#include "file_control.h"
#include "gym-control.h"
#include "gym.h"

enum {NEW = 1, MONEY = 2, PERSON = 3, EXIT = 4};

int
main (int   argc,
      char *argv[])
{
  int choice;
  int data_count;

  data_count = 0;

  gymperson gym_list[300];
  load_file (gym_list, &data_count);

  while (1)
    {
      show_menu ();
      choice = read_choice ();

      switch (choice)
        {
        case NEW:
          insert_data (gym_list, &data_count);
          break;
        case MONEY:
          sort_data (gym_list, data_count);
          no_insert_money (gym_list, data_count);
          break;
        case PERSON:
          search_data (gym_list, data_count);
          break;
        case EXIT:
          store_file (gym_list, data_count);
          exit_prog ();

          return 0;
        }
    }

  return 0;
}
