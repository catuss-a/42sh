/*
** ll_get_node_id.c for ll in /home/serraj_y//c/lemin/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Dec  8 13:03:01 2010 younes serraj
** Last update Wed Dec  8 13:08:52 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

/*
** cmp_data : comparison data.
** => f_cmp(cmp_data, node->data);
** f_cmp shall return :
**  (0) if DATA FOUND
** (-1) if DATA NOT FOUND
*/
int			ll_get_node_id(t_ll_list *list,
				       t_ll_node *node)
{
  int			i;
  t_ll_node		*w;

  if (!list || list->count == 0)
    return (0);
  i = 0;
  w = list->head;
  while (w)
    {
      i += 1;
      if (w == node)
	return (i);
      w = w->next;
    }
  return (0);
}
