/*
** add_char_in_buffer.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Nov  5 02:01:22 2010 axel catusse
** Last update Fri Dec 17 15:08:34 2010 younes serraj
*/

#include "my.h"
#include "config.h"
#include "cmdline.h"

void			add_char_in_buffer(t_config *sh, char new_c)
{
  int			buf_index;

  if (IS_PRINT(new_c) == 0)
    return ;
  if (sh->cmdline.prompt.length + my_strlen(sh->cmdline.buffer) >= BUFF_SIZE)
    return ;
  buf_index = sh->cmdline.tmc.cursorpos - sh->cmdline.prompt.length - 1;
  if (sh->cmdline.prompt.length + my_strlen(sh->cmdline.buffer) <
      sh->cmdline.tmc.cursorpos)
    {
      sh->cmdline.buffer[buf_index] = new_c;
      my_putchar(new_c);
      if (sh->cmdline.tmc.cursorpos % sh->cmdline.tmc.col == 0)
	my_putstr(sh->cmdline.tmc.down);
    }
  else
    {
      add_char_and_rightshift_buffer(sh, new_c, buf_index);
      putstr_insersion(sh);
    }
  sh->cmdline.tmc.cursorpos++;
  return ;
}
