/*
** x_getenv_term.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Jul  7 16:36:43 2010 younes serraj
** Last update Wed Jul  7 16:36:44 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "tc.h"

char			*x_getenv_term()
{
  extern char		**environ;
  int			i;

  if (!environ)
    return (0);
  i = 0;
  while (environ[i])
    {
      if (!my_strncmp(environ[i], "TERM=", 5))
	return (environ[i] + 5);
      i += 1;
    }
  return (0);
}
