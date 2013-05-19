/*
** query_out.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 19:59:48 2010 younes serraj
** Last update Sun Dec 19 23:22:43 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"
#include "config.h"
#include "builtins.h"

int			query_out(char *line,
				  t_config *conf, int *ret)
{
  int			argc;
  char			**argv;
  int			sig;

  if ((argv = my_make_argv(line, 1)) == NULL)
    {
      my_puterr("Error: my_make_argv() failed\n");
      return (MYSH_SIGNAL_NOPE);
    }
  argc = my_wt_count(argv);
  if (!is_builtin(argv[0]))
    sig = exec_builtin(argc, argv, conf, ret);
  else
    {
      my_wt_free(argv);
      x_free(argv);
      argv = my_split(line, SEPARATORS);
      sig = execute(argv, conf, ret);
    }
  my_wt_free(argv);
  x_free(argv);
  return (sig);
}
