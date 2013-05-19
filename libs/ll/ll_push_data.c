/*
** ll_push_data.c for ll in /home/serraj_y//c/corewar/asmx
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Thu Sep 16 16:57:56 2010 younes serraj
** Last update Sun Oct  3 21:13:51 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

t_ll_node		*ll_push_data(t_ll_list *list,
				      void *data,
				      signed int id)
{
  t_ll_node		*node;

  node = ll_make_node(data);
  if (!node)
    return (0);
  ll_push_node(list, node, id);
  return (node);
}
