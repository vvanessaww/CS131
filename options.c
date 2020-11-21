#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include "./options.h"
  
  /* Check arguments.  */
  int options (bool valid, long long nbytes, int argc, char **argv)
  {
  if (argc == 2)
    {
      char *endptr;
      errno = 0;
      nbytes = strtoll (argv[1], &endptr, 10);
      if (errno)
	perror (argv[1]);
      else
	valid = !*endptr && 0 <= nbytes;
    }
  if (!valid)
    {
      fprintf (stderr, "%s: usage: %s NBYTES\n", argv[0], argv[0]);
      return 1;
    }
  /* If there's no work to do, don't worry about which library to use.  */
  if (nbytes == 0)
    return 0;
  }