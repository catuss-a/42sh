/*
** my_getnbr.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:35:46 2010 younes serraj
** Last update Sat Sep 18 14:35:47 2010 younes serraj
*/

#include "my.h"

static char		*prep_str(char *s, int *signe)
{
  *signe = 1;
  while (*s == '+' || *s == '-')
    {
      if (*s == '-')
	*signe *= -1;
      s += 1;
    }
  while (*s == '0')
    s += 1;
  return (s);
}

static int		getnbr(char *s, int nbr_len, int signe)
{
  int			result;
  int			i;

  result = 0;
  i = 0;
  while (i < nbr_len)
    {
      result *= 10;
      result -= (s[i] - '0');
      i += 1;
    }
  if (signe == 1)
    result *= -1;
  return (result);
}

int			my_getnbr(char *s)
{
  int			signe;
  int			nbr_len;

  s = prep_str(s, &signe);
  nbr_len = 0;
  while (s[nbr_len] >= '0' && s[nbr_len] <= '9')
    nbr_len += 1;
  if (nbr_len > 10 || (nbr_len == 10 &&
      ((signe == 1 && my_strncmp(s, "2147483647", 10) > 0) ||
       (signe == -1 && my_strncmp(s, "2147483648", 10) > 0))))
    {
      my_puterr("Error: my_getnbr() reached 'int' limit\n");
      return (0);
    }
  return (getnbr(s, nbr_len, signe));
}
