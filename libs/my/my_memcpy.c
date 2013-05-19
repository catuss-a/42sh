/*
** my_memcpy.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Sep 17 16:54:36 2010 younes serraj
** Last update Fri Sep 17 16:56:29 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void			my_memcpy(void *dest, void *src, int size)
{
  char			*ptr_dest;
  char			*ptr_src;
  int			i;

  i = 0;
  ptr_dest = (char *)dest;
  ptr_src = (char *)src;
  while (i < size)
    {
      ptr_dest[i] = ptr_src[i];
      i += 1;
    }
}
