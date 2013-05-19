/*
** fg.c for 42sh in /home/delmas_s//rendu/c/proj/42sh_job
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Tue Dec 14 21:33:15 2010 stephane delmas
** Last update Sun Dec 19 21:52:59 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "config.h"
#include "shell.h"
#include "builtins.h"
#include "my.h"
#include "jobs.h"

static void	wait_for_job(t_config *conf, t_job *job)
{
  int		status;

  update_last_use(conf->head_job, job);
  if (kill(job->pgid, SIGCONT) < 0)
    my_puterr("Error: kill (SIGCONT)\n");
  job->head_process->is_stopped = 0;
  waitpid(job->pgid, &status, WUNTRACED);
  if (WIFSTOPPED(status))
    job->head_process->is_stopped = 1;
  else
    job->head_process->is_finish = 1;
  signal_display(status);
  if (tcsetpgrp(STDIN_FILENO, getpgid(getpid())) == -1)
    my_puterr("Error: tcsetpgrp\n");
  if (tcsetattr(STDIN_FILENO, TCSADRAIN, &conf->tmodes) == -1)
  my_puterr("Error: tcsetattr\n");
}

static int	check_job_and_put_in_foreground(t_job *job, char *opt,
						t_config *conf)
{
  int		i;

  i = atoi(opt);
  while (job != NULL)
    {
      if (job->id == i)
	break;
      job = job->next;
    }
  if (job != NULL)
    {
      if (tcsetpgrp(STDIN_FILENO, job->pgid) == -1)
	my_puterr("tcsetpgrp error\n");
      wait_for_job(conf, job);
      return (0);
    }
  return (-1);
}

static int	put_in_foreground(t_job *job, t_config *conf)
{
  while (job != NULL)
    {
      if (job->last_use == 1)
	break;
      job = job->next;
    }
  if (job != NULL)
    {
      if (tcsetpgrp(STDIN_FILENO, job->pgid) == -1)
	my_puterr("tcsetpgrp error\n");
      wait_for_job(conf, job);
      return (0);
    }
  return (-1);
}

static void	change_signal(int flag)
{
  if (flag)
    {
      signal(SIGCHLD, SIG_DFL);
      signal(SIGQUIT, SIG_DFL);
      signal(SIGURG, SIG_DFL);
      signal(SIGTTIN, SIG_DFL);
      signal(SIGTTOU, SIG_DFL);
    }
  else
    {
      signal(SIGCHLD, SIG_IGN);
      signal(SIGQUIT, SIG_IGN);
      signal(SIGURG, SIG_IGN);
      signal(SIGTTIN, SIG_IGN);
      signal(SIGTTOU, SIG_IGN);
    }
}

int		builtins_fg(int ac, char **av, t_config *conf, int *ret)
{
  change_signal(0);
  *ret = 0;
  if (ac == 1 && put_in_foreground(conf->head_job, conf) == -1)
    {
      *ret = -1;
      my_puterr("fg: No current job.\n");
    }
  else if (ac == 2)
    {
      if (check_job_and_put_in_foreground(conf->head_job, av[1], conf) == -1)
	{
	  *ret = -1;
	  my_puterr("fg: No such job.\n");
	}
    }
  else if (ac != 1)
    {
      *ret = -1;
      my_puterr("fg: No such job.\n");
    }
  change_signal(1);
  return (MYSH_SIGNAL_NOPE);
}
