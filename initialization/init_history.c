/*
** init_history.c for 42sh in /home/catuss_a//Desktop/42sh/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Nov  5 18:02:49 2010 axel catusse
** Last update Tue Dec  7 16:46:53 2010 younes serraj
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "config.h"

void			add_elem_to_history(t_config *sh, char *line)
{
  t_history		*new;

  new = x_malloc(sizeof(*new));
  new->data = my_strdup(line);
  new->next = sh->cmdline.history;
  new->prev = NULL;
  if (sh->cmdline.history)
    sh->cmdline.history->prev = new;
  sh->cmdline.history = new;
  return ;
}

void			init_history(t_config *sh)
{
  int			fd;
  char			*line;
  t_history		*tmp;

  sh->cmdline.history_flag = 0;
  if ((fd = open(HISTORY_FILE, O_RDONLY | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    {
      my_printf_err("Warning: cannot open '%s'\n", HISTORY_FILE);
      exit(EXIT_FAILURE);
    }
  while ((line = get_next_line(fd)) && my_strlen(line) < BUFF_SIZE)
    {
      add_elem_to_history(sh, line);
      free(line);
    }
  tmp = sh->cmdline.history;
  close(fd);
  return ;
}
