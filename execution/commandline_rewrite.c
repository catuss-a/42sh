/*
** commandline_rewrite.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/execution
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Dec 11 19:02:43 2010 younes serraj
** Last update Sun Dec 19 23:26:02 2010 younes serraj
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "execution.h"

char *keywords[] = {
  ";",
  "||",
  "|",
  "&&",
  "&",
  "<<",
  ">>",
  "<",
  ">",
  NULL
};

/*
**
** NEW COMMAND LINE LENGTH
**
*/
static void		check_char(char *s, int *buff_size,
				   int *skip)
{
  int			len;

  *skip = 1;
  if (!*s)
    return ;
  if ((len = get_keyword_length(s)) > 0)
    {
      *buff_size += len + 1;
      *skip = len;
    }
  else if ((len = get_word_len(s)) > 0)
    {
      *buff_size += len + 1;
      *skip = len;
    }
  else if (!IS_SEPARATOR(*s))
    {
      *buff_size += 1;
      if (IS_SEPARATOR(*(s + 1)) ||
	  IS_INHIBITOR(*(s + 1)) ||
	  get_keyword_length(s + 1) > 0)
	*buff_size += 1;
    }
}

static int		get_new_cmdline_len(char *cmdline)
{
  int			buff_size;
  int			i;
  int			skip;

  buff_size = 0;
  i = 0;
  while (cmdline[i])
    {
      check_char(cmdline + i, &buff_size, &skip);
      i += 1;
    }
  return (buff_size);
}

/*
**
** WRITE NEW COMMAND LINE
**
*/
static int		write_char(char *s, char *buffer,
				   int *skip)
{
  if (!*s)
    return (0);
  if ((*skip = get_keyword_length(s)) > 0)
    sprintf(buffer, "%s%.*s ", buffer, *skip, s);
  else if (IS_INHIBITOR(*s))
    {
      if ((*skip = get_word_len(s)) < 1)
	{
	  printf("Error: Unmatched %c.\n", *s);
	  return (-1);
	}
      sprintf(buffer, "%s%.*s ", buffer, *skip, s);
    }
  else if (!IS_SEPARATOR(*s))
    {
      my_strncat(buffer, s, 1);
      if (IS_SEPARATOR(*(s + 1)) ||
	  IS_INHIBITOR(*(s + 1)) ||
	  get_keyword_length(s + 1) > 0)
	my_strcat(buffer, " ");
      *skip = 1;
    }
  else
    *skip = 1;
  return (0);
}

static int		write_new_commandline(char *cmdline, char *buffer)
{
  int			i;
  int			skip;

  i = 0;
  skip = 0;
  while (cmdline[i])
    {
      if (write_char(cmdline + i, buffer, &skip) == -1)
	return (-1);
      i += skip;
    }
  if (*buffer)
    my_trim(buffer, SEPARATORS);
  return (0);
}

char			*commandline_rewrite(char *cmdline)
{
  char			*buffer;
  int			buff_size;

  buff_size = get_new_cmdline_len(cmdline);
  buffer = x_malloc(sizeof(char) * (buff_size + 2));
  my_memset(buffer, 0, buff_size + 2);
  if (write_new_commandline(cmdline, buffer) == -1)
    {
      x_free(buffer);
      return (NULL);
    }
  if (my_strcmp(buffer, "unsetenv *"))
    apply_globing(&buffer);
  my_trim(buffer, SEPARATORS);
  if (my_strlen(buffer) == 0)
    {
      x_free(buffer);
      buffer = NULL;
    }
  return (buffer);
}
