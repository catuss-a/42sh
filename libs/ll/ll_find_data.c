/*
** ll_find_data.c for ll in /home/serraj_y//c/lemin/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Oct 31 20:07:49 2010 younes serraj
** Last update Sat Nov 13 20:56:42 2010 younes serraj
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
t_ll_node		*ll_find_data(t_ll_list *list,
				      int (*f_cmp)(void *, void *),
				      void *cmp_data)
{
  t_ll_node		*w;

  if (!list || list->count == 0 || f_cmp == NULL)
    return (NULL);
  w = list->head;
  while (w)
    {
      if (!f_cmp(cmp_data, w->data))
	return (w);
      w = w->next;
    }
  return (NULL);
}
