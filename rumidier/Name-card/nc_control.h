#ifndef __NC_CONTROL_H__
#define __NC_CONTROL_H__

#include "namecard.h"

void
show_menu (void);

int
read_choice (void);

void
insert_data (namecard arr[],
            int      *cntPtr);
void
search_data (namecard arr[],
            int      cnt);
void
exit_prog (void);

#endif
