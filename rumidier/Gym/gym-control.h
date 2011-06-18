#ifndef _GYM_CONTROL_H
#define _GYM_CONTROL_H

#include "gym.h"

void
show_menu (void);

void
exit_prog (void);

int
read_choice (void);

void
insert_data (gymperson arr[],
             int      *cntPtr);

void
search_data (gymperson arr[],
             int       cnt);
void
in_last_date (char       *save_month_ptr,
              gymperson  *read);
void
sort_data (gymperson    gym_list[],
           int          data_count);
void
no_insert_money (gymperson    *gym_list,
                 int          data_count);


#endif
