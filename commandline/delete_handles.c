/*
** delete_handle.c for 42sh in /home/catuss_a//Desktop/42sh/42sh
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Dec  8 20:15:34 2010 axel catusse
** Last update Mon Dec 13 19:42:03 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"

static void		delete_char_on_cursor(t_config *sh)
{
  int			buf_index;
  int			cpt;
  int			pos;
  char			*sve;
  int			i;

  pos = sh->cmdline.tmc.cursorpos;
  buf_index = sh->cmdline.tmc.cursorpos - sh->cmdline.prompt.length - 1;
  cpt = buf_index;
  sve = my_strdup(sh->cmdline.buffer + buf_index + 1);
  my_memset(sh->cmdline.buffer + buf_index,
	    0, my_strlen(sh->cmdline.buffer + buf_index));
  i = -1;
  while (sve[++i])
    add_char_in_buffer(sh, sve[i]);
  x_free(sve);
  my_putstr(sh->cmdline.tmc.dc);
  right_arrow_handle(sh);
  while (pos < sh->cmdline.tmc.cursorpos)
    left_arrow_handle(sh);
}

int			delete_handle(t_config *sh, char *tmpbuf)
{
  if (!my_strcmp(sh->cmdline.tmc.del, tmpbuf))
    {
      if (my_strlen(sh->cmdline.buffer
		    + (sh->cmdline.tmc.cursorpos
		       - sh->cmdline.prompt.length - 1)))
	delete_char_on_cursor(sh);
      return (SUCCESS);
    }
  return (FAIL);
}
