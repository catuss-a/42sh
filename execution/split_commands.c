/*
** split_commads.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep 22 19:15:12 2010 younes serraj
** Last update Sun Dec 19 20:08:30 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"
#include "shell.h"

char			*build_str_from_wt(char **wt, int from, int to)
{
  char			*buffer;
  int			i;
  int			buff_size;

  if (from == to)
    return (my_strdup(wt[from]));
  buff_size = 0;
  i = from;
  while (i <= to)
    {
      buff_size += my_strlen(wt[i]) + 1;
      i += 1;
    }
  buffer = x_malloc(sizeof(char) * buff_size);
  *buffer = 0;
  i = from;
  while (i <= to)
    {
      my_strcat(buffer, wt[i]);
      if (i < to)
	my_strcat(buffer, " ");
      i += 1;
    }
  return (buffer);
}

static void		write_commands_in_list(char **wt,
					       t_ll_list *list,
					       char *sep,
					       int strict)
{
  int			i;
  int			from;

  from = 0;
  i = 0;
  while (wt[i])
    {
      if (!my_strcmp(wt[i], sep))
	{
	  if (from < i)
	    ll_push_data(list,
			 build_str_from_wt(wt, from, i - 1),
			 -1);
	  else if (strict == 1)
	    ll_push_data(list, my_strdup(""), -1);
	  from = i + 1;
	}
      i += 1;
    }
  if (from < i)
    ll_push_data(list, build_str_from_wt(wt, from, i - 1), -1);
}

/*
** strict values :
** 0 : do NOT copy empty strings in the list (;)
** 1 : copy all strings in the list (&& ||)
*/
void			split_commands(t_ll_list *list, char *line,
				       char *sep, int strict)
{
  char			**wt;

  wt = my_make_argv(line, 0);
  write_commands_in_list(wt, list, sep, strict);
  my_wt_free(wt);
  x_free(wt);
}
