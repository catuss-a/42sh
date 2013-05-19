/*
** display_prompt.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov  2 18:38:56 2010 axel catusse
** Last update Tue Dec  7 19:17:42 2010 younes serraj
*/

#include "my.h"
#include "config.h"
#include "color.h"

void			display_prompt(t_config *sh)
{
  my_putstr(sh->cmdline.prompt.color);
  my_putstr(sh->cmdline.prompt.str);
  my_putstr(END_COLOR);
  if (sh->cmdline.tmc.button == ON)
    sh->cmdline.tmc.cursorpos = sh->cmdline.prompt.length + 1;
  return ;
}
