/*
** my_trim.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:44:40 2010 younes serraj
** Last update Sat Dec 18 22:08:47 2010 younes serraj
*/

#include "my.h"

int			my_trim(char *s, char *sep)
{
  int			i;

  if (!s || !sep)
    return (-1);
  if (!*s || !*sep)
    return (0);
  i = my_strlen(s) - 1;
  while (i >= 0 && my_findchar(s[i], sep) > -1)
    {
      s[i] = 0;
      i -= 1;
    }
  i = 0;
  while (s[i] && my_findchar(s[i], sep) > -1)
    i += 1;
  if (i > 0)
    my_strcpy(s, s + i);
  return (0);
}
