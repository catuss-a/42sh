/*
** cmdline_editor.c for 42sh in /home/catuss_a//Desktop/42sh/srcs/cmdline
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov  2 00:27:20 2010 axel catusse
** Last update Sun Dec 19 23:09:56 2010 younes serraj
*/

#include <unistd.h>
#include <term.h>
#include "my.h"
#include "config.h"
#include "shell.h"

static void		move_cursor_to_end_to_exec(t_config *sh)
{
  int			total_len;

  total_len = sh->cmdline.prompt.length + my_strlen(sh->cmdline.buffer) + 1;
  while (sh->cmdline.tmc.cursorpos < total_len)
    right_arrow_handle(sh);
  my_putstr(sh->cmdline.tmc.down);
  return ;
}

static int		noeffect_handles(t_config *sh, char *tmpbuf)
{
  if (backspace_handle(sh, tmpbuf) == SUCCESS
      || (delete_handle(sh, tmpbuf) == SUCCESS)
      || (clear_screen_handle(sh, tmpbuf) == SUCCESS))
    {
      my_memset(tmpbuf, 0, 10);
      return (SUCCESS);
    }
  return (FAIL);
}

void			special_keys(t_config *sh, char *tmpbuf, int len)
{
  if (len > 1)
    {
      if (keyboard_handles(sh, tmpbuf) == FAIL)
	cp_mouse_event(sh, tmpbuf);
    }
  my_memset(tmpbuf, 0, 10);
}

int			cmdline_editor(t_config *sh)
{
  char			tmpbuf[10];
  int			len;

  sh->cmdline.resize = 0;
  while (!sh->cmdline.resize)
    {
      sh->cmdline.resize = 1;
      my_memset(tmpbuf, 0, 10);
      while ((len = read(0, tmpbuf, 10)) > 0)
	{
	  if (tmpbuf[0] == 4 && !tmpbuf[1])
	    return (MYSH_SIGNAL_EXIT);
	  if (noeffect_handles(sh, tmpbuf) == SUCCESS)
	    continue;
	  if (len == 1)
	    {
	      if (enter_handle(sh, tmpbuf) == SUCCESS)
		break;
	      add_char_in_buffer(sh, tmpbuf[0]);
	    }
	  special_keys(sh, tmpbuf, len);
	}
    }
  move_cursor_to_end_to_exec(sh);
  return (MYSH_SIGNAL_NOPE);
}
