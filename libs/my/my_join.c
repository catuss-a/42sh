/*
** my_join.c for my in /home/serraj_y//c/minishell2/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep 29 21:34:54 2010 younes serraj
** Last update Wed Sep 29 21:38:30 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

char			*my_join(char **wt, char *sep)
{
  int			i;
  char			*buffer;
  int			size;

  if (!wt)
    return (0);
  size = 0;
  i = 0;
  while (wt[i])
    {
      size += my_strlen(wt[i]);
      i += 1;
    }
  size += (my_strlen(sep) * i) + 1;
  buffer = x_malloc(sizeof(char) * size);
  *buffer = 0;
  i = 0;
  while (wt[i])
    {
      my_strcat(buffer, wt[i]);
      if (wt[i + 1])
	my_strcat(buffer, sep);
      i += 1;
    }
  return (buffer);
}
