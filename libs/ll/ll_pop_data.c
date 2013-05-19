/*
** ll_pop_data.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:46:26 2010 younes serraj
** Last update Sun Nov 14 17:59:42 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

void			*ll_pop_data(t_ll_list *list, signed int id)
{
  t_ll_node		*node;
  void			*data;

  node = ll_pop_node(list, id);
  if (!node)
    return (NULL);
  data = node->data;
  free(node);
  return (data);
}
