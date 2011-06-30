#ifndef _GYM_CONTROL_H
#define _GYM_CONTROL_H

#include "list.h"
#include "gym.h"

void
show_menu (void);

char **
gym_cat_csv ();

char **
gym_save_in_lines (char    **lines,
                   char    *line);
void
csv_parser_debug_lines (char **lines);


void
exit_prog (void);

int
read_choice (void);

void
search_person (List *list);

void
in_last_date (char       *save_month_ptr,
              gymperson  *read);

void
no_insert_money (gymperson    *gym_list,
                 int          data_count);
gymperson *
gym_list (char *str);

void
gym_print (ListElmt *elmt);

void
gym_person_print (gymperson *person);

void
gym_sort (List *list);

char *
gym_eig_find (ListElmt *elmt);

char *
gym_next_eig (char *eig_num,
              int   eig_len);

void
gym_new_input (List *list);

void
gym_history (gymperson *person);

void
gym_money (List *list);

char *
gym_get_current (int  time,
                 int  division);

void
gym_unpaid (List *list,
            char *current);

#endif
