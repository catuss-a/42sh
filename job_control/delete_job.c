/*
** delete_process.c for 42sh in /home/delmas_s//job_control
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Sun Dec 12 13:41:27 2010 stephane delmas
** Last update Sat Dec 18 16:59:28 2010 stephane delmas
*/

#include <stdlib.h>
#include <sys/types.h>
#include "jobs.h"

static t_job	*delete_job_from_list(t_job *job, t_job *tmp)
{
  t_job		*head;
  t_process	*process;

  head = NULL;
  while (job->head_process != NULL)
    {
      process = job->head_process;
      job->head_process = job->head_process->next;
      free(process);
    }
  if (tmp != NULL)
    tmp->next = job->next;
  else
    head = job->next;
  free(job->commandline);
  free(job);
  return (head);
}

t_job		*delete_job(t_job *job, pid_t pgid)
{
  t_job		*head;
  t_job		*tmp;

  head = job;
  tmp = NULL;
  if (job != NULL)
    {
      while (job != NULL)
	{
	  if (job->pgid == pgid)
	    break;
	  tmp = job;
	  job = job->next;
	}
      if (job != NULL)
	tmp = delete_job_from_list(job, tmp);
    }
  head = tmp;
  return (head);
}
