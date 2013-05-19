/*
** my_isnum.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:41:24 2010 younes serraj
** Last update Thu Sep 30 17:31:13 2010 younes serraj
*/

#include "my.h"

int			my_isnum(char *s, int strict)
{
  if (!s || !*s)
    return (-1);
  if (strict == 0)
    while (*s == '+' || *s == '-')
      s += 1;
  if (*s && *s >= '0' && *s <= '9')
    return (0);
  return (-1);
}
