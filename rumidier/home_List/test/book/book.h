#ifndef     BOOK_H
#define     BOOK_H

#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "list.h"

typedef struct _Book {
  char  *name;
  int   price;
  char  isbn[13];
  char  *arthor;
} Book;

Book *
book_insert (char  *name,
             int   price,
             char  *isbn,
             char  *arthor);

void
book_destroy (void *data);

ListElmt *
book_find (ListElmt *elmt,
           char     *name);

void
book_print (ListElmt *,
            Book     *);

#endif
