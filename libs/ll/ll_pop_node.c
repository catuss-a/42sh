/*
** ll_pop_node.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:46:33 2010 younes serraj
** Last update Sat Sep 18 14:46:33 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

t_ll_node		*ll_pop_node(t_ll_list *list, signed int id)
{
  t_ll_node		*node;

  ll_optimize_search_id(list, &id);
  if (!list || list->count == 0 || id == 0)
    return (0);
  else if (id == 1)
    return (ll_pop_head(list));
  else if (id == -1)
    return (ll_pop_tail(list));
  if (!(node = ll_get_node(list, id)))
    return (0);
  if (node->previous)
    node->previous->next = node->next;
  if (node->next)
    node->next->previous = node->previous;
  list->count -= 1;
  node->previous = 0;
  node->next = 0;
  return (node);
}
