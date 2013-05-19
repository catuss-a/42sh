/*
** signals.c for minishell2 in /home/serraj_y//c/minishell2/system
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Oct  3 16:53:30 2010 younes serraj
** Last update Fri Dec 17 17:25:55 2010 younes serraj
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/signal.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "system.h"

/*
** SIG_DFL	: supprime le callback sur ce signal
** SIG_IGN	: ignore ce signal
**
** SIGINT	: Ctrl + C
** SIGTSTP	: Ctrl + Z
*/
void			signal_handler(int sig)
{
  t_config		*conf;
  int			pos;

  conf = get_config();
  if (sig == SIGINT)
    my_memset(conf->cmdline.buffer, 0, BUFF_SIZE);
  else if (sig == SIGWINCH)
    {
      _get_window_sizes(conf);
      conf->cmdline.resize = 0;
      pos = conf->cmdline.tmc.cursorpos;
      my_putstr(conf->cmdline.tmc.cl);
      display_prompt(conf);
      conf->cmdline.tmc.cursorpos += my_putstr(conf->cmdline.buffer);
      while (pos < conf->cmdline.tmc.cursorpos)
	left_arrow_handle(conf);
    }
  signal_init();
}

void			signal_display(int sig)
{
  if (sig == -1)
    my_puterr("Error: execve() failed\n");
  else if (sig == SIGILL)
    my_puterr("Error: Illegal Instruction\n");
  else if (sig == SIGFPE)
    my_puterr("Error: Floating point exception\n");
  else if (sig == SIGSEGV)
    my_puterr("Error: Invalid memory reference (segmentation fault)\n");
  else if (sig == SIGPIPE)
    my_puterr("Error: Broken pipe\n");
  signal_init();
}

void			signal_init()
{
  signal(SIGINT, signal_handler);
  signal(SIGTSTP, signal_handler);
  signal(SIGWINCH, signal_handler);
}
