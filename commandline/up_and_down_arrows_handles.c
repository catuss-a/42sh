/*
** up_and_down_arrows_handles.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Nov  5 18:24:26 2010 axel catusse
** Last update Fri Dec 17 15:18:03 2010 younes serraj
*/

#include "my.h"
#include "config.h"
#include "cmdline.h"

static void		clean_line_from_end_buffer(t_config *sh)
{
  int			i;

  while (sh->cmdline.tmc.cursorpos > sh->cmdline.prompt.length + 1)
    left_arrow_handle(sh);
  i = sh->cmdline.tmc.cursorpos - sh->cmdline.prompt.length - 1;
  while (i < BUFF_SIZE
	 && sh->cmdline.buffer[i] != '\0')
    {
      my_putchar(' ');
      ++i;
      sh->cmdline.tmc.cursorpos += 1;
    }
  while (sh->cmdline.tmc.cursorpos > sh->cmdline.prompt.length + 1)
    left_arrow_handle(sh);
  return ;
}

void			up_arrow_handle(t_config *sh)
{
  int			i;

  if (sh->cmdline.history)
    {
      if (sh->cmdline.history->next &&
	  (sh->cmdline.history->prev || sh->cmdline.history_flag))
	sh->cmdline.history = sh->cmdline.history->next;
      else
	sh->cmdline.history_flag = 1;
      clean_line_from_end_buffer(sh);
      my_memset(sh->cmdline.buffer, 0, BUFF_SIZE);
      my_strcpy(sh->cmdline.buffer, sh->cmdline.history->data);
      i = 0;
      while (sh->cmdline.buffer[i])
	{
	  my_putchar(sh->cmdline.buffer[i++]);
	  sh->cmdline.tmc.cursorpos += 1;
	}
    }
  return ;
}

void			down_arrow_handle(t_config *sh)
{
  int			i;

  if (sh->cmdline.history)
    {
      clean_line_from_end_buffer(sh);
      my_memset(sh->cmdline.buffer, 0, BUFF_SIZE);
      if (sh->cmdline.history->prev)
	{
	  sh->cmdline.history = sh->cmdline.history->prev;
	  my_strcpy(sh->cmdline.buffer, sh->cmdline.history->data);
	  i = 0;
	  while (sh->cmdline.buffer[i])
	    {
	      my_putchar(sh->cmdline.buffer[i++]);
	      sh->cmdline.tmc.cursorpos += 1;
	    }
	}
      else
	sh->cmdline.history_flag = 0;
    }
  return ;
}
