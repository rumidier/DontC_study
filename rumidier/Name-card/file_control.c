#include <stdio.h>
#include <string.h>
#include "namecard.h"

#define       BIN_FILE      "nccount.bin"
#define       TXT_FILE      "ncList.txt"

void
store_file (namecard   *list,
             int        cnt)
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

      fputs (list[i].company, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].position, txtFP);
      fputs ("\n", txtFP);

      fputs (list[i].phone, txtFP);
      fputs ("\n", txtFP);
    }

  fclose (txtFP);
}

void
load_file (namecard    *list,
           int         *cntPtr)
{
  int i, cnt, sLen;
  FILE *binFP = fopen (BIN_FILE, "rb");
  FILE *txtFP = fopen (TXT_FILE, "rt");

  if (binFP == NULL || txtFP == NULL)
    return ;

  fread ((void *)cntPtr, sizeof (int), 1, binFP);
  fclose (binFP);

  cnt =* cntPtr;
  for (i = 0; i < cnt; i++)
    {
      fgets (list[i].name, SHORT_STR, txtFP);
      sLen = strlen (list[i].name);
      list[i].name[sLen - 1] = '\0';

      fgets (list[i].company, LONG_STR, txtFP);
      sLen = strlen (list[i].company);
      list[i].company[sLen - 1] = '\0';

      fgets (list[i].position, SHORT_STR, txtFP);
      sLen = strlen (list[i].position);
      list[i].position[sLen - 1] = '\0';

      fgets (list[i].phone, SHORT_STR, txtFP);
      sLen = strlen (list[i].phone);
      list[i].phone[sLen - 1] = '\0';
    }

  fclose (txtFP);
}
