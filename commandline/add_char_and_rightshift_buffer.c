/*
** add_char_and_rightshift_buffer.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Nov  4 19:26:55 2010 axel catusse
** Last update Thu Nov  4 23:47:45 2010 axel catusse
*/

#include "my.h"
#include "config.h"

void			add_char_and_rightshift_buffer(t_config *sh,
						       char new_c,
						       int buf_index)
{
  int			j;

  j = my_strlen(sh->cmdline.buffer) + 1;
  while (--j > buf_index)
    sh->cmdline.buffer[j] = sh->cmdline.buffer[j - 1];
  sh->cmdline.buffer[buf_index] = new_c;
  return ;
}
