/*
** get_binary_path.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Thu Sep 30 13:34:54 2010 younes serraj
** Last update Tue Dec  7 12:54:46 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"
#include "shell.h"
#include "memory.h"
#include "system.h"

static char		*make_binary_path(char *dir, char *bin_name)
{
  char			*binpath;

  binpath = x_malloc(sizeof(char) *
		     (my_strlen(dir) +  my_strlen(bin_name) + 2));
  my_strcpy(binpath, dir);
  my_strcat(binpath, "/");
  my_strcat(binpath, bin_name);
  return (binpath);
}

static int		special_cases(char *name, char **binpath)
{
  int			i;

  if ((i = check_binary_access(name)) == 0)
    {
      *binpath = my_strdup(name);
      return (0);
    }
  return (i);
}

int			get_binary_path(t_ll_list *env, char *name,
					char **binpath)
{
  char			**wt;
  int			i;
  int			j;

  if (my_findchar('/', name) > -1 || mem_exists(env, "PATH") == -1 ||
      (wt = my_split(mem_get(env, "PATH"), PATH_SEPARATORS)) == NULL)
    return (special_cases(name, binpath));
  i = 0;
  while (wt[i])
    {
      *binpath = make_binary_path(wt[i], name);
      if ((j = check_binary_access(*binpath)) == 0)
	return (0);
      x_free(*binpath);
      if (j == -1)
	return (-1);
      i += 1;
    }
  return (1);
}
