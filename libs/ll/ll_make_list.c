/*
** ll_make_list.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:45:50 2010 younes serraj
** Last update Sat Sep 18 14:45:51 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

t_ll_list			*ll_make_list()
{
  t_ll_list			*list;

  list = malloc(sizeof(t_ll_list));
  if (!list)
    return (0);
  ll_init_list(list);
  return (list);
}
