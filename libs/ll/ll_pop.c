/*
** ll_pop.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:46:17 2010 younes serraj
** Last update Sat Sep 18 14:46:17 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

t_ll_node		*ll_pop_head(t_ll_list *list)
{
  t_ll_node		*node;

  if (!list || list->count == 0)
    return (0);
  node = list->head;
  list->head = node->next;
  if (list->head)
    list->head->previous = 0;
  list->count -= 1;
  if (list->count == 0)
    list->tail = 0;
  node->previous = 0;
  node->next = 0;
  return (node);
}

t_ll_node		*ll_pop_tail(t_ll_list *list)
{
  t_ll_node		*node;

  if (!list || list->count == 0)
    return (0);
  else if (list->count == 1)
    return (ll_pop_head(list));
  node = list->tail;
  list->tail = node->previous;
  list->tail->next = 0;
  list->count -= 1;
  if (list->count == 1)
    list->head = list->tail;
  node->previous = 0;
  node->next = 0;
  return (node);
}
