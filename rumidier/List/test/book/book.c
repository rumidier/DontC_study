#include "book.h"

Book *
book_insert (char  *name,
             int   price,
             char  *isbn,
             char  *arthor)
{
  int name_len;
  int arthor_len;

  Book *new_book;
  new_book = (Book *) malloc (sizeof (Book) * 1);


  name_len = strlen (name);
  new_book->name = (char *) malloc (sizeof (char) * (name_len + 1));
  new_book->name = strdup (name);

  new_book->price = price;
  memcpy (new_book->isbn, isbn, 13);

  arthor_len = strlen (arthor);
  new_book->arthor = (char *) malloc (sizeof (char) * (arthor_len + 1));
  new_book->arthor = strdup (arthor);

  return new_book;
}

ListElmt *
book_find (ListElmt *elmt,
           char     *name)
{
  ListElmt *past_elmt;
  Book *book;

  past_elmt = NULL;

  while (1)
    {
      if (elmt == NULL)
        {
          break;
        }
      book = elmt->data;
      if (!strcmp (book->name, name))
        return past_elmt;

      past_elmt = elmt;
      elmt = elmt->next;
    }

  return past_elmt;
}

void
book_print (ListElmt *elmt,
            Book     *book)
{
  int count = 1;

  if (elmt != NULL)
    {
      while (1)
        {
          printf ("count : [%d]\n", count);
          book = elmt->data;
          printf ("name[%s]\n", book->name);
          printf ("prince [%d]\n", book->price);
          printf ("isbn   [%s]\n", book->isbn);
          printf ("arthor [%s]\n\n", book->arthor);

          if (elmt->next == NULL)
            break;
          elmt = elmt->next;
          count++;
        }
    }
    
  fputs ("--------------------------------\n", stdout);
}

void
book_destroy (void *data)
{
  Book *book;
  book = data;

  free (book->name);
  free (book->arthor);
}
