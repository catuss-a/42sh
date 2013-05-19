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

int			builtins_echo(int argc, char **argv,
				      t_config *conf, int *ret)
{
  int			i;
  char			n;

  conf = NULL;
  n = 1;
  i = 1;
  if (argc >= 2 && !my_strcmp(argv[1], "-n"))
    {
      i += 1;
      n = 0;
    }
  while (i < argc)
    {
      my_putstr(argv[i]);
      i += 1;
      if (i < argc)
	my_putchar(' ');
    }
  if (n)
    my_putchar('\n');
  *ret = 0;
  return (MYSH_SIGNAL_NOPE);
}
