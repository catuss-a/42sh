/*
** cd.c for minishell2 in /home/serraj_y//c/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 19:15:52 2010 younes serraj
** Last update Thu Dec  9 11:46:47 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "builtins.h"

static void		go_to(char *dest_path, t_config *conf, int *ret)
{
  char			*wt[4];
  char			*curr_dir;
  int			junk;

  curr_dir = getcwd(NULL, 0);
  if (chdir(dest_path) != 0)
    {
      x_free(curr_dir);
      *ret = -1;
      my_printf_err("'%s': path not found\n", dest_path);
      return ;
    }
  *ret = 0;
  x_free(conf->previous_dir);
  conf->previous_dir = curr_dir;
  wt[0] = NULL;
  wt[1] = my_strdup("PWD");
  wt[2] = dest_path;
  wt[3] = NULL;
  builtins_setenv(3, wt, conf, &junk);
  x_free(wt[1]);
}

int			builtins_cd(int argc, char **argv,
				    t_config *conf, int *ret)
{
  char			*path;

  if (argc > 2)
    {
      *ret = -1;
      my_puterr("Usage: cd [path]\n");
      return (MYSH_SIGNAL_NOPE);
    }
  path = get_absolute_path(conf, argv[1]);
  go_to(path, conf, ret);
  x_free(path);
  return (MYSH_SIGNAL_NOPE);
}
