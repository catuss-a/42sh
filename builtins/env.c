/*
** env.c for minishell2 in /home/serraj_y//c/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 19:15:52 2010 younes serraj
** Last update Tue Dec 14 23:58:37 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"
#include "execution.h"
#include "shell.h"
#include "builtins.h"
#include "memory.h"

void			print_env_entry(t_var *var)
{
  my_printf("%s=%s\n", var->name, var->value);
}

int			builtins_env(int argc, char **argv,
				     t_config *conf, int *ret)
{
  char			*cmdline;
  t_config		c;

  if (argc == 1)
    {
      ll_traverse(&(conf->env), (void (*)(void *))print_env_entry);
      *ret = 0;
      return (MYSH_SIGNAL_NOPE);
    }
  else if (!my_strcmp(argv[1], "-i"))
    {
      cmdline = build_str_from_wt(argv, 2, argc - 1);
      my_memcpy(&c, conf, sizeof(t_config));
      my_exec(&c, cmdline, ret);
      x_free(cmdline);
      return (MYSH_SIGNAL_NOPE);
    }
  my_printf_err("'%s': unknown option\n", argv[1]);
  *ret = -1;
  return (MYSH_SIGNAL_NOPE);
}
