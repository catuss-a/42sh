/*
** left_and_right_arrows_handles.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Nov  4 21:37:25 2010 axel catusse
** Last update Thu Nov  4 23:48:11 2010 axel catusse
*/

#include "my.h"
#include "config.h"
#include "cmdline.h"

/*
** right arrow move the cursor on the right
** or bottom right if the cursor is at the end of the line
*/
void			right_arrow_handle(t_config *sh)
{
  if (sh->cmdline.tmc.cursorpos < sh->cmdline.prompt.length
      + my_strlen(sh->cmdline.buffer) + 1)
    {
      if (sh->cmdline.tmc.cursorpos % sh->cmdline.tmc.col != END_OF_LINE)
	my_putstr(sh->cmdline.tmc.nd);
      else
	my_putstr(sh->cmdline.tmc.down);
      sh->cmdline.tmc.cursorpos++;
    }
  return ;
}

/*
** left arrow move the cursor on the left
** or top left if the cursor is at the begining of the line
*/
void			left_arrow_handle(t_config *sh)
{
  int			i;

  if (sh->cmdline.tmc.cursorpos > sh->cmdline.prompt.length + 1)
    {
      if (sh->cmdline.tmc.cursorpos % sh->cmdline.tmc.col != BEGING_OF_LINE)
	my_putstr(sh->cmdline.tmc.le);
      else
	{
	  my_putstr(sh->cmdline.tmc.up);
	  i = 1;
	  while (i++ < sh->cmdline.tmc.col)
	    my_putstr(sh->cmdline.tmc.nd);
	}
      sh->cmdline.tmc.cursorpos--;
    }
  return ;
}
