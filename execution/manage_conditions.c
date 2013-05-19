/*
** manage_conditions.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Nov 23 13:17:30 2010 younes serraj
** Last update Sun Dec 19 22:19:34 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"
#include "shell.h"

static int		check_invalid_null_command(t_ll_list *list,
						   char *line, char *sep)
{
  t_ll_node		*w;
  char			**wt;

  w = list->head;
  while (w)
    {
      if (my_strlen(w->data) == 0)
	{
	  my_puterr("Invalid null command\n");
	  return (-1);
	}
      w = w->next;
    }
  wt = my_split(line, " \t");
  if (list->count == 0 || !my_strcmp(wt[0], sep) ||
      !my_strcmp(wt[my_wt_count(wt) - 1], sep))
    {
      my_wt_free(wt);
      x_free(wt);
      my_puterr("Invalid null command\n");
      return (-1);
    }
  my_wt_free(wt);
  x_free(wt);
  return (0);
}

static int		manage_conditions_and(char *line,
					      t_config *conf, int *ret)
{
  t_ll_list		conditions;
  t_ll_node		*w;

  ll_init_list(&conditions);
  split_commands(&conditions, line, "&&", 1);
  if (check_invalid_null_command(&conditions, line, "&&") == -1)
    {
      ll_clear_list(&conditions, free);
      *ret = -1;
      return (MYSH_SIGNAL_NOPE);
    }
  w = conditions.head;
  while (w)
    {
      if (query_out(w->data, conf, ret) == MYSH_SIGNAL_EXIT)
	{
	  ll_clear_list(&conditions, free);
	  return (MYSH_SIGNAL_EXIT);
	}
      else if (*ret != 0)
	break;
      w = w->next;
    }
  ll_clear_list(&conditions, free);
  return (MYSH_SIGNAL_NOPE);
}

static int		manage_conditions_or(char *line,
					     t_config *conf, int *ret)
{
  t_ll_list		conditions;
  t_ll_node		*w;

  ll_init_list(&conditions);
  split_commands(&conditions, line, "||", 1);
  if (check_invalid_null_command(&conditions, line, "||") == -1)
    {
      ll_clear_list(&conditions, free);
      *ret = -1;
      return (MYSH_SIGNAL_NOPE);
    }
  w = conditions.head;
  while (w)
    {
      if (manage_conditions_and(w->data, conf, ret) == MYSH_SIGNAL_EXIT)
	{
	  ll_clear_list(&conditions, free);
	  return (MYSH_SIGNAL_EXIT);
	}
      if (*ret == 0)
	break;
      w = w->next;
    }
  ll_clear_list(&conditions, free);
  return (MYSH_SIGNAL_NOPE);
}

int			manage_conditions(char *line,
					  t_config *conf, int *ret)
{
  return (manage_conditions_or(line, conf, ret));
}
