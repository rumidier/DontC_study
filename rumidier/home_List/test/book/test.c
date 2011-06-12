#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "book.h"

int
main (int   argc,
      char *argv[])
{
  int size;

  List list;
  Book *book;
  ListElmt *elmt;
  list_init (&list, (void *)book_destroy);


  book = book_insert ("난 정말 C PROGRAMMING을 공부한적이 없다구요!", 27000, "978-89-960940", "윤성우");
  list_ins_next (&list, list.head, (void *) book);

  elmt = list.head;
  book = book_insert ("C로 배우는 알고리즘", 23000, "89-317-0139-x", "이재규");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("C로 구현한 알고리즘", 25000, "89-7914-063-0", "카일루든");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("C프로그래밍과 스타일링", 20000, "978-89-7085-9", "오일석");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("거침없이 배우는 펄", 27000, "978-89-93827-", "Randal L. Schwartz");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("Git, 분산버전 관리시스템", 20000, "978-89-91268-", "트라비스 스위스굿");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("성공과 실패를 결정하는 1%의 프로그래밍 원리", 14800, "89-315-4739-0", "Hisao Yawzwa");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("열혈 TCP/IP 소켓 프로그래밍", 26000, "978-89-960940", "윤성우");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("The Practice of Programming", 20000, "978-89-91268-", "브라이언 W. 커니핸");
  list_ins_next (&list, elmt, (void *) book);

  elmt = elmt->next;
  book = book_insert ("C언어 펀더멘탈", 32000, "89-7914-217-x", "전웅");
  list_ins_next (&list, elmt, (void *) book);

  elmt = list.head;
  Book *new_book;
  book_print (elmt, new_book);

  elmt = list.head;
  elmt = book_find (elmt,"성공과 실패를 결정하는 1%의 프로그래밍 원리");
  if (elmt == NULL)
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }
  else
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }

  elmt = list.head;
  if (size != list.size)
    book_print (elmt, new_book);

  elmt = book_find (elmt,"난 정말 C PROGRAMMING을 공부한적이 없다구요!");
  if (elmt == NULL)
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }
  else
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }

  elmt = list.head;

  if (size != list.size)
    book_print (elmt, new_book);

  elmt = book_find (elmt, "C언어 펀더멘탈");
  if (elmt == NULL)
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }
  else
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }
  elmt = list.head;

  if (size != list.size)
    book_print (elmt, new_book);

  elmt = book_find (elmt, "C언어 펀더멘탈");
  if (elmt == NULL)
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }
  else
    {
      size = list.size;
      new_book = list.head->data;
      list_rem_next (&list, elmt, (void **) &new_book);

      if (size != list.size)
        {
          book_destroy (new_book);
        }
    }
  elmt = list.head;

  if (size != list.size)
    book_print (elmt, new_book);
  else
    {
      printf ("원하시는 책이 없습니다.\n");
    }

  elmt = list.head;
  book = book_insert ("C언어 펀더멘탈", 32000, "89-7914-217-x", "전웅");
  list_ins_next (&list, elmt, (void *) book);
  book_print (elmt, new_book);

  list_destroy (&list);
  elmt = list.head;
  book_print (elmt, new_book);

  return 0;
}
