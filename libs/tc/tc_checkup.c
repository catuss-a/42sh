/*
** tc_checkup.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Jul  2 17:57:43 2010 younes serraj
** Last update Fri Jul  2 19:42:11 2010 younes serraj
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include "my.h"
#include "tc.h"

static int		check_commands()
{
  if (TC_GOTO(0, 0) ||
      TC_STANDOUT_MODE_ON() ||
      TC_STANDOUT_MODE_OFF() ||
      TC_UNDERLINE_MODE_ON() ||
      TC_UNDERLINE_MODE_OFF() ||
      TC_BOLD_MODE_ON() ||
      TC_BOLD_MODE_OFF() ||
      TC_SHOW_CURSOR() ||
      TC_HIDE_CURSOR() ||
      TC_CLEAR_SCREEN())
    return (-1);
  return (0);
}

int			tc_checkup()
{
  char			*term;
  static char		bp[1024];
  int			col;
  int			row;

  if (!(term = x_getenv_term()) ||
      !(*term) ||
      tgetent(bp, term) != 1 ||
      tc_get_window_size(&col, &row) ||
      col < 5 || row < 5 ||
      check_commands())
    {
      my_puterr("Error: tc_checkup() failed\n");
      return (-1);
    }
  return (0);
}
