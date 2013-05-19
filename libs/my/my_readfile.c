/*
** my_readfile.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:42:33 2010 younes serraj
** Last update Sun Oct  3 16:46:10 2010 younes serraj
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

static int		add_data_to_buffer(char **buffer, int buffer_size,
					   char *data, int data_size)
{
  char			*new_buffer;

  if (!buffer)
    return (-1);
  new_buffer = x_malloc(buffer_size + data_size);
  if (*buffer && buffer_size)
    my_memcpy(new_buffer, *buffer, buffer_size);
  my_memcpy(new_buffer + buffer_size, data, data_size);
  if (*buffer)
    x_free(*buffer);
  *buffer = new_buffer;
  return (buffer_size + data_size);
}

static int		read_data(int fd, char **data)
{
  char			buffer[MY_READFILE_BUFFSIZE];
  int			i;
  int			size;

  *data = 0;
  size = 0;
  while ((i = read(fd, buffer, MY_READFILE_BUFFSIZE)) > 0)
    size = add_data_to_buffer(data, size, buffer, i);
  if (i == -1)
    {
      x_free(*data);
      my_puterr("Error: read() failed in my_readfile()\n");
      return (0);
    }
  return (size);
}

char			*my_readfile(char *path)
{
  int			fd;
  char			*buffer;
  char			*data;
  int			size;

  if ((fd = open(path, O_RDONLY)) == 0)
    {
      my_puterr("Error: open() failed in my_readfile()\n");
      return (0);
    }
  size = read_data(fd, &buffer);
  close(fd);
  data = x_malloc(size + 1);
  my_memcpy(data, buffer, size);
  x_free(buffer);
  data[size] = 0;
  return (data);
}

int			my_readfile_from_fd(int fd, char **data)
{
  if (fd < 0 || fd == 1 || fd == 2)
    return (0);
  return (read_data(fd, data));
}
