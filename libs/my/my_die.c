/*
** my_die.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Wed Sep  1 15:34:15 2010 younes serraj
** Last update Wed Sep 15 22:18:25 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

void			my_die(char *msg, int retcode)
{
  my_printf_err(msg);
  exit(retcode);
}
