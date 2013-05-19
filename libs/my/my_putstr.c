/*
** my_putstr.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:42:16 2010 younes serraj
** Last update Sat Sep 18 14:42:17 2010 younes serraj
*/

#include <unistd.h>
#include "my.h"

int			my_putstr(char *s)
{
  return (write(1, s, my_strlen(s)));
}
