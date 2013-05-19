/*
** end_handle.c for 42sh in /home/catuss_a//Desktop/42sh/42sh
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Dec 16 14:34:05 2010 axel catusse
** Last update Thu Dec 16 14:34:53 2010 axel catusse
*/

#include "my.h"
#include "config.h"

int			end_handle(t_config *sh, char *tmpbuf)
{
  if ((tmpbuf[0] == 27
       && tmpbuf[1] == 91
       && tmpbuf[2] == 70
       && tmpbuf[3] == 0)
      || !my_strcmp(tmpbuf, "\05"))
    {
      while (sh->cmdline.tmc.cursorpos < sh->cmdline.prompt.length
	     + my_strlen(sh->cmdline.buffer) + 1)
	right_arrow_handle(sh);
      return (SUCCESS);
    }
  return (FAIL);
}
