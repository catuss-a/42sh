/*
** my_strlen.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:43:04 2010 younes serraj
** Last update Sat Sep 18 14:43:05 2010 younes serraj
*/

#include "my.h"

int			my_strlen(char *s)
{
  int			i;

  if (!s)
    return (0);
  i = 0;
  while (s[i])
    i += 1;
  return (i);
}
