/*
** clear_screen_handle.c for 42sh in /home/catuss_a//Desktop/42sh/42sh
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Dec 16 14:28:52 2010 axel catusse
** Last update Thu Dec 16 14:29:58 2010 axel catusse
*/

#include "my.h"
#include "config.h"

int			clear_screen_handle(t_config *sh, char *tmpbuf)
{
  if (tmpbuf[0] == 12 && tmpbuf[1] == 0)
    {
      my_putstr(sh->cmdline.tmc.cl);
      display_prompt(sh);
      my_putstr(sh->cmdline.buffer);
      sh->cmdline.tmc.cursorpos += my_strlen(sh->cmdline.buffer);
      return (SUCCESS);
    }
  return (FAIL);
}
