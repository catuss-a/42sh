/*
** my_strcpy.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:41:13 2010 younes serraj
** Last update Tue Dec 14 21:47:49 2010 younes serraj
*/

#include "my.h"

int			my_strcpy(char *dest, char *src)
{
  if (!dest || !src)
    return (0);
  while (*src)
    {
      *dest = *src;
      dest += 1;
      src += 1;
    }
  *dest = 0;
  return (0);
}
