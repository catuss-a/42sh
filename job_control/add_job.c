/*
** job.c for 42sh in /home/delmas_s//42sh
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Thu Dec  9 15:59:41 2010 stephane delmas
** Last update Fri Dec 17 22:50:01 2010 stephane delmas
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "jobs.h"

static int	check_id(t_job *job)
{
  int		i;

  i = 0;
  while (job != NULL)
    {
      if (job->id > i)
	i = job->id;
      job = job->next;
    }
  return (i + 1);
}

t_job		*add_job(t_job *head, char *line)
{
  t_job		*new_job;
  t_job		*tmp;

  new_job = x_malloc(sizeof(t_job));
  new_job->pgid = 0;
  new_job->id = check_id(head);
  new_job->commandline = my_strdup(line);
  update_last_use(head, new_job);
  new_job->head_process = x_malloc(sizeof(t_process));
  new_job->head_process->is_finish = 0;
  new_job->head_process->is_stopped = 0;
  new_job->head_process->pid = 0;
  new_job->head_process->next = NULL;
  new_job->next = NULL;
  if (head == NULL)
    return (new_job);
  tmp = head;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_job;
  return (head);
}
