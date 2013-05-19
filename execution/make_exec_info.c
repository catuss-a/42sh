/*
** make_exec_info.c for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Thu Sep 30 13:37:52 2010 younes serraj
** Last update Sat Dec 18 23:20:50 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"
#include "shell.h"
#include "system.h"
#include "memory.h"

void			make_exec_info(t_exec_info *ei,
				       char *line, t_ll_list *env)
{
  my_memset(ei, 0, sizeof(t_exec_info));
  ei->argv = my_make_argv(line, 1);
  ei->envp = mem_make_environ(env);
}

