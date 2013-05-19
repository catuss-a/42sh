/*
** processus.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Oct  2 20:15:45 2010 younes serraj
** Last update Sun Dec 19 23:13:43 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "ll.h"
#include "shell.h"
#include "system.h"
#include "builtins.h"
#include "config.h"

int			exit_status_manager(pid_t pid)
{
  int			status;

  if (waitpid(pid, &status, 0) == -1)
    return (-1);
  signal_display(status);
  return (WEXITSTATUS(status));
}

/*
** Lit des donnees depuis le pipe et execute un programme
*/
int			processus_father(t_ll_node *w, t_config *conf)
{
  t_exec_info		ei;
  int			i;
  int			ret;

  make_exec_info(&ei, w->data, &(conf->env));
  if (!is_builtin(ei.argv[0]))
    {
      exec_builtin(my_wt_count(ei.argv), ei.argv, conf, &ret);
      exit(ret);
    }
  else if ((i = get_binary_path(&(conf->env), ei.argv[0], &(ei.binpath))) != 0)
    {
      if (i == 1)
	my_printf_err("'%s': command not found\n", ei.argv[0]);
      else if (i == -1)
	my_printf_err("'%s': permission denied\n", ei.argv[0]);
      exit(EXIT_FAILURE);
    }
  execve(ei.binpath, ei.argv, ei.envp);
  exit(EXIT_FAILURE);
}

/*
** Fork en passant a la commande suivante
*/
int			processus_child(int *fd, t_ll_node *w, t_config *conf)
{
  if (fd[IN] == -2 || fd[OUT] == -2)
    exit(EXIT_FAILURE);
  if (w->previous == 0)
    {
      if (fd[IN] > -1 && dup2(fd[IN], 0) == -1)
	  my_puterr("Error: dup2() failed\n");
      processus_father(w, conf);
    }
  else
    fork_piped(w, fd, conf);
  return (-1);
}
