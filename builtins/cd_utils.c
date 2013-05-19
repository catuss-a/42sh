/*
** cd_utils.c for minishell2 in /home/serraj_y//c/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 19:15:52 2010 younes serraj
** Last update Thu Dec  9 11:48:33 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"

char			*get_absolute_path(t_config *conf, char *to)
{
  char			*buffer;

  if (!to)
    return (my_strdup(conf->user.home_dir));
  if (!my_strcmp(to, "-"))
    return (my_strdup(conf->previous_dir));
  else if (*to == '~' && (to[1] == 0 || to[1] == '/'))
    {
      buffer = x_malloc(sizeof(char) *
			(my_strlen(conf->user.home_dir) + my_strlen(to) + 1));
      my_strcpy(buffer, conf->user.home_dir);
      my_strcat(buffer, to + 1);
      return (buffer);
    }
  else
    return (my_strdup(to));
}
