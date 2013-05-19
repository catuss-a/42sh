/*
** update_last_use.c for 42sh in /home/delmas_s//rendu/c/proj/42sh
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Fri Dec 17 21:44:21 2010 stephane delmas
** Last update Fri Dec 17 23:20:51 2010 stephane delmas
*/

#include <stdlib.h>
#include "jobs.h"

void		update_last_use(t_job *head, t_job *job)
{
  t_job		*save;
  t_job		*j;
  int		i;

  save = NULL;
  i = -2147483647;
  job->last_use = 1;
  if (head != NULL)
    {
      j = head;
      while (j != NULL)
	{
	  if (j->pgid != job->pgid)
	    j->last_use -= 1;
	  if (j->last_use > i && job->pgid != j->pgid)
	    {
	      save = j;
	      i = j->last_use;
	    }
	  j = j->next;
	}
      if (save != NULL)
	save->last_use = 0;
    }
}
