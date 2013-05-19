/*
** my_findchar.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:41:34 2010 younes serraj
** Last update Tue Dec  7 14:57:01 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

int			my_findchar(char c, char *s)
{
  int			i;

  if (!c)
    return (-1);
  i = 0;
  while (s[i] && s[i] != c)
    i += 1;
  if (s[i] == c)
    return (i);
  return (-1);
}
