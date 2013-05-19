/*
** read_cmdline.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 18:38:57 2010 younes serraj
** Last update Sun Dec 19 23:00:54 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"
#include "shell.h"

static int		_simple_cmdline(t_config *sh)
{
  int			len;

  if ((len = read(0, sh->cmdline.buffer, BUFF_SIZE)) < 1)
    {
      if (len == -1)
	my_printf_err("Error: read() failed\n", len);
      return (MYSH_SIGNAL_EXIT);
    }
  sh->cmdline.buffer[len - 1] = '\0';
  return (MYSH_SIGNAL_NOPE);
}

int			read_cmdline(t_config *sh)
{
  my_memset(sh->cmdline.buffer, 0, BUFF_SIZE);
  if (sh->cmdline.tmc.button == ON)
    {
      set_term_cfg(sh);
      if (cmdline_editor(sh) == MYSH_SIGNAL_EXIT)
	return (MYSH_SIGNAL_EXIT);
      set_term_ref_cfg(sh);
    }
  else
    {
      if (_simple_cmdline(sh) == MYSH_SIGNAL_EXIT)
	return (MYSH_SIGNAL_EXIT);
    }
  return (MYSH_SIGNAL_NOPE);
}
