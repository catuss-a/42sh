/*
** home_handle.c for 42sh in /home/catuss_a//Desktop/42sh/42sh
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Dec 16 14:32:48 2010 axel catusse
** Last update Thu Dec 16 14:33:53 2010 axel catusse
*/

#include "config.h"

int			home_handle(t_config *sh, char *tmpbuf)
{
  if ((tmpbuf[0] == 27
       && tmpbuf[1] == 91
       && tmpbuf[2] == 72
       && tmpbuf[3] == 0)
      || (tmpbuf[0] == 1 && tmpbuf[1] == 0))
    {
      while (sh->cmdline.tmc.cursorpos > sh->cmdline.prompt.length + 1)
	left_arrow_handle(sh);
      return (SUCCESS);
    }
  return (FAIL);
}
