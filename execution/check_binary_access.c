/*
** check_binary_access.c for minishell2 in /home/serraj_y//c/minishell2/system
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep 29 19:18:23 2010 younes serraj
** Last update Sun Dec 19 23:29:40 2010 younes serraj
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "ll.h"
#include "system.h"

int			check_binary_access(char *path)
{
  if (access(path, F_OK) != 0)
    return (1);
  if (access(path, X_OK) != 0)
    {
      my_printf_err("'%s': Permission denied\n", path);
      return (-1);
    }
  return (0);
}
