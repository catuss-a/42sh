/*
** my_strndup.c for my in /home/serraj_y//c/corewar/asmx
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Sep 17 16:51:43 2010 younes serraj
** Last update Fri Sep 17 16:52:13 2010 younes serraj
*/

#include "my.h"

char			*my_strndup(char *s, int n)
{
  char			*buffer;
  int			i;

  i = my_strlen(s);
  if (i > n)
    i = n;
  buffer = x_malloc(i + 1);
  my_strncpy(buffer, s, i);
  return (buffer);
}
