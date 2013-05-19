/*
** get_globing.c for 42sh in /home/delmas_s//etoile
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Wed Dec  8 17:09:26 2010 stephane delmas
** Last update Wed Dec  8 17:59:59 2010 stephane delmas
*/

#include <glob.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my.h"

static int	count_total_letter(char **wt, int pathc)
{
  int		i;
  int		c;

  i = 0;
  c = 0;
  while (i < pathc)
    {
      c += my_strlen(wt[i]);
      i++;
    }
  c += pathc - 1;
  return (c);
}

static char	*create_new_data(glob_t *buf)
{
  char		*new_data;
  int		i;
  int		u;
  int		a;

  i = count_total_letter(buf->gl_pathv, buf->gl_pathc);
  new_data = x_malloc(sizeof(char) * (i + 1));
  i = 0;
  a = 0;
  while ((unsigned)i < buf->gl_pathc)
    {
      u = 0;
      while (buf->gl_pathv[i][u])
	new_data[a++] = buf->gl_pathv[i][u++];
      if (buf->gl_pathv[i + 1] != NULL)
	new_data[a++] = ' ';
      i++;
    }
  new_data[a] = '\0';
  return (new_data);
}

static int	is_globing(char *data)
{
  int		i;

  i = 0;
  while (data[i])
    {
      if (data[i] == '*' || data[i] == '?' || data[i] == '[')
	return (1);
      i++;
    }
  return (0);
}

/*
** return:
** -1 : no match
** 0 : match
** 1 : no globing
** 2 : error
*/

int		get_globing(char *data, char **result)
{
  glob_t	buf;
  int		i;

  if (!is_globing(data))
    return (1);
  i = glob(data, 0, NULL, &buf);
  if (i == GLOB_NOMATCH)
    return (-1);
  else if (i != 0)
    {
      my_puterr("Error: glob\n");
      return (2);
    }
  *result = create_new_data(&buf);
  globfree(&buf);
  return (0);
}
