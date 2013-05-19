/*
** my_printf.c for my_printf in /u/all/serraj_y/cu/rendu/c/my_printf
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Apr 12 13:07:01 2010 younes serraj
** Last update Fri Jul  2 16:20:20 2010 younes serraj
*/

#include <stdarg.h>
#include "my.h"

static int	print_escaped_char(char *s)
{
  if (*s == '\a')
    my_putchar('\a');
  else if (*s == 'b')
    my_putchar('\b');
  else if (*s == 'f')
    my_putchar('\f');
  else if (*s == 'n')
    my_putchar('\n');
  else if (*s == 'r')
    my_putchar('\r');
  else if (*s == 't')
    my_putchar('\t');
  else if (*s == 'v')
    my_putchar('\v');
  else if (*s == '\'' || *s == '\\')
    my_putchar(*s);
  else
    {
      my_putchar('\\');
      my_putchar(*s);
      return (2);
    }
  return (1);
}

static int	print_arg(char *expr, va_list *args)
{
  if (expr[1] == 's')
    my_putstr((char *)va_arg(*args, char *));
  else if (expr[1] == 'd')
    my_putnbr((int)va_arg(*args, int));
  else if (expr[1] == 'c')
    my_putchar((char)va_arg(*args, int));
  else if (expr[1] == '%')
    my_putchar('%');
  return (2);
}

int		my_printf(char *s, ...)
{
  va_list	args;
  int		i;

  va_start(args, s);
  i = 0;
  while (s[i])
    {
      if (s[i] == '\\')
	i += print_escaped_char(s + i + 1);
      else if (s[i] == '%')
	i += print_arg(s + i, &args);
      else
	my_putchar(s[i++]);
    }
  va_end(args);
  return (1);
}
