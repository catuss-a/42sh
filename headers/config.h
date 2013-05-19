/*
** config.h<2> for 42sh in /home/serraj_y//catuss/42sh/includes
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 15:30:39 2010 younes serraj
** Last update Fri Dec 17 23:29:41 2010 stephane delmas
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# include <termios.h>
# include "ll.h"
# include "config_user.h"
# include "cmdline.h"
# include "jobs.h"

typedef struct		s_config
{
  t_ll_list		env;
  t_ll_list		variables;
  t_user		user;
  t_cmdline		cmdline;
  t_ll_list		plugins;
  char			*previous_dir;
  t_job			*head_job;
  t_job			*current_job;
  pid_t			shell_pgid;
  struct termios	tmodes;
}			t_config;

# include "commandline.h"

void			init_config(t_config *conf);
void			free_config(t_config *conf);
void			check_status(t_config *conf);
t_config		*get_config();

#endif /* CONFIG_H_ */
