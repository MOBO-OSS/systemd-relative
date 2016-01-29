/* Test of environ variable.
   Copyright (C) 2008-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Bruno Haible <bruno@clisp.org>, 2008.  */

#include <config.h>

#include <unistd.h>

#include <string.h>

/* environ is the exported symbol referencing the internal
   __cygwin_environ variable on cygwin64:
   <https://cygwin.com/ml/cygwin/2013-06/msg00228.html>.  */
#if defined __CYGWIN__ && defined __x86_64__
extern DLL_VARIABLE char **environ;
#endif

int
main ()
{
  /* The environment variables that are set even in the weirdest situations
     are HOME and PATH.
     POSIX says that HOME is initialized by the system, and that PATH may be
     unset.  But in practice it's more frequent to see HOME unset and PATH
     set.  So we test the presence of PATH.  */
  char **remaining_variables = environ;
  char *string;

  for (; (string = *remaining_variables) != NULL; remaining_variables++)
    {
      if (strncmp (string, "PATH=", 5) == 0)
        /* Found the PATH environment variable.  */
        return 0;
    }
  /* Failed to find the PATH environment variable.  */
  return 1;
}
