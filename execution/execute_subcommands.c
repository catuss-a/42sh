/*
** execute_subcommands.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Thu Sep 30 20:59:01 2010 younes serraj
** Last update Sun Dec 19 19:56:03 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "ll.h"
#include "config.h"
#include "shell.h"
#include "memory.h"
#include "system.h"
#include "jobs.h"

void			fork_piped(t_ll_node *w, int *fd, t_config *conf)
{
  int			pipe_fd[2];
  pid_t			pid;

  if (pipe(pipe_fd) < 0)
    {
      my_puterr("Error: pipe() failed\n");
      exit(EXIT_FAILURE);
    }
  if ((pid = fork()) == -1)
    {
      my_puterr("Error: fork() failed\n");
      exit(EXIT_FAILURE);
    }
  if (pid)
    {
      close(pipe_fd[OUT]);
      dup2(pipe_fd[IN], 0);
      processus_father(w, conf);
    }
  else
    {
      close(pipe_fd[IN]);
      dup2(pipe_fd[OUT], 1);
      processus_child(fd, w->previous, conf);
    }
}

static void		fork_tail(t_ll_node *w, int *fd, t_config *conf)
{
  int			pipe_fd[2];
  pid_t			pid;

  if (pipe(pipe_fd) < 0)
    {
      my_puterr("Error: pipe() failed\n");
      exit(EXIT_FAILURE);
    }
  if ((pid = fork()) == -1)
    {
      my_puterr("Error: fork() failed\n");
      exit(EXIT_FAILURE);
    }
  if (pid)
    {
      close(pipe_fd[OUT]);
      dup2(pipe_fd[IN], 0);
      processus_father(w, conf);
    }
  else
    {
      close(pipe_fd[IN]);
      dup2(pipe_fd[OUT], 1);
      processus_child(fd, w->previous, conf);
    }
}

/*
** Fork pour garder le shell
** le parent (shell) envoit dans le pipe la redirection d'entree
** le fils executera les commandes de l'utilisateur
*/
static int		forker(t_ll_list *list, int *fd,
			       t_config *conf)
{
  pid_t			pid;

  if ((pid = fork()) == -1)
    {
      my_puterr("Error: fork() failed\n");
      return (-1);
    }
  if (pid)
    {
      if (list->is_job)
	fill_job(conf->current_job, pid);
      else
	return (exit_status_manager(pid));
    }
  else
    {
      if (fd[OUT] > -1 && dup2(fd[OUT], 1) == -1)
	my_puterr("Error: dup2() failed\n");
      if (list->count == 1)
	processus_child(fd, list->head, conf);
      else
	fork_tail(list->tail, fd, conf);
    }
  return (0);
}

int			execute_subcommands(t_ll_list *subcommands,
					    t_config *conf, int *ret)
{
  int			fd[2];
  t_job			*job;

  if (subcommands->is_job)
    {
      conf->head_job = add_job(conf->head_job, subcommands->tail->data);
      job = conf->head_job;
      while (job != NULL && job->next != NULL)
	job = job->next;
      conf->current_job = job;
    }
  fd[IN] = extract_redirection_in(subcommands);
  fd[OUT] = extract_redirection_out(subcommands);
  clean_from_redirections((char *)subcommands->head->data);
  clean_from_redirections((char *)subcommands->tail->data);
  if (subcommands->count > 0 &&
      my_strlen(subcommands->head->data) > 0 &&
      my_strlen(subcommands->tail->data) > 0)
    *ret = forker(subcommands, (int *)fd, conf);
  if (fd[IN] > -1)
    close(fd[IN]);
  if (fd[OUT] > -1)
    close(fd[OUT]);
  return (MYSH_SIGNAL_NOPE);
}
