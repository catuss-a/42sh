/*
** my_wt_print.c for my in /home/serraj_y//c/minishell2/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 20:33:43 2010 younes serraj
** Last update Mon Sep 20 20:34:49 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void			my_wt_print(char **wt)
{
  int			i;

  if (!wt)
    return ;
  i = 0;
  while (wt[i])
    {
      my_printf("%s\n", wt[i]);
      i += 1;
    }
}
