/*
** keywords.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/execution
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Dec 11 19:33:24 2010 younes serraj
** Last update Sat Dec 11 21:28:46 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "execution.h"

static int		get_keyword_id(char *s)
{
  int			i;

  i = 0;
  while (keywords[i])
    {
      if (!my_strncmp(s, keywords[i], my_strlen(keywords[i])))
	return (i);
      i += 1;
    }
  return (-1);
}

int			get_keyword_length(char *s)
{
  int			i;

  if ((i = get_keyword_id(s)) == -1)
    return (0);
  else
    return (my_strlen(keywords[i]));
}
