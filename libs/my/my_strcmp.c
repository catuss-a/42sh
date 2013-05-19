/*
** my_strcmp.c for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sat Sep 18 14:40:37 2010 younes serraj
** Last update Sat Sep 18 14:40:38 2010 younes serraj
*/

#include "my.h"

int			my_strcmp(char *s1, char *s2)
{
  while (*s1 && *s1 == *s2)
    {
      s1 += 1;
      s2 += 1;
    }
  return (*s1 - *s2);
}
