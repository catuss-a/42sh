/*
** fill_job.c for 42sh in /home/delmas_s//rendu/c/proj/42sh_job
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Tue Dec 14 17:55:19 2010 stephane delmas
** Last update Sat Dec 18 15:30:11 2010 stephane delmas
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "jobs.h"

int		fill_job(t_job *job, pid_t pid)
{
  if (job != NULL)
    {
      job->pgid = pid;
      job->head_process->pid = pid;
      if (setpgid(pid, pid) == -1)
	my_puterr("Error setpgid\n");
      printf("[%i] %i\n", job->id, job->pgid);
      return (0);
    }
  else
    return (-1);
}
