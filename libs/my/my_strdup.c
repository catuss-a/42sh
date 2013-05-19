/*
** my_strdup.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:41:54 2010 younes serraj
** Last update Sat Sep 18 14:41:54 2010 younes serraj
*/

#include "my.h"

char			*my_strdup(char *s)
{
  char			*buffer;
  int			i;

  i = my_strlen(s);
  buffer = x_malloc(i + 1);
  if (!buffer)
    return (0);
  my_strcpy(buffer, s);
  return (buffer);
}
