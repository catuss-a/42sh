/*
** my_strncpy.c for  in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:41:04 2010 younes serraj
** Last update Sat Sep 18 14:41:06 2010 younes serraj
*/

#include "my.h"

int			my_strncpy(char *dest, char *src, int n)
{
  int			i;

  i = 0;
  while (*src && i < n)
    {
      *dest = *src;
      dest += 1;
      src += 1;
      i += 1;
    }
  *dest = 0;
  return (0);
}
