/*
** my_swap.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Sep 17 16:25:47 2010 younes serraj
** Last update Fri Sep 17 21:13:31 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void			my_swap(void *ptr1, void *ptr2)
{
  char			c;
  char			*p1;
  char			*p2;

  p1 = (char *)ptr1;
  p2 = (char *)ptr2;
  c = *p1;
  *p1 = *p2;
  *p2 = c;
}
