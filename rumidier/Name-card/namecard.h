#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#define       SHORT_STR       40
#define       LONG_STR        80
#define       MAX_CNT         100


typedef struct _NameCard {
  char name[SHORT_STR];
  char company[LONG_STR];
  char position[SHORT_STR];
  char phone[SHORT_STR];
} namecard;

#endif
