/*
** add_process.c for 42sh in /home/delmas_s//42sh
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Thu Dec  9 16:47:46 2010 stephane delmas
** Last update Tue Dec 14 21:28:31 2010 stephane delmas
*/

#include <stdlib.h>
#include "my.h"
#include "jobs.h"

int		add_process(t_job *head, t_job *job, pid_t pid)
{
  t_process	*new_process;
  t_process	*process;

  if (job == NULL || head == NULL)
    return (-1);
  new_process = x_malloc(sizeof(t_process));
  new_process->pid = pid;
  new_process->is_finish = 0;
  new_process->is_stopped = 0;
  new_process->next = NULL;
  process = head->head_process;
  while (process != NULL && process->next != NULL)
    process = process->next;
  process->next = new_process;
  return (0);
}
