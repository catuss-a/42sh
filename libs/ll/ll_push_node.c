/*
** ll_push_node.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:46:52 2010 younes serraj
** Last update Sun Oct  3 21:14:03 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

/*
** 'id' represents the location where the user wishes to insert the node.
** if 'id' is greater than 0, the list will be traversed from the head.
** if 'id' is less than 0, the list will be traversed backwards (from the tail)
** 'id' 0 is invalid.
*/
int			ll_push_node(t_ll_list *list,
				     t_ll_node *node,
				     signed int id)
{
  t_ll_node		*w;

  if (!list || !node || id == 0)
    return (-1);
  if (list->count == 0 || id == 1 || (id * -1) > list->count)
    return (ll_push_node_head(list, node));
  else if (id == -1 || id > list->count)
    return (ll_push_node_tail(list, node));
  w = ll_get_node(list, id - (id > 0 ? 1 : 0));
  node->previous = w;
  node->next = w->next;
  w->next->previous = node;
  w->next = node;
  list->count += 1;
  return (0);
}
