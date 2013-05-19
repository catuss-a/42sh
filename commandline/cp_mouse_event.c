/*
** mouth_event.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Nov  5 01:58:47 2010 axel catusse
** Last update Fri Nov  5 02:03:46 2010 axel catusse
*/

#include "config.h"
#include "cmdline.h"

void			cp_mouse_event(t_config *sh, char *tmpbuf)
{
  int			i;

  i = -1;
  while (++i < 10 && tmpbuf[i] != '\0')
    add_char_in_buffer(sh, tmpbuf[i]);
  return ;
}
