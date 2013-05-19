/*
** memory.c for minishell2 in /home/serraj_y//c/minishell2/
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep 29 18:29:58 2010 younes serraj
** Last update Thu Sep 30 17:24:21 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "ll.h"
#include "memory.h"

int			mem_exists(t_ll_list *mem, char *name)
{
  t_ll_node		*w;
  t_var			*var;

  w = mem->head;
  while (w)
    {
      var = w->data;
      if (!my_strcmp(var->name, name))
	return (0);
      w = w->next;
    }
  return (-1);
}

void			mem_set(t_ll_list *mem,
				char *name, char *value)
{
  t_ll_node		*w;
  t_var			*var;

  w = mem->head;
  while (w)
    {
      var = w->data;
      if (!my_strcmp(var->name, name))
	{
	  x_free(var->value);
	  var->value = my_strdup(value);
	  return ;
	}
      w = w->next;
    }
  ll_push_data(mem, var_make(name, value), -1);
}

char			*mem_get(t_ll_list *mem, char *name)
{
  t_ll_node		*w;
  t_var			*var;

  w = mem->head;
  while (w)
    {
      var = w->data;
      if (!my_strcmp(var->name, name))
	return (var->value);
      w = w->next;
    }
  return (0);
}

void			mem_del(t_ll_list *mem, char *name)
{
  t_ll_node		*w;
  t_var			*var;
  int			i;

  i = 1;
  w = mem->head;
  while (w)
    {
      var = w->data;
      if (!my_strcmp(var->name, name))
	{
	  ll_delete_node(mem, i, (void (*)(void *))var_free);
	  return ;
	}
      i += 1;
      w = w->next;
    }
}

int			mem_import_environ(t_ll_list *mem)
{
  extern char		**environ;
  int			i;

  i = 0;
  while (environ[i])
    {
      ll_push_data(mem, var_make_from_environ(environ[i]), -1);
      i += 1;
    }
  return (0);
}
