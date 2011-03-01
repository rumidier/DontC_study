#include <stdio.h>

static void
show_star_line (void)
{
  printf ("*************** \n");
}

static void
show_wave_line (void)
{
  printf ("~~~~~~~~~~~~~~~ \n");
}

int
main (int   argc,
      char *argv[])
{
  show_star_line ();
  show_wave_line ();

  return 0;
}
