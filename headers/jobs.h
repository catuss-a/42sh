/*
** jobs.h for 42sh in /home/delmas_s//42sh
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Thu Dec  9 15:45:53 2010 stephane delmas
** Last update Sun Dec 19 22:53:07 2010 younes serraj
*/

#ifndef			__JOBS_H_
# define		__JOBS_H_

# include <sys/types.h>
# include <unistd.h>

typedef struct		s_process
{
  pid_t			pid;
  char			is_finish;
  char			is_stopped;
  struct s_process	*next;
}			t_process;

typedef struct		s_job
{
  pid_t			pgid;
  int			id;
  char			*commandline;
  t_process		*head_process;
  char			last_use;
  struct s_job		*next;
}			t_job;

t_job		*add_job(t_job *head_job, char *line);
int		fill_job(t_job *job, pid_t pid);
t_job		*delete_job(t_job *head_job, pid_t pgid);
int		add_process(t_job *head, t_job *job, pid_t pid);
void		update_last_use(t_job *head, t_job *job);
void		put_job_in_foreground(t_job *job);
void		stop_job(t_job *job);
void		continue_job(t_job *job);
int		kill(pid_t pid, int sig);
pid_t		getpgid(pid_t pid);

#endif			/* JOBS_H_ */
