/*
** my_strstr.c for my in /home/serraj_y//c/minishell2/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Sep 19 20:54:22 2010 younes serraj
** Last update Sun Sep 19 20:56:16 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

char			*my_strstr(char *s1, char *s2)
{
  int			len;

  if (!s1 || !s2 || !*s1 || !*s2)
    return (0);
  len = my_strlen(s2);
  while (*s1)
    {
      if (!my_strncmp(s1, s2, len))
	return (s1);
      s1 += 1;
    }
  return (0);
}
