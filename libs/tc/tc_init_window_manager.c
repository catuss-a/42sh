/*
** tc_init_window_manager.c for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Jul  7 16:36:30 2010 younes serraj
** Last update Wed Sep 22 23:26:39 2010 younes serraj
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include "tc.h"

int			tc_init_window_manager(void (*f)(void))
{
  if (signal(SIGWINCH, (__sighandler_t)f) == SIG_ERR)
    return (-1);
  return (0);
}
