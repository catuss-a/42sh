/*
** exit.c for minishell2 in /home/serraj_y//c/minishell2
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 19:11:10 2010 younes serraj
** Last update Mon Dec 13 20:54:24 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "builtins.h"

/*
** builtins_exit is used in an array of pointers on function.
** Thus, it must have the same function arguments.
** 'conf' here is useless, so I used 'conf = 0;' to
** shut down the warning associated to this unused variable.
*/
int			builtins_exit(int argc, char **argv,
				      t_config *conf, int *ret)
{
  conf = 0;
  if (argc == 1)
    {
      *ret = 0;
      return (MYSH_SIGNAL_EXIT);
    }
  else
    {
      if (argc > 2 || my_isnum(argv[1], 1))
	{
	  my_puterr("exit: Expression Syntax\n");
	  *ret = -1;
	  return (MYSH_SIGNAL_NOPE);
	}
      *ret = atoi(argv[1]);
      return (MYSH_SIGNAL_EXIT);
    }
}
