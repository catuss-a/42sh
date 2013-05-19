/*
** my_wt_count.c for my in /home/serraj_y//c/minishell2/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 20:33:04 2010 younes serraj
** Last update Mon Sep 20 20:33:21 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

int		my_wt_count(char **wt)
{
  int		i;

  i = 0;
  while (wt[i])
    i += 1;
  return (i);
}
