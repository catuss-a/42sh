/*
** cmdline.h for 42sh in /home/serraj_y//catuss/42sh/includes
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 15:38:09 2010 younes serraj
** Last update Fri Dec 17 17:35:15 2010 younes serraj
*/

#ifndef CMDLINE_H_
# define CMDLINE_H_

# include "color.h"
# include "termcap.h"

# define		SUCCESS		0
# define		FAIL		-1
# define		TRUE		1
# define		FALSE		0
# define		ON		1
# define		OFF		0

# define		KEY_ENTER	"\n"
# define                END_OF_LINE     0
# define                BEGING_OF_LINE  1

# define		BUFF_SIZE	4048
# define		SDT_IN		0
# define		HISTORY_FILE	"./.history"

# define		XTERM_NOAPP	"xterm-noapp"

# define		IS_PRINT(x)	((x) > 31 && (x) < 127)

typedef struct		s_history
{
  char			*data;
  struct s_history	*next;
  struct s_history	*prev;
}			t_history;

typedef struct		s_prompt
{
  char			*str;
  int			length;
  char			*color;
}			t_prompt;

typedef struct		s_cmdline
{
  char			buffer[BUFF_SIZE + 1];
  struct s_prompt	prompt;
  struct s_termcap	tmc;
  struct s_history	*history;
  char			history_flag;
  char			resize;
}			t_cmdline;

#endif /* CMDLINE_H_ */
