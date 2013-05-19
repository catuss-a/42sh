/*
** my_split.c for libmy in /u/all/serraj_y/cu/rendu/lib/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Apr 17 13:19:42 2010 younes serraj
** Last update Wed Dec  8 17:11:50 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

static int	count_words(char *s, char *sep)
{
  int		i;

  i = 0;
  while (*s)
    {
      while (*s && my_findchar(*s, sep) > -1)
	s += 1;
      if (*s)
	{
	  i += 1;
	  while (*s && my_findchar(*s, sep) == -1)
	    s += 1;
	}
    }
  return (i);
}

static int	word_length(char *s, char *sep)
{
  int		i;

  i = 0;
  while (s[i] && my_findchar(s[i], sep) == -1)
    i += 1;
  return (i);
}

char		**my_split(char *s, char *sep)
{
  char		**tab;
  int		nbr_words;
  int		len;
  int		i;

  nbr_words = count_words(s, sep);
  tab = x_malloc(sizeof(char *) * (nbr_words + 1));
  i = 0;
  while (i < nbr_words)
    {
      while (my_findchar(*s, sep) > -1)
	s += 1;
      len = word_length(s, sep);
      tab[i] = x_malloc(sizeof(char) * (len + 1));
      my_strncpy(tab[i], s, len);
      s += len;
      i += 1;
    }
  tab[i] = NULL;
  return (tab);
}
