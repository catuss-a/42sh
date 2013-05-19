/*
** stop_job.c for 42sh in /home/delmas_s//job_control
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Sun Dec 12 14:20:36 2010 stephane delmas
** Last update Sun Dec 12 14:44:56 2010 stephane delmas
*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "jobs.h"

void		stop_job(t_job *job)
{
  t_process	*process;

  process = job->head_process;
  while (process != NULL)
    {
      process->is_stopped = 1;
      process = process->next;
    }
  if (kill(job->pgid, SIGSTOP) == -1)
    my_puterr("kill error (SIGSTOP)\n");
}
