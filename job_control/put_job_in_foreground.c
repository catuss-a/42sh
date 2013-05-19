/*
** put_job_in_foreground.c for 42sh in /home/delmas_s//job_control
** 
** Made by stephane delmas
** Login   <delmas_s@epitech.net>
** 
** Started on  Sun Dec 12 14:09:30 2010 stephane delmas
** Last update Sun Dec 12 14:41:13 2010 stephane delmas
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"
#include "jobs.h"

void		put_job_in_foreground(t_job *job)
{
  if (tcsetpgrp(STDIN_FILENO, job->pgid) == -1)
    my_puterr("tcsetpgrp error\n");
}
