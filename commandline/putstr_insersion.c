/*
** putstr_insertion.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Nov  4 19:29:16 2010 axel catusse
** Last update Wed Dec  8 20:57:18 2010 axel catusse
*/

#include "my.h"
#include "config.h"

void			putstr_since_index(t_config *sh, int *j,
					   int *tmp, int *cpt)
{
  *tmp = sh->cmdline.tmc.cursorpos;
  *j = sh->cmdline.tmc.cursorpos - sh->cmdline.prompt.length - 1;
  *cpt = 0;
  while (sh->cmdline.buffer[*j] != '\0')
    {
      my_putchar(sh->cmdline.buffer[*j]);
      if ((*tmp) % sh->cmdline.tmc.col == 0)
	{
	  ++(*cpt);
	  my_putstr(sh->cmdline.tmc.down);
	}
      ++(*tmp);
      ++(*j);
    }
  return ;
}

static void		up_cursor_special_inst(t_config *sh)
{
  int			j;
  int			i;
  int			flag;

  flag = 0;
  i = sh->cmdline.tmc.cursorpos - sh->cmdline.prompt.length - 1;
  j = my_strlen(sh->cmdline.buffer + i);
  if (j < sh->cmdline.tmc.col)
    return ;
  if (j % sh->cmdline.tmc.col == 0)
    flag = 1;
  j /= sh->cmdline.tmc.col;
  if (flag)
    j--;
  while (j-- > 0)
    my_putstr(sh->cmdline.tmc.up);
  return ;
}

void			putstr_insersion(t_config *sh)
{
  int			j;
  int			tmp;
  int			cpt;

  putstr_since_index(sh, &j, &tmp, &cpt);
  j = tmp % sh->cmdline.tmc.col;
  if (j == 0)
    j = sh->cmdline.tmc.col;
  while (j-- > 1)
    my_putstr(sh->cmdline.tmc.le);
  if (sh->cmdline.tmc.cursorpos % sh->cmdline.tmc.col != 0)
    {
      while (cpt-- > 0)
	my_putstr(sh->cmdline.tmc.up);
      while (j++ < sh->cmdline.tmc.cursorpos % sh->cmdline.tmc.col)
	my_putstr(sh->cmdline.tmc.nd);
    }
  else
    up_cursor_special_inst(sh);
  return ;
}

void			putstr_insersion2(t_config *sh)
{
  int			j;
  int			tmp;
  int			cpt;

  putstr_since_index(sh, &j, &tmp, &cpt);
  j = tmp % sh->cmdline.tmc.col;
  if (j == 0)
    j = sh->cmdline.tmc.col;
  while (j-- > 1)
    my_putstr(sh->cmdline.tmc.le);
  if (sh->cmdline.tmc.cursorpos % sh->cmdline.tmc.col != 0)
    {
      while (cpt-- > 0)
	my_putstr(sh->cmdline.tmc.up);
      while (j++ < sh->cmdline.tmc.cursorpos % sh->cmdline.tmc.col)
	my_putstr(sh->cmdline.tmc.nd);
    }
  else
    up_cursor_special_inst(sh);
  return ;
}
