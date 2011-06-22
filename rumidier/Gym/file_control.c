#include <stdio.h>
#include <string.h>

#include "file_control.h"
#include "gym.h"
#include "gym-control.h"

#define       BIN_FILE      "gymcount.bin"
#define       TXT_FILE      "gymList.txt"

/*
 * txt file load
 */
void
load_file (gymperson    *list,
           int          *cntPtr)
{
  int i, cnt, sLen;
  FILE *binFP = fopen (BIN_FILE, "rb");
  FILE *txtFP = fopen (TXT_FILE, "rt");

  if (binFP == NULL || txtFP == NULL)
    return ;

  fread ((void *)cntPtr, sizeof (int), 1, binFP);
  fclose (binFP);

  cnt = *cntPtr; //확실히 모르겠음
  for (i = 0; i < cnt; i++)
    {
      fgets (list[i].name, SHORT_STR, txtFP);
      sLen = strlen (list[i].name);
      list[i].name[sLen - 1] = '\0';

      fgets (list[i].start_date, SHORT_STR, txtFP);
      sLen = strlen (list[i].start_date);
      list[i].start_date[sLen - 1] = '\0';

      fgets (list[i].phone, SHORT_STR, txtFP);
      sLen = strlen (list[i].phone);
      list[i].phone[sLen - 1] = '\0';

      fgets (list[i].addr, SHORT_STR, txtFP);
      sLen = strlen (list[i].addr);
      list[i].addr[sLen - 1] = '\0';

      fgets (list[i].age, SHORT_STR, txtFP);
      sLen = strlen (list[i].age);
      list[i].age[sLen - 1] = '\0';

      fgets (list[i].kg, SHORT_STR, txtFP);
      sLen = strlen (list[i].kg);
      list[i].kg[sLen - 1] = '\0';

      fgets (list[i].height, SHORT_STR, txtFP);
      sLen = strlen (list[i].height);
      list[i].height[sLen - 1] = '\0';

      fgets (list[i].last_date, SHORT_STR, txtFP);
      sLen = strlen (list[i].last_date);
      list[i].last_date[sLen - 1] = '\0';

    }

  fclose (txtFP);
}

/*
 * txt save file
 */
void
store_file (gymperson   *list,
            int         cnt)
{
  int i;
  FILE *binFP = fopen (BIN_FILE, "wb");
  FILE *txtFP = fopen (TXT_FILE, "wt");

  fwrite ((void *) &cnt, sizeof (int), 1, binFP);
  fclose (binFP);

  for (i = 0; i < cnt; i++)
    {
      fputs (list[i].name, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].start_date, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].phone, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].addr, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].age, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].kg, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].height, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].last_date, txtFP);
      fputs ("\n", txtFP);
    }

  fclose (txtFP);
}
