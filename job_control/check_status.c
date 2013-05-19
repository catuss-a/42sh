/*
** check_status.c for 42sh in /home/delmas_s//rendu/c/proj/42sh/job_control
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Fri Dec 17 23:11:14 2010 stephane delmas
** Last update Fri Dec 17 23:31:42 2010 stephane delmas
*/

#include <stdlib.h>
#include "jobs.h"
#include "config.h"

static t_job	*find_the_minus(t_job *head)
{
  t_job		*job;
  int		i;

  job = NULL;
  i = -2147483647;
  while (head != NULL)
    {
      if (head->last_use > i)
	{
	  job = head;
	  i = head->last_use;
	}
      head = head->next;
    }
  return (job);
}

void		check_status(t_config *conf)
{
  t_job		*job;
  t_job		*save;

  job = conf->head_job;
  while (job != NULL)
    {
      if (job->head_process->is_finish)
	conf->head_job = delete_job(conf->head_job, job->pgid);
      job = job ->next;
    }
  save = find_the_minus(conf->head_job);
  if (save != NULL)
    update_last_use(conf->head_job, save);
}
