/*
** ll_get_node.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:45:25 2010 younes serraj
** Last update Sun Oct  3 21:13:19 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

void			ll_optimize_search_id(t_ll_list *list, signed int *id)
{
  if (!list || list->count == 0 ||
      (*id > 0 && *id > list->count) ||
      (*id < 0 && *id < (list->count * -1)))
    {
      *id = 0;
      return ;
    }
  if (list->count == 1)
    return ;
  if (*id > 0 && *id > (list->count / 2))
    *id -= (list->count + 1);
  else if (*id < 0 && *id < ((list->count / 2) * -1))
    *id += list->count + 1;
}

static t_ll_node	*id_positive(t_ll_list *list, signed int id)
{
  t_ll_node		*w;
  int			i;

  i = 1;
  w = list->head;
  while (i < id)
    {
      i += 1;
      w = w->next;
    }
  return (w);
}

static t_ll_node	*id_negative(t_ll_list *list, signed int id)
{
  t_ll_node		*w;
  int			i;

  i = 1;
  w = list->tail;
  id *= -1;
  while (i < id)
    {
      i += 1;
      w = w->previous;
    }
  return (w);
}

t_ll_node	       	*ll_get_node(t_ll_list *list, signed int id)
{
  ll_optimize_search_id(list, &id);
  if (!list || id == 0)
    return (0);
  if (id > 0)
    return (id_positive(list, id));
  else
    return (id_negative(list, id));
}
