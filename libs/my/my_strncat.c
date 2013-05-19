/*
** my_strncat.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:42:49 2010 younes serraj
** Last update Sat Sep 18 14:42:50 2010 younes serraj
*/

#include "my.h"

int			my_strncat(char *dest, char *s, int n)
{
  int			i;

  i = my_strlen(dest);
  my_strncpy(dest + i, s, n);
  return (0);
}
