/*
** init_cmdline.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov  2 15:58:38 2010 axel catusse
** Last update Tue Dec 14 23:00:39 2010 younes serraj
*/

#include "my.h"
#include "config.h"
#include "init.h"

static void		_init_prompt(t_config *sh)
{
  sh->cmdline.prompt.str = my_strdup("<< 42sh >> ");
  sh->cmdline.prompt.length = my_strlen(sh->cmdline.prompt.str);
  sh->cmdline.prompt.color = my_strdup(GREEN);
}

int			init_cmdline(t_config *sh)
{
  _init_prompt(sh);
  if (check_fd_read(0) == -1)
    init_termcap(sh);
  init_history(sh);
  return (SUCCESS);
}
