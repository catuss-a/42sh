/*
** tc_get_window_size.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Jul  2 19:02:41 2010 younes serraj
** Last update Wed Sep 22 23:24:08 2010 younes serraj
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include "my.h"
#include "tc.h"

int			tc_get_window_size(int *col, int *row)
{
  struct winsize	w;

  if (ioctl(0, TIOCGWINSZ, &w) < 0)
    {
      my_puterr("Error: ioctl(TIOCGWINSZ) failed\n");
      return (-1);
    }
  if (col)
    *col = w.ws_col;
  if (row)
    *row = w.ws_row;
  return (0);
}
