/*
** config_user.h for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/config
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 15:59:55 2010 younes serraj
** Last update Tue Dec  7 16:02:43 2010 younes serraj
*/

#ifndef CONFIG_USER_H_
# define CONFIG_USER_H_

typedef struct		s_user
{
  int			id;
  char			*name;
  char			*home_dir;
}			t_user;

void			init_user(t_user *user);
void			free_user(t_user *user);

#endif /* CONFIG_USER_H_ */
