/*
** my_strcat.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:42:43 2010 younes serraj
** Last update Sat Sep 18 14:42:44 2010 younes serraj
*/

#include "my.h"

int			my_strcat(char *dest, char *s)
{
  int			i;

  i = my_strlen(dest);
  my_strcpy(dest + i, s);
  return (0);
}
