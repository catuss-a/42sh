/*
** ll_sort.c for libll in /u/all/serraj_y/cu/rendu/c/push_swap/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Jun 16 17:32:36 2010 younes serraj
** Last update Sun Oct  3 21:12:32 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

static void		static_ll_swap(t_ll_node *node_1,
				       t_ll_node *node_2)
{
  void			*data;

  if (!node_1 || !node_2)
    return ;
  data = node_1->data;
  node_1->data = node_2->data;
  node_2->data = data;
}

int			ll_sort(t_ll_list *list,
				int (*f_cmp)(void *, void *))
{
  t_ll_node		*w;
  t_ll_node		*wp;

  if (!list)
    return (-1);
  else if (list->count < 2)
    return (0);
  w = list->head;
  while (w->next)
    {
      if (f_cmp(w->data, w->next->data) > 0)
	{
	  wp = w->next;
	  while (wp->previous &&
		 f_cmp(wp->data, wp->previous->data) < 0)
	    {
	      static_ll_swap(wp, wp->previous);
	      wp = wp->previous;
	    }
	}
      w = w->next;
    }
  return (0);
}
