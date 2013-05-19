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
    my_putchar_err('\a');
  else if (*s == 'b')
    my_putchar_err('\b');
  else if (*s == 'f')
    my_putchar_err('\f');
  else if (*s == 'n')
    my_putchar_err('\n');
  else if (*s == 'r')
    my_putchar_err('\r');
  else if (*s == 't')
    my_putchar_err('\t');
  else if (*s == 'v')
    my_putchar_err('\v');
  else if (*s == '\'' || *s == '\\')
    my_putchar_err(*s);
  else
    {
      my_putchar_err('\\');
      my_putchar_err(*s);
      return (2);
    }
  return (1);
}

static int	print_arg(char *expr, va_list *args)
{
  if (expr[1] == 's')
    my_puterr((char *)va_arg(*args, char *));
  else if (expr[1] == 'd')
    my_putnbr_err((int)va_arg(*args, int));
  else if (expr[1] == 'c')
    my_putchar_err((char)va_arg(*args, int));
  else if (expr[1] == '%')
    my_putchar_err('%');
  return (2);
}

int		my_printf_err(char *s, ...)
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
	my_putchar_err(s[i++]);
    }
  va_end(args);
  return (1);
}
