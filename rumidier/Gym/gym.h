#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#define       SHORT_STR       40
#define       LONG_STR        80
#define       MAX_CNT         100


typedef struct _GymPerson {
  char name[SHORT_STR];
  char name_num[SHORT_STR];
  char start_date[SHORT_STR];
  char phone[SHORT_STR];
  char addr[LONG_STR];
  char age[SHORT_STR];
  char kg[SHORT_STR];
  char height[SHORT_STR];
  char last_date[SHORT_STR];
} gymperson;

#endif
