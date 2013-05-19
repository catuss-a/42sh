/*
** builtins.h for minishell2 in /home/serraj_y//c/minishell2/builtins
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Sep 19 20:11:36 2010 younes serraj
** Last update Sat Dec 18 16:58:21 2010 stephane delmas
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

# include "config.h"

typedef struct		s_builtins_f
{
  char			*name;
  int			(*f)(int, char **,
			     t_config *, int *);
}			t_builtins_f;

/*
** NOTE:
** Builtin functions put the return value in 'ret'
** and return a signal (defined in headers/config.h)
** which tells EXIT (exit the shell) or
** NOPE (keep executing instructions).
*/
int			builtins_history(int argc, char **argv,
					 t_config *conf, int *ret);
int			builtins_cd(int argc, char **argv,
				    t_config *conf, int *ret);
int			builtins_pwd(int argc, char **argv,
				     t_config *conf, int *ret);
int			builtins_exit(int argc, char **argv,
				      t_config *conf, int *ret);
int			builtins_echo(int argc, char **argv,
				      t_config *conf, int *ret);
int			builtins_env(int argc, char **argv,
				     t_config *conf, int *ret);
int			builtins_setenv(int argc, char **argv,
					t_config *conf, int *ret);
int			builtins_unsetenv(int argc, char **argv,
					  t_config *conf, int *ret);
int			builtins_set(int argc, char **argv,
				     t_config *conf, int *ret);
int			builtins_unset(int argc, char **argv,
				       t_config *conf, int *ret);
int			builtins_jobs(int argc, char **argv,
				     t_config *conf, int *ret);
int			builtins_fg(int argc, char **argv,
				     t_config *conf, int *ret);
int			builtins_bg(int argc, char **argv,
				     t_config *conf, int *ret);

char			*get_absolute_path(t_config *conf, char *to);
char			*clean_path(char *path);

int			is_builtin(char *name);
int			exec_builtin(int argc, char **argv,
				     t_config *conf, int *ret);

#endif /* BUILTINS_H_ */
