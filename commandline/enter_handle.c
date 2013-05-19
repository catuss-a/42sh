/*
** enter_handle.c for 42sh in /home/catuss_a//Desktop/42sh/42sh
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Dec 16 14:24:56 2010 axel catusse
** Last update Thu Dec 16 14:30:28 2010 axel catusse
*/

#include "my.h"
#include "config.h"
#include "init.h"

int			enter_handle(t_config *sh, char *tmpbuf)
{
  if (!my_strcmp(KEY_ENTER, tmpbuf))
    {
      while (sh->cmdline.history && sh->cmdline.history->prev)
	sh->cmdline.history = sh->cmdline.history->prev;
      sh->cmdline.history_flag = 0;
      if (my_strlen(sh->cmdline.buffer))
	{
	  delete_elem_in_history(sh);
	  add_elem_to_history(sh, sh->cmdline.buffer);
	}
      return (SUCCESS);
    }
  return (FAIL);
}
