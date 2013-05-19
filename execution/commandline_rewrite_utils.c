/*
** commandline_rewrite_utils.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/execution
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Dec 17 16:42:26 2010 younes serraj
** Last update Sat Dec 18 22:25:42 2010 younes serraj
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "execution.h"

int			get_word_len(char *s)
{
  int			i;
  char			c;

  if (!*s)
    return (0);
  i = 0;
  if (IS_INHIBITOR(s[i]))
    {
      c = s[i++];
      while (s[i] && s[i] != c)
	{
	  if (s[i] == '\\' && !s[++i])
	    return (-1);
	  i += 1;
	}
      return (s[i] == c ? ++i : -1);
    }
  while (s[i] && !IS_SEPARATOR(s[i]))
    {
      if (s[i] == '\\' && !s[++i])
	return (-1);
      i += 1;
    }
  return (i);
}

void			apply_globing(char **cmdline)
{
  char			**wt;
  char			*buffer;
  int			i;

  if (!(wt = my_make_argv(*cmdline, 0)))
    return ;
  i = 0;
  while (wt[i])
    {
      buffer = NULL;
      if (!IS_INHIBITOR(*(wt[i])) && !get_globing(wt[i], &buffer))
	{
	  x_free(wt[i]);
	  wt[i] = buffer;
	}
      i += 1;
    }
  x_free(*cmdline);
  *cmdline = my_join(wt, " ");
  my_wt_free(wt);
  x_free(wt);
}
