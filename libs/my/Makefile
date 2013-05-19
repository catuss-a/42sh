##
## Makefile for my in /home/serraj_y//c/corewar/asmx/libs/my
## 
## Made by younes serraj
## Login   <serraj_y@epitech.net>
## 
## Started on  Sat Sep 18 14:43:10 2010 younes serraj
## Last update Tue Dec 14 23:03:34 2010 younes serraj
##

CC		=	gcc
NAME		=	libmy.a

DIR_MY_PRINTF	=	./my_printf

SRCS_DISPLAY	=	my_die.c		\
			my_printf.c		\
			my_printf_err.c		\
			my_putnbr.c		\
			my_putnbr_err.c		\
			my_puterr.c		\
			my_putline.c		\
			my_putstr.c		\
			my_putchar.c

SRCS_STR	=	my_readfile.c		\
			get_next_line.c		\
			my_strdupcat.c		\
			my_make_argv.c		\
			my_strstr.c		\
			my_findchar.c		\
			my_memcpy.c		\
			my_memrev.c		\
			my_memset.c		\
			my_isnum.c		\
			my_strcat.c		\
			my_strncat.c		\
			my_trim.c		\
			my_join.c		\
			my_split.c		\
			my_wt_print.c		\
			my_wt_free.c		\
			my_wt_count.c		\
			my_getnbr.c		\
			my_strcpy.c		\
			my_strncpy.c		\
			my_strcmp.c		\
			my_strncmp.c		\
			my_strdup.c		\
			my_strndup.c		\
			my_strlen.c		\
			my_swap.c

SRCS_X		=	x_malloc.c		\
			check_fd_read.c

SRCS		=	$(SRCS_STR)		\
			$(SRCS_X)		\
			$(SRCS_DISPLAY)

INCLUDES	=	-I$(DIR_MY_PRINTF)	\
			-I.

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-W -Wall -pedantic -ansi -ggdb

RM		=	rm -f
ECHO		=	@echo

$(NAME)		:	$(OBJS)
			ar -r $(NAME) $(OBJS)
			ranlib $(NAME)
			$(ECHO) ""
			$(ECHO) "[SUCCESS]"

all		:	$(NAME)

.c.o		:
			$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
