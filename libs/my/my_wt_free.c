/*
** my_wt_free.c for my in /home/serraj_y//c/minishell2/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 20:32:32 2010 younes serraj
** Last update Sun Oct  3 21:54:14 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void		my_wt_free(char **wt)
{
  int		i;

  i = 0;
  while (wt[i])
    {
      x_free(wt[i]);
      i += 1;
    }
}
