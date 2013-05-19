/*
** keyboard_handles.c for 42hs in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Nov  4 21:08:24 2010 axel catusse
** Last update Fri Dec 17 15:17:42 2010 younes serraj
*/

#include <stdlib.h>
#include <term.h>
#include "my.h"
#include "config.h"
#include "init.h"

int			keyboard_handles(t_config *sh, char *tmpbuf)
{
  if (home_handle(sh, tmpbuf) == SUCCESS ||
      end_handle(sh, tmpbuf) == SUCCESS ||
      arrows_handles(sh, tmpbuf) == SUCCESS)
    return (SUCCESS);
  return (FAIL);
}
