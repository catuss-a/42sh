/*
** my_putline.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Thu Sep 16 16:30:58 2010 younes serraj
** Last update Wed Dec  8 16:25:51 2010 younes serraj
*/

#include <unistd.h>
#include "my.h"

int			my_putline(char *s)
{
  int			i;

  if (!s)
    return (-1);
  i = 0;
  while (s[i] && s[i] != '\n')
    i += 1;
  write(1, s, i);
  my_putchar('\n');
  return (0);
}

int			my_putline_err(char *s)
{
  int			i;

  if (!s)
    return (-1);
  i = 0;
  while (s[i] && s[i] != '\n')
    i += 1;
  write(2, s, i);
  my_putchar_err('\n');
  return (0);
}
