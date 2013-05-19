/*
** init_termcap.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov  2 16:14:30 2010 axel catusse
** Last update Fri Dec 17 17:40:53 2010 younes serraj
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include <term.h>
#include "my.h"
#include "tc.h"
#include "config.h"
#include "termcap.h"

int	 		_get_window_sizes(t_config *sh)
{
  struct winsize	size;

  if (ioctl(0, TIOCGWINSZ, &size) < 0)
    {
      my_printf_err("Error: ioctl() failed\n");
      return (FAIL);
    }
  sh->cmdline.tmc.col = size.ws_col;
  sh->cmdline.tmc.li = size.ws_row;
  return (SUCCESS);
}

static int 		_get_capabilities(t_config *shell, char *term)
{
  char			bp[1024];
  char			area[2048];

  my_memset(area, 0, 2048);
  if (!my_strcmp(term, "xterm"))
    term = XTERM_NOAPP;
  if (tgetent(bp, term) != 1)
    {
      my_printf_err("Error: tgetent: cannot determine terminal.\n");
      return (FAIL);
    }
  shell->cmdline.tmc.cl = x_tgetstr("cl", (char **)&area);
  shell->cmdline.tmc.ch = x_tgetstr("ch", (char **)&area);
  shell->cmdline.tmc.kr = x_tgetstr("kr", (char **)&area);
  shell->cmdline.tmc.kl = x_tgetstr("kl", (char **)&area);
  shell->cmdline.tmc.kd = x_tgetstr("kd", (char **)&area);
  shell->cmdline.tmc.ku = x_tgetstr("ku", (char **)&area);
  shell->cmdline.tmc.le = x_tgetstr("le", (char **)&area);
  shell->cmdline.tmc.nd = x_tgetstr("nd", (char **)&area);
  shell->cmdline.tmc.kb = x_tgetstr("kb", (char **)&area);
  shell->cmdline.tmc.up = x_tgetstr("up", (char **)&area);
  shell->cmdline.tmc.dc = x_tgetstr("dc", (char **)&area);
  shell->cmdline.tmc.del = x_tgetstr("kD", (char **)&area);
  shell->cmdline.tmc.down = x_tgetstr("do", (char **)&area);
  return (SUCCESS);
}

static int		_get_termios_struct(t_config *sh)
{
  if (ioctl(0, TIOCGETA, &sh->cmdline.tmc.ref_cfg) < 0)
    {
      my_printf_err("error: ioctl: cannot get termios struct.\n");
      return (FAIL);
    }
  my_memcpy(&sh->cmdline.tmc.cur_cfg,
	    &sh->cmdline.tmc.ref_cfg,
	    sizeof(sh->cmdline.tmc.ref_cfg));
  return (SUCCESS);
}

void			init_termcap(t_config *sh)
{
  char			*term;

  if ((term = getenv("TERM")) == NULL)
    {
      my_printf_err("error: getenv: cannot determine terminal.\n");
      return ;
    }
  if (_get_window_sizes(sh) == FAIL ||
      _get_capabilities(sh, term) == FAIL ||
      _get_termios_struct(sh) == FAIL)
    return ;
  sh->cmdline.tmc.button = ON;
}
