/*
** init.h for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/struct/headers
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 18:50:13 2010 younes serraj
** Last update Tue Dec  7 20:16:36 2010 younes serraj
*/

#ifndef INIT_H_
# define INIT_H_

# include "ll.h"
# include "config.h"

void			add_elem_to_history(t_config *config,
					    char *line);
void			init_termcap(t_config *sh);
int			load_env(t_ll_list *env);

#endif /* INIT_H_ */
