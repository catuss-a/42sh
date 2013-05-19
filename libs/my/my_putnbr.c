/*
** my_putnbr.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:37:50 2010 younes serraj
** Last update Sun Oct  3 21:05:31 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

static void		my_putnbr_print(int i, int nbr,
					int flag_zeros)
{
  int			n;

  while (i > 1)
    {
      n = nbr / i;
      if (!flag_zeros || n)
	my_putchar((nbr / i) + '0');
      if (flag_zeros && n)
	flag_zeros = 0;
      nbr %= i;
      i /= 10;
    }
  my_putchar((nbr / i) + '0');
}

void			my_putnbr(int nbr)
{
  int			i;
  int			flag_zeros;

  if (nbr < 0 && nbr < -2147483647)
    {
      my_putstr("-2147483648");
      return ;
    }
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  i = 1000000000;
  flag_zeros = 1;
  my_putnbr_print(i, nbr, flag_zeros);
}
