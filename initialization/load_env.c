/*
** load_env.c for minishell2 in /home/serraj_y//c/minishell2/main
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Sep 21 20:13:42 2010 younes serraj
** Last update Wed Dec  8 16:52:42 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "config.h"
#include "memory.h"

int			load_env(t_ll_list *env)
{
  extern char		**environ;
  int			i;

  i = 0;
  while (environ[i])
    {
      ll_push_data(env,
		   (void *)var_make_from_environ(environ[i]),
		   -1);
      i += 1;
    }
  return (0);
}
