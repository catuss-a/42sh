/*
** my_memrev.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Sep 17 16:23:16 2010 younes serraj
** Last update Fri Sep 17 18:26:41 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void			my_memrev(void *ptr, int size)
{
  char			*ptr_left;
  char			*ptr_right;
  int			i;

  if (size < 1)
    return ;
  ptr_left = (char *)ptr;
  ptr_right = ptr_left + size - 1;
  size /= 2;
  i = 0;
  while (i < size)
    {
      my_swap((void *)ptr_left, (void *)ptr_right);
      ptr_left += 1;
      ptr_right -= 1;
      i += 1;
    }
}
