/*
** execution.h for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/struct/headers
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 18:38:51 2010 younes serraj
** Last update Fri Dec 17 17:46:33 2010 younes serraj
*/

#ifndef EXECUTION_H_
# define EXECUTION_H_

# include "ll.h"
# include "shell.h"

int			check_fd_read(int fd);
int			get_globing(char *data, char **result);

/*
** COMMANDLINE_REWRITE_H_
*/
char			*commandline_rewrite(char *cmdline);
int			get_keyword_length(char *s);
int			get_word_len(char *s);
void			apply_globing(char **cmdline);

/*
** IS_VALID_COMAND_H_
*/
int			is_valid_command(char **argv);

/*
** EXTRACT_REDIRECTIONS_H_
*/
void			clean_from_redirections(char *s);
int			write_redirection_in(int fd_in, int pipe_out);
int			extract_redirection_out(t_ll_list *list);
int			extract_redirection_in(t_ll_list *list);

/*
** GET_BINARY_PATH_H_
*/
int			get_binary_path(t_ll_list *env,
					char *name,
					char **binpath);

/*
** QUERY_OUT_H_
*/
int			query_out(char *line,
				  t_config *conf, int *ret);

/*
** SPLIT_COMMAND_H_
*/
char			*build_str_from_wt(char **wt, int from, int to);
void			split_commands(t_ll_list *list,
				       char *line,
				       char *sep, int strict);

int			my_exec(t_config *conf, char *line, int *ret);
int			shell();
void			make_commands_list(t_ll_list *list, char *line);

/*
** MAKE_EXEC_INFO_H_
*/
void			make_exec_info(t_exec_info *ei,
				       char *line, t_ll_list *env);

/*
** PROCESSUS_H_
*/
int			exit_status_manager(pid_t pid);
int			processus_father(t_ll_node *w,
					 t_config *conf);
int			processus_child(int *fd,
					t_ll_node *w,
					t_config *conf);

/*
** EXECUTE_SUBCOMMANDS_H_
*/
int			execute_subcommands(t_ll_list *subcommands,
					    t_config *conf, int *ret);
void			fork_piped(t_ll_node *w, int *fd, t_config *conf);

/*
** EXECUTE_H_
*/
int			execute(char **argv,
				t_config *conf, int *ret);

/*
** MANAGE_CONDITIONS_H_
*/
int			manage_conditions(char *line,
					  t_config *conf, int *ret);

extern char *keywords[];

#endif /* EXECUTION_H_ */
