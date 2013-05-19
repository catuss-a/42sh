/*
** extract_redirections.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep 29 22:26:21 2010 younes serraj
** Last update Sun Dec 19 19:42:27 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "ll.h"
#include "config.h"
#include "shell.h"
#include "memory.h"

int			write_redirection_in(int fd_in, int pipe_out)
{
  char			*buffer;
  int			size;

  if (fd_in == -1)
    return (0);
  size = my_readfile_from_fd(fd_in, &buffer);
  close(fd_in);
  if (buffer == 0)
    return (-1);
  if (write(pipe_out, buffer, size) != size)
    {
      x_free(buffer);
      my_puterr("Error: write() failed\n");
      return (-1);
    }
  x_free(buffer);
  return (0);
}

static int		drg_write_data_in_pipe(char *word,
					       int *pipe_fd)
{
  char			*buffer;

  my_putstr("? ");
  if (!(buffer = get_next_line(0)))
    {
      close(pipe_fd[OUT]);
      return (0);
    }
  if (!my_strcmp(buffer, word))
    {
      x_free(buffer);
      close(pipe_fd[OUT]);
      return (0);
    }
  if (write(pipe_fd[OUT], buffer, my_strlen(buffer)) == -1 ||
      write(pipe_fd[OUT], "\n", 1) == -1)
    {
      my_puterr("Error: write() failed\n");
      x_free(buffer);
      return (-1);
    }
  x_free(buffer);
  return (1);
}

static int		dbl_redirection_gauche(char *word, int *fd)
{
  int			pipe_fd[2];
  int			i;

  if (pipe(pipe_fd) < 0)
    {
      my_puterr("Error: pipe() failed\n");
      return (-1);
    }
  while (1)
    {
      if ((i = drg_write_data_in_pipe(word, (int *)pipe_fd)) == 1)
	continue;
      else if (i == 0)
	break;
      else
	{
	  *fd = -1;
	  return (-1);
	}
    }
  *fd = pipe_fd[IN];
  return (0);
}

static int		check_cases(char **wt, int i, int *fd)
{
  if (!my_strcmp(wt[i], "<"))
    {
      if ((*fd = open(wt[i + 1], O_RDONLY)) == -1)
	{
	  my_printf_err("'%s': No such file or directory\n", wt[i + 1]);
	  *fd = -2;
	}
      return (0);
    }
  else if (!my_strcmp(wt[i], "<<"))
    {
      if (dbl_redirection_gauche(wt[i + 1], fd) != 0)
	*fd = -1;
      return (0);
    }
  return (-1);
}

int			extract_redirection_in(t_ll_list *list)
{
  int			fd;
  char			**wt;
  int			i;

  if ((wt = my_split((char *)list->tail->data, " ")) == 0)
    return (-1);
  else
    {
      my_wt_free(wt);
      x_free(wt);
    }
  fd = -1;
  wt = my_split((char *)list->head->data, " ");
  i = 0;
  while (wt[i])
    {
      if (!check_cases(wt, i, &fd))
	break;
      i += 1;
    }
  my_wt_free(wt);
  x_free(wt);
  return (fd);
}
