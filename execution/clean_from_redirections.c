/*
** clean_from_redirections.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Oct  3 21:58:33 2010 younes serraj
** Last update Sat Dec 18 23:20:16 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

static int		is_keyword(char *s)
{
  if (!my_strcmp(s, "<") ||
      !my_strcmp(s, "<<") ||
      !my_strcmp(s, ">") ||
      !my_strcmp(s, ">>"))
    return (0);
  return (-1);
}

static void		boucle(char *buffer, char **wt, int *i)
{
  if (!is_keyword(wt[*i]))
    *i += 1;
  else
    {
      my_strcat(buffer, wt[*i]);
      my_strcat(buffer, " ");
    }
}

void			clean_from_redirections(char *s)
{
  char			**wt;
  char			*buffer;
  int			i;

  wt = my_make_argv(s, 0);
  buffer = x_malloc(sizeof(char) * (my_strlen(s) + 2));
  *buffer = 0;
  i = 0;
  while (wt[i])
    {
      boucle(buffer, wt, &i);
      i += 1;
    }
  my_wt_free(wt);
  x_free(wt);
  my_trim(buffer, " \t");
  my_strcpy(s, buffer);
  x_free(buffer);
}
