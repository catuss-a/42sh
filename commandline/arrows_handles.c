/*
** arrows_handles.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Nov  4 21:25:42 2010 axel catusse
** Last update Fri Nov  5 18:23:52 2010 axel catusse
*/

#include "my.h"
#include "config.h"
#include "cmdline.h"

int			arrows_handles(t_config *sh, char *tmpbuf)
{
  if (!my_strcmp(sh->cmdline.tmc.kl, tmpbuf))
    {
      left_arrow_handle(sh);
      return (SUCCESS);
    }
  else if (!my_strcmp(sh->cmdline.tmc.kr, tmpbuf))
    {
      right_arrow_handle(sh);
      return (SUCCESS);
    }
  else if (!my_strcmp(sh->cmdline.tmc.ku, tmpbuf))
    {
      up_arrow_handle(sh);
      return (SUCCESS);
    }
  else if (!my_strcmp(sh->cmdline.tmc.kd, tmpbuf))
    {
      down_arrow_handle(sh);
      return (SUCCESS);
    }
  return (FAIL);
}
