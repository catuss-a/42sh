/*
** termcap.h for 42sh in /home/serraj_y//catuss/42sh/includes
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 15:39:44 2010 younes serraj
** Last update Fri Dec 17 17:01:01 2010 younes serraj
*/

#ifndef TERMCAP_H_
# define TERMCAP_H_

# include <termios.h>
# include "config.h"
# include "tc.h"

typedef struct		s_termcap
{
  int			button;
  int			cursorpos;
  int			col;
  int			li;
  char			*cl;
  char			*ch;
  char			*kr;
  char			*kl;
  char			*kd;
  char			*ku;
  char			*le;
  char			*dc;
  char			*del;
  char			*nd;
  char			*down;
  char			*up;
  char			*kb;
  struct termios        ref_cfg;
  struct termios        cur_cfg;
}			t_termcap;

#endif /* TERMCAP_H_ */
