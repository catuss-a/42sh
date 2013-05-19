/*
** ll_traverse.c for ll in /home/serraj_y//c/corewar/asmx/libs/ll
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:47:06 2010 younes serraj
** Last update Sun Oct 31 20:22:48 2010 younes serraj
*/

#include <stdlib.h>
#include "ll.h"

int			ll_traverse(t_ll_list *list, void (*action)(void *))
{
  return (ll_traverse_using_filter(list, action, NULL, NULL));
}
