/*
** unsetenv.c for minishell2 in /home/serraj_y//c/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 19:15:52 2010 younes serraj
** Last update Fri Dec 17 15:16:09 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "builtins.h"
#include "memory.h"

static void		_do_unset(t_ll_list *list, char *var_name)
{
  t_ll_node		*w;
  int			i;
  t_var			*var;

  w = list->head;
  i = 0;
  while (i < list->count)
    {
      var = w->data;
      if (!my_strcmp(var_name, var->name))
	{
	  ll_delete_node(list, i + 1,
			 (void (*)(void *))var_free);
	  return ;
	}
      w = w->next;
      i += 1;
    }
}

/*
** if name not found, do nothing && return (0) (man unsetenv)
*/
int			builtins_unset(int argc, char **argv,
				       t_config *conf, int *ret)
{
  *ret = 0;
  if (argc != 2)
    {
      my_puterr("Usage: unset [name]\n");
      return (-1);
    }
  if (!my_strcmp(argv[1], "*"))
    {
      ll_clear_list(&(conf->variables), free);
      return (0);
    }
  _do_unset(&(conf->variables), argv[1]);
  return (MYSH_SIGNAL_NOPE);
}
