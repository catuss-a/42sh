/*
** ll_push.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:46:42 2010 younes serraj
** Last update Sat Sep 18 14:46:43 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

int			ll_push_node_head(t_ll_list *list, t_ll_node *node)
{
  if (!list)
    return (-1);
  node->next = list->head;
  if (list->head)
    list->head->previous = node;
  node->previous = 0;
  list->head = node;
  if (!(list->tail))
    list->tail = node;
  list->count += 1;
  return (0);
}

int			ll_push_node_tail(t_ll_list *list, t_ll_node *node)
{
  if (!list)
    return (-1);
  if (list->count == 0)
    return (ll_push_node_head(list, node));
  list->tail->next = node;
  node->next = 0;
  node->previous = list->tail;
  list->tail = node;
  list->count += 1;
  return (0);
}
