/*
** ll_make_node.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:46:04 2010 younes serraj
** Last update Sat Sep 18 14:46:04 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

t_ll_node			*ll_make_node(void *data)
{
  t_ll_node			*node;

  node = malloc(sizeof(t_ll_node));
  if (!node)
    return (0);
  node->data = data;
  node->previous = 0;
  node->next = 0;
  return (node);
}
