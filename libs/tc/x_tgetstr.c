/*
** x_tgetstr.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Jul  2 16:55:25 2010 younes serraj
** Last update Wed Sep 22 23:23:32 2010 younes serraj
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <curses.h>
#include <termcap.h>
#include "my.h"
#include "tc.h"

char			*x_tgetstr(char *cap, char **area)
{
  char			*cap_ptr;

  if (!(cap_ptr = tgetstr(cap, area)))
    {
      my_printf_err("Error: tgetstr(%s) failed\n", cap);
      return (0);
    }
  return (cap_ptr);
}
