/*
** ll_delete_node.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:45:15 2010 younes serraj
** Last update Fri Nov 19 17:29:20 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

int			ll_delete_node(t_ll_list *list,
				       signed int id,
				       void (*f_del)(void *))
{
  t_ll_node		*node;

  if (!list || (id < 0 ? (id * -1) : id) > list->count)
    return (-1);
  node = ll_get_node(list, id);
  if (!node)
    return (-1);
  if (f_del)
    f_del(node->data);
  if (node->previous)
    node->previous->next = node->next;
  if (node->next)
    node->next->previous = node->previous;
  if (list->head == node)
    list->head = node->next;
  if (list->tail == node)
    list->tail = node->previous;
  free(node);
  list->count -= 1;
  return (0);
}

int			ll_delete_node_byaddr(t_ll_list *list,
					      t_ll_node *addr,
					      void (*f_del)(void *))
{
  signed int		id;
  t_ll_node		*w;

  w = list->head;
  id = 0;
  while (w)
    {
      id += 1;
      if (w == addr)
	return (ll_delete_node(list, id, f_del));
      w = w->next;
    }
  return (-1);
}

int			ll_delete_node_by_data_addr(t_ll_list *list,
						    void *data_addr,
						    void (*f_del)(void *))
{
  signed int		id;
  t_ll_node		*w;

  w = list->head;
  id = 0;
  while (w)
    {
      id += 1;
      if (w->data == data_addr)
	return (ll_delete_node(list, id, f_del));
      w = w->next;
    }
  return (-1);
}
