##
## Makefile for ll in /home/serraj_y//c/corewar/asmx/libs/ll
## 
## Made by younes serraj
## Login   <serraj_y@epitech.net>
## 
## Started on  Sat Sep 18 14:47:13 2010 younes serraj
## Last update Wed Dec  8 13:07:48 2010 younes serraj
##

CC		=	gcc
NAME		=	libll.a

SRCS		=	ll_sort.c			\
			ll_get_node_id.c		\
			ll_find_data.c			\
			ll_traverse.c			\
			ll_traverse_using_filter.c	\
			ll_clear_list.c			\
			ll_delete_node.c		\
			ll_pop_data.c			\
			ll_pop_node.c			\
			ll_pop.c			\
			ll_push_data.c			\
			ll_push_node.c			\
			ll_push.c			\
			ll_get_node.c			\
			ll_make_node.c			\
			ll_make_list.c			\
			ll_init_list.c

OBJS		=	$(SRCS:.c=.o)

CLFLAGS		+=	-W -Wall -pedantic -ansi

RM		=	rm -f

$(NAME)		:	$(OBJS)
			ar -r $(NAME) $(OBJS)
			ranlib $(NAME)

all		:	$(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
