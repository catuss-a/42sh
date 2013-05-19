/*
** ll_init_list.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:45:40 2010 younes serraj
** Last update Wed Dec 15 18:57:56 2010 stephane delmas
*/

#include <stdlib.h>
#include "ll.h"

void			ll_init_list(t_ll_list *list)
{
  if (!list)
    return ;
  list->head = 0;
  list->tail = 0;
  list->count = 0;
  list->is_job = 0;
}
