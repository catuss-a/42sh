/*
** x_malloc.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:44:46 2010 younes serraj
** Last update Sat Sep 18 14:44:47 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void			*x_malloc(int i)
{
  void			*ptr;

  ptr = malloc(i);
  if (!ptr)
    {
      my_puterr("Error: malloc() failed\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
