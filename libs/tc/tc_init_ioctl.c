/*
** tc_init_ioctl.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Jul  7 16:36:21 2010 younes serraj
** Last update Wed Sep 22 23:25:08 2010 younes serraj
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <termios.h>
#include "my.h"
#include "tc.h"

static struct termios	*tc_ioctl_backup(struct termios *st)
{
  static struct termios	t;

  if (st)
    my_memcpy(&t, st, sizeof(struct termios));
  return (&t);
}

int			tc_init_ioctl()
{
  struct termios	t;

  if (ioctl(0, TCGETA, &t) < 0)
    {
      my_puterr("Error: ioctl(TCGETA) failed\n");
      return (-1);
    }
  tc_ioctl_backup(&t);
  t.c_lflag = 0;
  t.c_oflag = 0;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (ioctl(0, TCSETA, &t) < 0)
    {
      my_puterr("Error: ioctl(TCSETA) failed\n");
      return (-1);
    }
  if (tc_checkup())
    {
      tc_restore_ioctl();
      return (-1);
    }
  return (0);
}

int			tc_restore_ioctl()
{
  struct termios	*t;

  t = tc_ioctl_backup(0);
  if (ioctl(0, TCSETA, t) < 0)
    {
      my_puterr("Error: ioctl(TIOCSETA) failed\n");
      return (-1);
    }
  return (0);
}
