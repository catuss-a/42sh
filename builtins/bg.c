/*
** bg.c for 42sh in /home/delmas_s//rendu/c/proj/42sh
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Sat Dec 18 16:04:12 2010 stephane delmas
** Last update Sat Dec 18 16:23:35 2010 stephane delmas
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "config.h"
#include "shell.h"
#include "builtins.h"
#include "my.h"
#include "jobs.h"

static int	check_job_and_put_in_background(t_job *job, char *opt,
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
      update_last_use(conf->head_job, job);
      if (kill(job->pgid, SIGCONT) < 0)
	my_puterr("Error: kill (SIGCONT)\n");
      job->head_process->is_stopped = 0;
      printf("[%i]\t%s &\n", job->id, job->commandline);
      return (0);
    }
  return (-1);
}

static int	put_in_background(t_job *job, t_config *conf)
{
  while (job != NULL)
    {
      if (job->last_use == 1)
	break;
      job = job->next;
    }
  if (job != NULL)
    {
      update_last_use(conf->head_job, job);
      if (kill(job->pgid, SIGCONT) < 0)
	my_puterr("Error: kill (SIGCONT)\n");
      job->head_process->is_stopped = 0;
      printf("[%i]\t%s &\n", job->id, job->commandline);
      return (0);
   }
  return (-1);
}

int		builtins_bg(int ac, char **av, t_config *conf, int *ret)
{
  *ret = 0;
  if (ac == 1 && put_in_background(conf->head_job, conf) == -1)
    {
      *ret = -1;
      my_puterr("bg: No current job.\n");
    }
  else if (ac == 2)
    {
      if (check_job_and_put_in_background(conf->head_job, av[1], conf) == -1)
	{
	  *ret = -1;
	  my_puterr("bg: No such job.\n");
	}
    }
  else if (ac != 1)
    {
      *ret = -1;
      my_puterr("bg: No such job.\n");
    }
  return (MYSH_SIGNAL_NOPE);
}
