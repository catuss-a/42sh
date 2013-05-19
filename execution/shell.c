/*
** shell.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 18:33:02 2010 younes serraj
** Last update Sun Dec 19 22:59:46 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"
#include "system.h"
#include "shell.h"
#include "config.h"

int			my_exec(t_config *conf, char *line, int *ret)
{
  t_ll_list		commands;
  int			sig;
  t_ll_node		*w;

  ll_init_list(&commands);
  sig = MYSH_SIGNAL_NOPE;
  split_commands(&commands, line, ";", 0);
  w = commands.head;
  while (w)
    {
      if (*((char *)w->data) &&
	  (sig = manage_conditions(w->data, conf, ret)) == MYSH_SIGNAL_EXIT)
	break;
      w = w->next;
    }
  ll_clear_list(&commands, free);
  return (sig);
}

int			shell(t_config *conf)
{
  int			ret;
  char			*cmd;

  ret = EXIT_SUCCESS;
  while (1)
    {
      check_status(conf);
      if (check_fd_read(0) == -1)
	display_prompt(conf);
      if (read_cmdline(conf) == MYSH_SIGNAL_EXIT)
	{
	  ret = EXIT_SUCCESS;
	  break;
	}
      if ((cmd = commandline_rewrite(conf->cmdline.buffer)) == NULL)
	continue ;
      if (my_exec(conf,
		  cmd, &ret) == MYSH_SIGNAL_EXIT)
	break;
    }
  my_putchar('\n');
  return (ret);
}
