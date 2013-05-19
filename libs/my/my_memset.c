/*
** my_memset.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep  6 14:34:40 2010 younes serraj
** Last update Mon Sep  6 14:34:41 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void			my_memset(void *ptr, char c, int size)
{
  int			i;
  char			*addr;

  addr = (char *)ptr;
  i = 0;
  while (i < size)
    {
      *addr = c;
      addr += 1;
      i += 1;
    }
}
