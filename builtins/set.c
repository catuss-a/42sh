/*
** setenv.c for minishell2 in /home/serraj_y//c/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 19:15:52 2010 younes serraj
** Last update Tue Dec 14 23:27:10 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "builtins.h"
#include "memory.h"

static void		variable_entry_update(t_ll_list *list,
					      char *name, char *new_value)
{
  int			i;
  t_ll_node		*w;
  t_var			*var;

  w = list->head;
  i = 0;
  while (i < list->count)
    {
      var = w->data;
      if (!my_strcmp(var->name, name))
	{
	  free(var->value);
	  var->value = my_strdup(new_value);
	  return ;
	}
      w = w->next;
      i += 1;
    }
}

int			builtins_set(int argc, char **argv,
				     t_config *conf, int *ret)
{
  int			overwrite;

  if (argc < 3)
    {
      my_puterr("Usage: set [name] [value] ([overwrite])\n");
      *ret = -1;
      return (MYSH_SIGNAL_NOPE);
    }
  overwrite = (argc == 4) ? atoi(argv[3]) : 1;
  if (!mem_exists(&(conf->variables), argv[1]))
    {
      if (overwrite == 0)
	{
	  my_printf_err("Variable '%s' already exists.\n", argv[1]);
	  my_puterr("Overwrite explicitely forbidden\n");
	  *ret = -1;
	  return (MYSH_SIGNAL_NOPE);
	}
      variable_entry_update(&(conf->variables), argv[1], argv[2]);
    }
  else
    ll_push_data(&(conf->variables), var_make(argv[1], argv[2]), -1);
  *ret = 0;
  return (MYSH_SIGNAL_NOPE);
}
