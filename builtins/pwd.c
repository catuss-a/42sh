/*
** pwd.c for 42sh in /home/serraj_y//c/_backups/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Nov 16 12:14:41 2010 younes serraj
** Last update Tue Nov 16 12:35:40 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "builtins.h"

int			builtins_pwd(int argc, char **argv,
				     t_config *conf, int *ret)
{
  char			*path;

  if (argc > 1)
    my_puterr("Warning: pwd takes no argument\n");
  path = getcwd(NULL, 0);
  my_printf("%s\n", path);
  x_free(path);
  return (MYSH_SIGNAL_NOPE);
}
