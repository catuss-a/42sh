/*
** ll_clear_list.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:45:05 2010 younes serraj
** Last update Sat Sep 18 14:45:06 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

int			ll_clear_list(t_ll_list *list, void (*f_del)(void *))
{
  t_ll_node		*w;
  t_ll_node		*node;

  if (!list)
    return (-1);
  w = list->head;
  while (w)
    {
      node = w;
      if (f_del)
	f_del(node->data);
      w = w->next;
      free(node);
    }
  list->head = 0;
  list->tail = 0;
  list->count = 0;
  return (0);
}
