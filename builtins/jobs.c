/*
** jobs.c for 42sh in /home/delmas_s//job_control
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Sun Dec 12 14:50:00 2010 stephane delmas
** Last update Fri Dec 17 23:12:30 2010 stephane delmas
*/

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "shell.h"
#include "builtins.h"
#include "my.h"
#include "jobs.h"

static char	*check_status1(t_process *process)
{
  if (process->is_finish)
    return ("Terminated");
  else if (process->is_stopped)
    return ("Stopped");
  else
    return ("Running");
}

static char	check_last_use(int i)
{
  if (i == 1)
    return ('+');
  else if (i == 0)
    return ('-');
  else
    return (' ');
}

static void	print_all_job(t_job *job, int flag)
{
  t_process	*process;

  while (job != NULL)
    {
      if (flag)
	{
	  printf("[%i]%c\t%i %s\t\t%s\n", job->id,
		 check_last_use(job->last_use),
		 job->head_process->pid,
		 check_status1(job->head_process), job->commandline);
	  process = job->head_process->next;
	  while (process != NULL)
	    {
	      printf("\t%i \t\t%s\n", process->pid, job->commandline);
	      process = process->next;
	    }
	}
      else
	printf("[%i]%c\t%s\t\t%s\n", job->id, check_last_use(job->last_use),
	       check_status1(job->head_process), job->commandline);
      job = job->next;
    }
}

int		builtins_jobs(int ac, char **av, t_config *conf, int *ret)
{
  if (ac == 1 || (ac == 2 && my_strcmp(av[1], "-l") == 0))
    {
      if (ac == 2)
	print_all_job(conf->head_job, 1);
      else
	print_all_job(conf->head_job, 0);
      *ret = 0;
      return (MYSH_SIGNAL_NOPE);
    }
  my_puterr("Usage: jobs [ -l ].\n");
  *ret = -1;
  return (MYSH_SIGNAL_NOPE);
}
