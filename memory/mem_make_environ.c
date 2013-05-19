/*
** mem_make_environ.c for minishell2 in /home/serraj_y//c/minishell2/memory
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep 29 20:42:37 2010 younes serraj
** Last update Mon Dec  6 19:39:46 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "ll.h"
#include "memory.h"

static char		*make_env_entry(t_ll_node *w)
{
  t_var			*var;
  char			*buffer;

  var = w->data;
  buffer = x_malloc(sizeof(char) *
		    (my_strlen(var->name) + my_strlen(var->value) + 2));
  my_strcpy(buffer, var->name);
  my_strcat(buffer, "=");
  my_strcat(buffer, var->value);
  return (buffer);
}

char			**mem_make_environ(t_ll_list *env)
{
  char			**wt;
  int			i;
  t_ll_node		*w;

  wt = x_malloc(sizeof(char *) * (env->count + 1));
  i = 0;
  w = env->head;
  while (i < env->count)
    {
      wt[i] = make_env_entry(w);
      w = w->next;
      i += 1;
    }
  wt[i] = 0;
  return (wt);
}
