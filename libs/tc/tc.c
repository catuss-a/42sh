/*
** tc_clear_screen.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Jul  2 16:52:15 2010 younes serraj
** Last update Wed Sep 22 22:54:44 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <termcap.h>
#include "my.h"
#include "tc.h"

int			tc(char *cmd)
{
  char			area[TC_BUFFER_SIZE];
  char			*ptr;

  ptr = area;
  if (!(ptr = x_tgetstr(cmd, &ptr)))
    return (-1);
  if (tputs(ptr, 1, (int (*)(int))my_putchar_err) == ERR)
    return (-1);
  return (0);
}
