/*
** my_make_argv.c for my in /u/all/serraj_y/rendu/c/proj/42sh/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Dec  3 19:53:00 2010 younes serraj
** Last update Sat Dec 18 23:19:18 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

static int	get_escaped_char(char c)
{
  if (c == 'a')
    return ('\a');
  else if (c == 'b')
    return ('\b');
  else if (c == 'f')
    return ('\f');
  else if (c == 'n')
    return ('\n');
  else if (c == 'r')
    return ('\r');
  else if (c == 't')
    return ('\t');
  else if (c == 'v')
    return ('\v');
  else if (c == '\'' || c == '\\')
    return (c);
  else
      return (c);
}

static int		get_arg_len(char *s)
{
  int			i;
  char			c;

  if (!*s)
    return (0);
  i = 0;
  if (IS_INHIBITOR(s[i]))
    {
      c = s[i++];
      while (s[i] && s[i] != c)
	{
	  if (s[i] == '\\' && !s[++i])
	    return (-1);
	  i += 1;
	}
      return (s[i] == c ? ++i : -1);
    }
  while (s[i] && !IS_SEPARATOR(s[i]))
    {
      if (s[i] == '\\' && !s[++i])
	return (-1);
      i += 1;
    }
  return (i);
}

static int		get_argc(char *s)
{
  int			i;
  int			skip;

  i = 0;
  do
    {
      while (*s && IS_SEPARATOR(*s))
	s += 1;
      skip = get_arg_len(s);
      s += skip;
      i += (skip > 0 ? 1 : 0);
    }
  while (skip > 0);
  return (skip == 0 ? i : -1);
}

static void		_epur_str(char *s)
{
  if (IS_INHIBITOR(*s))
    {
      s[my_strlen(s) - 1] = 0;
      my_strcpy(s, s + 1);
    }
  while (*s)
    {
      if (*s == '\\')
	{
	  my_strcpy(s, s + 1);
	  *s = get_escaped_char(*s);
	}
      s += 1;
    }
}

char			**my_make_argv(char *s, char call_epurstr)
{
  char			**argv;
  int			argc;
  int			i;
  int			arg_len;

  if ((argc = get_argc(s)) == -1)
    return (NULL);
  argv = x_malloc(sizeof(char *) * (argc + 1));
  i = 0;
  while (i < argc)
    {
      while (*s && IS_SEPARATOR(*s))
	s += 1;
      arg_len = get_arg_len(s);
      argv[i] = my_strndup(s, arg_len);
      if (call_epurstr)
	_epur_str(argv[i]);
      s += arg_len;
      i += 1;
    }
  argv[i] = NULL;
  return (argv);
}
