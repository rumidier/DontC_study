#include <stdio.h>

static void
sec_to_hms (int sec);

int
main (int   argc,
      char *argv[])
{
  sec_to_hms (3245);
  sec_to_hms (5109);

  return 0;
}

static void
sec_to_hms (int sec)
{
  int time;
  int rest;

  time = 0;
  rest = 0;

  if (sec > 3599)
    {
      time = sec / 3600;
      rest = sec % 3600;
    }
  else
    {
      rest = sec;
    }
  printf ("%d시:", time);

  if (rest > 59)
  {
    time = rest / 60;
    rest %= 60;
  }
  printf ("%d분:", time);
  printf ("%d초\n", rest);




}
