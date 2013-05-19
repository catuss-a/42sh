/*
** delete_elem_in_history.c for 42sh in /home/catuss_a//Desktop/42sh/42sh
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Dec 16 14:30:54 2010 axel catusse
** Last update Thu Dec 16 14:32:39 2010 axel catusse
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"

void			delete_elem_in_history(t_config *sh)
{
  t_history		*tmp;

  tmp = sh->cmdline.history;
  while (tmp)
    {
      if (!my_strcmp(sh->cmdline.buffer, tmp->data))
	{
	  if (tmp == sh->cmdline.history)
	    sh->cmdline.history = tmp->next;
	  if (tmp->next)
	    tmp->next->prev = tmp->prev;
	  if (tmp->prev)
	    tmp->prev->next = tmp->next;
	  free(tmp);
	  return ;
	}
      tmp = tmp->next;
    }
  return ;
}
