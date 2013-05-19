/*
** history.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/headers
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Dec 13 20:53:58 2010 younes serraj
** Last update Tue Dec 14 22:11:22 2010 younes serraj
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "builtins.h"

int			builtins_history(int argc, char **argv,
					 t_config *conf, int *ret)
{
  t_history		*w;

  *ret = 0;
  if (argc == 2 && !my_strcmp(argv[1], "--help"))
    {
      printf("Displays the commands' history.\n");
      return (MYSH_SIGNAL_NOPE);
    }
  w = conf->cmdline.history;
  while (w)
    {
      printf("%s\n", w->data);
      w = w->next;
    }
  return (MYSH_SIGNAL_NOPE);
}
