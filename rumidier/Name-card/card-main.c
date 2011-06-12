#include <stdio.h>
#include "namecard.h"
#include "nc_control.h"
#include "file_control.h"

enum {INSERT = 1, SEARCH = 2, EXIT = 3};

int
main (int   argc,
      char *argv[])
{
  int data_count;
  data_count = 0;

  namecard nc_list[MAX_CNT];
  load_file (nc_list, &data_count);

  while (1)
    {
      int choice;

      show_menu ();
      choice = read_choice ();

      switch (choice)
        {
        case INSERT:
          insert_data (nc_list, &data_count);
          break;
        case SEARCH:
          search_data (nc_list, data_count);
          break;
        case EXIT:
          store_file (nc_list, data_count);
          exit_prog ();

          return 0;
        }
    }

  return 0;
}
