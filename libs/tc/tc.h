/*
** tc.h for my_select in /u/all/serraj_y/cu/rendu/c/my_select/tc
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Jul  2 16:58:52 2010 younes serraj
** Last update Wed Dec  8 13:24:48 2010 younes serraj
*/

#ifndef TC_H_
# define TC_H_

# ifndef TIOCGETA
#  define TIOCGETA TCGETS
# endif /* TIOCGETA */

# ifndef TIOCSETA
#  define TIOCSETA TCSETS
# endif /* TIOCSETA */

# define TC_BUFFER_SIZE		4096

# define TC_CLEAR_SCREEN()		tc("cl")
# define TC_GOTO(x, y)			x_tgoto((x), (y))
# define TC_STANDOUT_MODE_ON()		tc("so")
# define TC_STANDOUT_MODE_OFF()		tc("se")
# define TC_UNDERLINE_MODE_ON()		tc("us")
# define TC_UNDERLINE_MODE_OFF()	tc("ue")
# define TC_BOLD_MODE_ON()		tc("md")
# define TC_BOLD_MODE_OFF()		tc("me")
# define TC_SHOW_CURSOR()		tc("ve")
# define TC_HIDE_CURSOR()		tc("vi")

char			*x_getenv_term();
char			*x_tgetstr(char *cap, char **area);
int			x_tgoto(int col, int row);
int			tc(char *cmd);
int			tc_checkup();
int			tc_init_ioctl();
int			tc_restore_ioctl();
int			tc_init_window_manager();
int			tc_get_window_size(int *col, int *row);

#endif /* TC_H_ */
