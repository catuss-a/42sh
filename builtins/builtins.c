/*
** builtins.c for minishell2 in /home/serraj_y//c/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Sep 19 20:14:08 2010 younes serraj
** Last update Sat Dec 18 16:57:33 2010 stephane delmas
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"
#include "builtins.h"
#include "shell.h"

t_builtins_f	builtins_list[] = {
  {"exit", builtins_exit},
  {"echo", builtins_echo},
  {"env", builtins_env},
  {"setenv", builtins_setenv},
  {"unsetenv", builtins_unsetenv},
  {"set", builtins_set},
  {"unset", builtins_unset},
  {"cd", builtins_cd},
  {"history", builtins_history},
  {"jobs", builtins_jobs},
  {"fg", builtins_fg},
  {"bg", builtins_fg},
  {0, 0}
};

int			is_builtin(char *name)
{
  int			i;

  i = 0;
  while (builtins_list[i].f)
    {
      if (!my_strcmp(name, builtins_list[i].name))
	return (0);
      i += 1;
    }
  return (-1);

}

int			exec_builtin(int argc, char **argv,
				     t_config *conf, int *ret)
{
  int			i;

  i = 0;
  while (builtins_list[i].f)
    {
      if (!my_strcmp(argv[0], builtins_list[i].name))
	return (builtins_list[i].f(argc, argv, conf, ret));
      i += 1;
    }
  my_printf_err("'%s': unknown builtin\n", argv[0]);
  return (MYSH_SIGNAL_NOPE);
}
