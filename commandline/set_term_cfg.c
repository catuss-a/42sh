/*
** set_term_cfg.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov  2 18:24:37 2010 axel catusse
** Last update Wed Dec  8 13:25:35 2010 younes serraj
*/

#include <sys/ioctl.h>
#include "my.h"
#include "config.h"
#include "termcap.h"

void			set_term_ref_cfg(t_config *sh)
{
  if (ioctl(0, TIOCSETA, &sh->cmdline.tmc.ref_cfg) < 0)
    {
      my_printf_err("error: ioctl: cannot set termios struct.\n");
      sh->cmdline.tmc.button = OFF;
    }
}

void			set_term_cfg(t_config *sh)
{
  sh->cmdline.tmc.cur_cfg.c_lflag &= ~(ICANON | ECHO);
  sh->cmdline.tmc.cur_cfg.c_cc[VMIN] = 1;
  sh->cmdline.tmc.cur_cfg.c_cc[VTIME] = 0;
  if (ioctl(0, TIOCSETA, &sh->cmdline.tmc.cur_cfg) < 0)
    {
      my_printf_err("error: ioctl: cannot set termios struct.\n");
      sh->cmdline.tmc.button = OFF;
    }
}
