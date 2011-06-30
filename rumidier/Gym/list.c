/**
 * list.c
 */

#include <stdlib.h>
#include <string.h>

#include "list.h"

/**
 * list_init
 */

void
list_init (List     *list,
           void    (*destroy) (void *data))
{
  /**
   * 리스트 초기화
   */

  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;

  return;
}

/**
 * list_destroy
 */
void
list_destroy (List *list)
{
  void *data;

  /**
   * 각 항목 삭제
   */
  while (list_size (list) > 0)
    {
      if (list_rem_next (list, NULL, (void **)&data) == 0 && list->destroy !=
          NULL)
        {
          list->destroy (data);
        }
    }

  /**
   * 지금은 아무 연산도 허용되지 않지만 예방책으로 구조체를 지움
   */

  memset (list, 0, sizeof (List));

  return;
}

/**
 * list_ins_next
 */

int
list_ins_next (List          *list,
               ListElmt      *element,
               const void    *data)
{
  ListElmt *new_element;
  /**
   * 항목을 위한 메모리 할당
   */

  if ((new_element = (ListElmt *) malloc (sizeof (ListElmt))) == NULL)
    return -1;

  /**
   * 리스트에 항목 삽입.
   */

  new_element->data = (void *) data;

  if (element == NULL) {
    /**
     * 리스트의 head에 삽입.
     */

    if (list_size (list) == 0)
      list->tail = new_element;

    new_element->next = list->head;
    list->head = new_element;
  }
  else
    {
      /**
       * head가 아닌 곳에 삽입 처리.
       */

      if (element->next == NULL)
        list->tail = new_element;

      new_element->next = element->next;
      element->next = new_element;
    }

  /**
   * 삽입된 항목을 반영하기 위해 리스트의 size 조정.
   */

  list->size++;

  return 0;
}

/**
 * list_rem_next
 */

int
list_rem_next (List      *list,
               ListElmt  *element,
               void      **data)
{
  ListElmt *old_element;

  /**
   * 빈 리스트에서 항목 삭제 금지.
   */

  if (list_size (list) == 0)
    return -1;

  /**
   * 리스트에서 항목 삭제.
   */

  if (element == NULL)
    {
      /**
       * head 항목 삭제.
       */
      *data = list->head->data;
      old_element = list->head;
      list->head = list->head->next;

      if (list_size (list) == 1)
        list->tail = NULL;
    }
  else
    {
      /**
       * head가 아닌 항목 삭제.
       */
      if (element->next == NULL)
        return -1;

      *data = element->next->data;
      old_element = element->next;
      element->next = element->next->next;

      if (element->next == NULL)
        list->tail = element;
    }
  /**
   * 추상 자료형에 할당된 메모리 해제.
   */

  free (old_element);

  /**
   * 삭제된 항목을 반영하기 위해 리스트의 size조정
   */

  list->size--;

  return 0;
}
