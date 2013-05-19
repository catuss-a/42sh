/*
** ll_traverse_using_filter.c for minishell2 in /home/serraj_y//c/minishell2/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Sep 21 21:08:39 2010 younes serraj
** Last update Tue Nov  2 23:43:40 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

/*
** Returns -1 on error, or the number of matches.
*/
int			ll_traverse_using_filter(t_ll_list *list,
						 void (*action)(void *),
						 int (*filter)(void *, void *),
						 void *param)
{
  int			i;
  t_ll_node		*w;

  if (!list || action == NULL)
    return (-1);
  i = 0;
  w = list->head;
  while (w)
    {
      if (filter)
	{
	  if (!filter(param, w->data))
	    {
	      action(w->data);
	      i += 1;
	    }
	}
      else
	action(w->data);
      w = w->next;
    }
  return (i);
}
