#include "list_head.h"

int
main (int   argc,
      char *argv[])
{
  char buf[MAX_LEN];
  char **cat_lines;
  int i;
  int command_value = 0;

  /*
  if (argc != 3)
    {
      fputs ("입력 값이 잘못 되었습니다.\n", stdout);
      exit (EXIT_FAILURE);
    }
    */

  command_value = list_cat_command (argc, argv);

  cat_lines = list_cat_csv ();

  if (!cat_lines)
    {
      printf ("why return cat_lines\n");
      exit (EXIT_FAILURE);
    }

  fir_point = (ListFuncPhonePoint *) malloc (sizeof (ListFuncPhonePoint));
  list_init (fir_point);

  for (i = 0; cat_lines[i] != NULL; ++i)
    {
      char *token;

      token = cat_lines[i];

      list_insert_link (fir_point, fir_point -> head, token);
    }

  switch (command_value)
    {
    case 1://add
        {
          break;
        }
    case 2://del
        {
          break;
        }
    case 3://change
        {
          break;
        }
    case 4://search
        {
  //        list_search ();
          break;
        }
    default :
        {
          fputs ("command_value가 잘못 되었습니다.\n", stdout);
          break;
        }
    }
  fputs ("END!!!!!!!!!\n", stdout);
  //cat_lists free!! 

  return 0;
}
