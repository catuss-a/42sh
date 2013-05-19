/*
** check_fd_read.c for my in /u/all/serraj_y/rendu/c/proj/42sh
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec 14 23:02:42 2010 younes serraj
** Last update Tue Dec 14 23:03:05 2010 younes serraj
*/

#include <stdlib.h>
#include <sys/select.h>

int			check_fd_read(int fd)
{
  fd_set		fds;
  struct timeval	timeout;

  timeout.tv_sec = 0;
  timeout.tv_usec = 1;
  FD_ZERO(&fds);
  FD_SET(fd, &fds);
  if (select(fd + 1, &fds, NULL, NULL, &timeout) < 1)
    return (-1);
  return (0);
}
