/*
** memory.h for minishell2 in /home/serraj_y//c/minishell2
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep 20 18:21:57 2010 younes serraj
** Last update Thu Sep 30 15:34:57 2010 younes serraj
*/

#ifndef MEMORY_H_
# define MEMORY_H_

# include "ll.h"

typedef struct		s_var
{
  char			*name;
  char			*value;
}			t_var;

/*
** VARIABLE MANAGEMENT
*/
t_var			*var_make(char *name, char *value);
void			var_free(t_var *var);
t_var			*var_make_from_environ(char *env_entry);

/*
** MEMORY MANAGEMENT
*/
int			mem_exists(t_ll_list *mem, char *name);
void			mem_set(t_ll_list *mem,
				char *name, char *value);
char			*mem_get(t_ll_list *mem, char *name);
void			mem_del(t_ll_list *mem, char *name);

/*
** ENVIRON-BASED FUNCTIONS
*/
int			mem_import_environ(t_ll_list *mem);
char			**mem_make_environ(t_ll_list *mem);

#endif /* MEMORY_H_ */
