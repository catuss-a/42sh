/*
** commandline.h for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/struct/headers
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 18:35:34 2010 younes serraj
** Last update Fri Dec 17 17:02:18 2010 younes serraj
*/

#ifndef COMMANDLINE_H_
# define COMMANDLINE_H_

# include "config.h"

int			read_cmdline(t_config *conf);

int			clear_screen_handle(t_config *sh, char *tmpbuf);
void			delete_elem_in_history(t_config *sh);
int			enter_handle(t_config *sh, char *tmpbuf);

int			init_cmdline(t_config *config);
void			init_history(t_config *config);
void			save_history(t_config *conf);
void			display_prompt(t_config *config);

/*
** this func allows to edit the cmdline and manage it.
*/
int			cmdline_editor(t_config *config);

/*
** this func add the new_c at the buf_index in sh->buffer
** and shift the other ones on the right.
*/
void			add_char_in_buffer(t_config *config, char new_c);
void			add_char_and_rightshift_buffer(t_config *config,
						       char new_c,
						       int buf_index);
/*
** display the new buffer from cursor position to the end.
*/
void			putstr_insersion(t_config *config);

/*
** func used for configure terminal.
** ref is the reference termios struct.
*/
void			set_term_cfg(t_config *config);
void			set_term_ref_cfg(t_config *config);

/*
** keyboard handles func.
*/
void			right_arrow_handle(t_config *config);
void			left_arrow_handle(t_config *config);
void			up_arrow_handle(t_config *config);
void			down_arrow_handle(t_config *config);
int			arrows_handles(t_config *config, char *tmpbuf);
int			keyboard_handles(t_config *config, char *tmpbuf);
int			backspace_handle(t_config *sh, char *tmpbuf);
int			delete_handle(t_config *sh, char *tmpbuf);
int			home_handle(t_config *sh, char *tmpbuf);
int			end_handle(t_config *sh, char *tmpbuf);
int			tabulation_handle(t_config *sh, char *tmpbuf);

/*
** mouse handles func.
*/
void			cp_mouse_event(t_config *config, char *tmpbuf);

int			_get_window_sizes(t_config *sh);

#endif /* COMMANDLINE_H_ */
