/*
** my_strdupcat.c for my in /u/all/serraj_y/rendu/c/proj/42sh/struct/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 16:56:30 2010 younes serraj
** Last update Tue Dec  7 17:00:03 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"

char			*my_strdupcat(char *s1, char *s2)
{
  char			*buffer;

  buffer = x_malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
  my_strcpy(buffer, s1);
  my_strcat(buffer, s2);
  return (buffer);
}
