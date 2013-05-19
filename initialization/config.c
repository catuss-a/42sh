/*
** config.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/struct/initialization
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 18:55:47 2010 younes serraj
** Last update Fri Dec 17 23:06:52 2010 stephane delmas
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"
#include "init.h"

t_config		*get_config()
{
  static t_config	conf;

  return (&conf);
}

void			init_config(t_config *conf)
{
  my_memset(conf, 0, sizeof(t_config));
  ll_init_list(&(conf->env));
  ll_init_list(&(conf->variables));
  load_env(&(conf->env));
  init_user(&(conf->user));
  init_cmdline(conf);
  conf->head_job = NULL;
  conf->current_job = NULL;
  conf->shell_pgid = 0;
  conf->previous_dir = getcwd(NULL, 0);
}

void			free_cmdline(t_cmdline *cmdline)
{
  t_history		*t;

  x_free(cmdline->prompt.str);
  x_free(cmdline->prompt.color);
  while (cmdline->history)
    {
      t = cmdline->history;
      cmdline->history = cmdline->history->next;
      x_free(t->data);
      x_free(t);
    }
}

void			free_config(t_config *conf)
{
  ll_clear_list(&(conf->env), free);
  ll_clear_list(&(conf->variables), free);
  free_user(&(conf->user));
  free_cmdline(&conf->cmdline);
  x_free(conf->previous_dir);
}
