/*
** x_tgoto.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Jul  2 18:14:50 2010 younes serraj
** Last update Fri Jul  2 18:19:55 2010 younes serraj
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include "my.h"
#include "tc.h"

int			x_tgoto(int col, int row)
{
  static char		area[TC_BUFFER_SIZE];
  char			*ptr;
  char			*buff;

  ptr = area;
  if (!(*area))
    ptr = x_tgetstr("cm", &ptr);
  if (!ptr)
    return (-1);
  if (!(buff = tgoto(ptr, col, row)))
    return (-1);
  my_puterr(buff);
  return (0);
}
