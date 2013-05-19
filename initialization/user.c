/*
** config_user.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/config
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 15:55:50 2010 younes serraj
** Last update Fri Dec 17 17:29:22 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "my.h"
#include "config.h"

void			init_user(t_user *user)
{
  struct passwd		*user_info;

  user->id = getuid();
  if ((user_info = getpwuid(user->id)) == 0)
    {
      my_puterr("Error: couldn't read user info\n");
      user->name = NULL;
      user->home_dir = NULL;
    }
  user->name = my_strdup(user_info->pw_name);
  user->home_dir = my_strdup(user_info->pw_dir);
}

void			free_user(t_user *user)
{
  if (!user)
    return ;
  x_free(user->name);
  x_free(user->home_dir);
}
