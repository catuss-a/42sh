/*
** shell.h for minishell2 in /home/serraj_y//c/minishell2/shell
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 18:32:31 2010 younes serraj
** Last update Tue Dec  7 18:44:46 2010 younes serraj
*/

#ifndef SHELL_H_
# define SHELL_H_

# include <sys/types.h>
# include "ll.h"
# include "system.h"
# include "config.h"

# define MYSH_SIGNAL_NOPE	0
# define MYSH_SIGNAL_EXIT	1

# define IN	0
# define OUT	1
# define PROG	2

# ifndef PATH_SEPARATORS
#  define PATH_SEPARATORS	":"
# endif

# define OPEN_PERMISSIONS	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# define OPEN_MODE_WRITE	(O_CREAT | O_TRUNC | O_WRONLY)
# define OPEN_MODE_APPEND	(O_CREAT | O_APPEND | O_WRONLY)

/*
** EXECUTION INFORMATION
*/
typedef struct		s_exec_info
{
  char			*binpath;
  char			**argv;
  char			**envp;
}			t_exec_info;

# include "execution.h"

#endif /* SHELL_H_ */
