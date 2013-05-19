/*
** backspace_handles.c for 42sh in /home/catuss_a//Desktop/42sh/42sh
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Dec  8 15:40:43 2010 axel catusse
** Last update Tue Dec 14 21:47:02 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"

static void		leftshift_buffer(t_config *sh)
{
  int			buf_index;
  int			cpt;
  int			pos;
  char			*sve;
  int			i;

  pos = sh->cmdline.tmc.cursorpos - 1;
  buf_index = sh->cmdline.tmc.cursorpos - sh->cmdline.prompt.length - 1;
  cpt = buf_index;
  sve = my_strdup(sh->cmdline.buffer + buf_index);
  my_memset(sh->cmdline.buffer + buf_index - 1,
	    0, my_strlen(sh->cmdline.buffer + buf_index - 1));
  left_arrow_handle(sh);
  i = -1;
  while (sve[++i])
    add_char_in_buffer(sh, sve[i]);
  x_free(sve);
  my_putstr(sh->cmdline.tmc.dc);
  right_arrow_handle(sh);
  while (pos < sh->cmdline.tmc.cursorpos)
    left_arrow_handle(sh);
}

int			backspace_handle(t_config *sh, char *tmpbuf)
{
  if (!my_strcmp(sh->cmdline.tmc.kb, tmpbuf))
    {
      if (sh->cmdline.tmc.cursorpos > sh->cmdline.prompt.length + 1)
	leftshift_buffer(sh);
      return (SUCCESS);
    }
  return (FAIL);
}
