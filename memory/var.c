/*
** var.c for minishell2 in /home/serraj_y//c/minishell2/main
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Sep 21 20:47:15 2010 younes serraj
** Last update Fri Dec  3 19:31:02 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"
#include "memory.h"

t_var			*var_make(char *name, char *value)
{
  t_var			*var;

  var = x_malloc(sizeof(t_var));
  var->name = my_strdup(name);
  var->value = my_strdup(value);
  return (var);
}

void			var_free(t_var *var)
{
  if (!var)
    return ;
  if (var->name)
    x_free(var->name);
  if (var->value)
    x_free(var->value);
  free(var);
}

t_var			*var_make_from_environ(char *env_entry)
{
  int			i;
  char			*name;
  char			*value;
  t_var			*var;

  if ((i = my_findchar('=', env_entry)) == -1)
    {
      name = my_strdup(env_entry);
      value = my_strdup("");
    }
  else
    {
      name = my_strndup(env_entry, i);
      value = my_strdup(env_entry + i + 1);
    }
  var = var_make(name, value);
  x_free(name);
  x_free(value);
  return (var);
}
