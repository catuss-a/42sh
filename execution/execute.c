/*
** execute.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep 29 18:26:29 2010 younes serraj
** Last update Sun Dec 19 22:37:31 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "ll.h"
#include "config.h"
#include "shell.h"

static void		set_flag_is_job(t_ll_list *list, char *line)
{
  char			**wt;

  my_trim(line, SEPARATORS);
  if ((wt = my_make_argv(line, 0)) == NULL)
    {
      my_puterr("Error: my_make_argv() failed\n");
      return ;
    }
  if (my_wt_count(wt) > 0 && !my_strcmp(wt[my_wt_count(wt) - 1], "&"))
    {
      list->is_job = 1;
      line[my_strlen(line) - 1] = 0;
    }
  my_wt_free(wt);
  x_free(wt);
  my_trim(line, SEPARATORS);
}

static int		_is_valid_cmdline(char *line)
{
  char			**wt;
  int			ret;

  ret = 0;
  wt = my_make_argv(line, 0);
  if (!wt || is_valid_command(wt) == -1)
    ret = -1;
  my_wt_free(wt);
  x_free(wt);
  return (ret);
}

int			execute(char **argv,
				t_config *conf, int *ret)
{
  t_ll_list		subcommands;
  char			*line;
  int			i;

  *ret = -1;
  if (is_valid_command(argv) == -1)
    return (MYSH_SIGNAL_NOPE);
  line = my_join(argv, " ");
  ll_init_list(&subcommands);
  set_flag_is_job(&subcommands, line);
  if ((i = my_strlen(line)) == 0 || _is_valid_cmdline(line) == -1)
    {
      if (i == 0)
	my_puterr("Invalid null command\n");
      return (MYSH_SIGNAL_NOPE);
    }
  split_commands(&subcommands, line, "|", 1);
  x_free(line);
  if (subcommands.count > 0 && subcommands.head)
    i = execute_subcommands(&subcommands, conf, ret);
  else
    i = MYSH_SIGNAL_NOPE;
  ll_clear_list(&subcommands, free);
  return (i);
}
