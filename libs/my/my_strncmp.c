/*
** my_strncmp.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:40:44 2010 younes serraj
** Last update Sat Sep 18 14:40:45 2010 younes serraj
*/

#include "my.h"

int			my_strncmp(char *s1, char *s2, int n)
{
  int			i;

  i = 0;
  while (*s1 && *s1 == *s2 && i < n)
    {
      s1 += 1;
      s2 += 1;
      i += 1;
    }
  if (i == n)
    return (0);
  return (*s1 - *s2);
}
