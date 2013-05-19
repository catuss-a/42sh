/*
** is_valid_command.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Thu Sep 30 17:05:15 2010 younes serraj
** Last update Sat Oct  2 18:20:15 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"
#include "config.h"
#include "shell.h"
#include "memory.h"
#include "system.h"

static int		is_keyword(char *s)
{
  if (!my_strcmp(s, "<") ||
      !my_strcmp(s, "<<") ||
      !my_strcmp(s, ">") ||
      !my_strcmp(s, ">>") ||
      !my_strcmp(s, "|"))
    return (0);
  return (-1);
}

static int		check_pipe(char **argv, int i,
				   int *flags)
{
  if (flags[OUT] != 0)
    {
      my_puterr("Error: Ambiguous input redirect\n");
      return (-1);
    }
  else if (flags[PROG] == 0 || argv[i + 1] == 0 ||
	   !my_strcmp(argv[i + 1], "|"))
    {
      my_puterr("Error: Invalid null command\n");
      return (-1);
    }
  flags[IN] = 1;
  flags[OUT] = 0;
  flags[PROG] = 0;
  return (0);
}

static int		check_redirection(char **argv, int *i,
					  int *flag)
{
  if (*flag != 0)
    {
      my_puterr("Error: Ambiguous input redirect\n");
      return (-1);
    }
  else if (argv[*i + 1] == 0 || !is_keyword(argv[*i + 1]))
    {
      my_puterr("Error: Missing name for redirect\n");
      return (-1);
    }
  *i += 1;
  *flag = 1;
  return (0);
}

static int		check(char **argv, int *i,
			      int *flags)
{
  if (!my_strcmp(argv[*i], "<<") || !my_strcmp(argv[*i], "<"))
    {
      if (check_redirection(argv, i, &(flags[IN])) == -1)
	return (-1);
    }
  else if (!my_strcmp(argv[*i], ">>") || !my_strcmp(argv[*i], ">"))
    {
      if (check_redirection(argv, i, &(flags[OUT])) == -1)
	return (-1);
    }
  else if (!my_strcmp(argv[*i], "|"))
    {
      if (check_pipe(argv, *i, flags) == -1)
	return (-1);
    }
  else
    flags[PROG] = 1;
  return (0);
}

/*
** flags[3]: IN, OUT, PROG
*/
int			is_valid_command(char **argv)
{
  int			i;
  int			flags[3];

  if (!my_strcmp(argv[0], "|"))
    {
      my_puterr("Error: Invalid null command\n");
      return (-1);
    }
  i = 0;
  my_memset(flags, 0, sizeof(int) * 3);
  while (argv[i])
    {
      if (check(argv, &i, (int *)&flags) == -1)
	return (-1);
      i += 1;
    }
  return (0);
}
