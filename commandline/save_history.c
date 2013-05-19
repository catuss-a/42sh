/*
** save_history.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/commandline
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec 14 21:55:42 2010 younes serraj
** Last update Sun Dec 19 23:29:15 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "config.h"
#include "shell.h"

void			save_history(t_config *conf)
{
  int			fd;
  t_history		*w;

  w = conf->cmdline.history;
  if (!w)
    return ;
  if ((fd = open(HISTORY_FILE, OPEN_MODE_WRITE, OPEN_PERMISSIONS)) == -1)
    {
      my_puterr("Error: cannot open '.history'\n");
      return ;
    }
  while (w->next)
    w = w->next;
  while (w)
    {
      if (write(fd, w->data, my_strlen(w->data)) == -1 ||
	  write(fd, "\n", 1) == -1)
	{
	  my_puterr("Error: write() failed while saving the history\n");
	  close(fd);
	  return ;
	}
      w = w->prev;
    }
  close(fd);
}
