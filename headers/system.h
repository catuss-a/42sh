/*
** system.h for minishell2 in /home/serraj_y//c/minishell2/system
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 18:34:00 2010 younes serraj
** Last update Sat Dec 11 18:52:08 2010 younes serraj
*/

#ifndef SYSTEM_H_
# define SYSTEM_H_

void			signal_handler(int sig);
void			signal_display(int sig);
void			signal_init();

/*
** File doesn't exists: return (1)
** Permission denied: return (-1)
** OK: return (0)
*/
int			check_binary_access(char *path);

#endif /* SYSTEM_H_ */
