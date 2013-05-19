##
## Makefile for my in /home/serraj_y//c/corewar/asmx/libs/my
## 
## Made by younes serraj
## Login   <serraj_y@epitech.net>
## 
## Started on  Sat Sep 18 14:43:10 2010 younes serraj
## Last update Wed Sep 22 23:30:44 2010 younes serraj
##

CC		=	gcc
NAME		=	libtc.a

DIR_MY		=	./../my

SRCS		=	tc_init_ioctl.c			\
			tc_checkup.c			\
			tc.c				\
			x_tgoto.c			\
			x_tgetstr.c			\
			x_getenv_term.c			\
			tc_get_window_size.c		\
			tc_init_window_manager.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	-I$(DIR_MY)			\
			-I.

LDFLAGS		=	-L$(DIR_MY) -lmy

CFLAGS		+=	-W -Wall -pedantic -ansi

RM		=	rm -f
ECHO		=	@echo

$(NAME)		:	$(OBJS)
			ar -r $(NAME) $(OBJS)
			ranlib $(NAME)
			$(ECHO) ""
			$(ECHO) "[SUCCESS]"

all		:	$(NAME)

.c.o		:
			$(CC) $(LDFLAGS) $(INCLUDES) $(CFLAGS) -c -o $@ $<

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
