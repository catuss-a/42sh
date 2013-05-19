##
## Makefile for minishell2 in /home/serraj_y//c/minishell2
## 
## Made by younes serraj
## Login   <serraj_y@epitech.net>
## 
## Started on  Sat Sep 18 18:26:51 2010 younes serraj
## Last update Sun Dec 19 23:17:23 2010 younes serraj
##

CC		=	gcc
NAME		=	42sh

########################
## --------------------|
########################

## 
## DIRECTORIES
## 

DIR_LIBS		=	./libs

DIR_BUILTINS		=	./builtins
DIR_COMMANDLINE		=	./commandline
DIR_EXECUTION		=	./execution
DIR_HEADERS		=	./headers
DIR_INITIALIZATION	=	./initialization
DIR_MEMORY		=	./memory
DIR_JOB_CONTROL         =       ./job_control

##
## SOURCE CODE
##

SRCS_BUILTINS		=	$(DIR_BUILTINS)/builtins.c			\
				$(DIR_BUILTINS)/history.c			\
				$(DIR_BUILTINS)/cd.c				\
				$(DIR_BUILTINS)/cd_utils.c			\
				$(DIR_BUILTINS)/unset.c				\
				$(DIR_BUILTINS)/set.c				\
				$(DIR_BUILTINS)/unsetenv.c			\
				$(DIR_BUILTINS)/setenv.c			\
				$(DIR_BUILTINS)/env.c				\
				$(DIR_BUILTINS)/echo.c				\
				$(DIR_BUILTINS)/jobs.c				\
				$(DIR_BUILTINS)/fg.c				\
				$(DIR_BUILTINS)/bg.c				\
				$(DIR_BUILTINS)/exit.c

SRCS_COMMANDLINE	=	$(DIR_COMMANDLINE)/save_history.c			\
				$(DIR_COMMANDLINE)/add_char_and_rightshift_buffer.c	\
				$(DIR_COMMANDLINE)/add_char_in_buffer.c			\
				$(DIR_COMMANDLINE)/arrows_handles.c			\
				$(DIR_COMMANDLINE)/backspace_handles.c			\
				$(DIR_COMMANDLINE)/delete_elem_in_history.c		\
				$(DIR_COMMANDLINE)/enter_handle.c			\
				$(DIR_COMMANDLINE)/home_handle.c			\
				$(DIR_COMMANDLINE)/end_handle.c				\
				$(DIR_COMMANDLINE)/clear_screen_handle.c		\
				$(DIR_COMMANDLINE)/delete_handles.c			\
				$(DIR_COMMANDLINE)/cmdline_editor.c			\
				$(DIR_COMMANDLINE)/cp_mouse_event.c			\
				$(DIR_COMMANDLINE)/display_prompt.c			\
				$(DIR_COMMANDLINE)/keyboard_handles.c			\
				$(DIR_COMMANDLINE)/left_and_right_arrows_handles.c	\
				$(DIR_COMMANDLINE)/putstr_insersion.c			\
				$(DIR_COMMANDLINE)/read_cmdline.c			\
				$(DIR_COMMANDLINE)/set_term_cfg.c			\
				$(DIR_COMMANDLINE)/up_and_down_arrows_handles.c

SRCS_EXECUTION		=	$(DIR_EXECUTION)/shell.c			\
				$(DIR_EXECUTION)/commandline_rewrite.c		\
				$(DIR_EXECUTION)/commandline_rewrite_utils.c	\
				$(DIR_EXECUTION)/keywords.c			\
				$(DIR_EXECUTION)/get_globing.c			\
				$(DIR_EXECUTION)/get_binary_path.c		\
				$(DIR_EXECUTION)/is_valid_command.c		\
				$(DIR_EXECUTION)/split_commands.c		\
				$(DIR_EXECUTION)/query_out.c			\
				$(DIR_EXECUTION)/manage_conditions.c		\
				$(DIR_EXECUTION)/execute.c			\
				$(DIR_EXECUTION)/execute_subcommands.c		\
				$(DIR_EXECUTION)/processus.c			\
				$(DIR_EXECUTION)/make_exec_info.c		\
				$(DIR_EXECUTION)/extract_redirections_in.c	\
				$(DIR_EXECUTION)/extract_redirections_out.c	\
				$(DIR_EXECUTION)/clean_from_redirections.c	\
				$(DIR_EXECUTION)/check_binary_access.c		\
				$(DIR_EXECUTION)/signals.c

SRCS_INITIALISATION	=	$(DIR_INITIALIZATION)/config.c			\
				$(DIR_INITIALIZATION)/init_cmdline.c		\
				$(DIR_INITIALIZATION)/init_termcap.c		\
				$(DIR_INITIALIZATION)/init_history.c		\
				$(DIR_INITIALIZATION)/user.c			\
				$(DIR_INITIALIZATION)/load_env.c

SRCS_MEMORY		=	$(DIR_MEMORY)/mem_make_environ.c		\
				$(DIR_MEMORY)/memory.c				\
				$(DIR_MEMORY)/var.c

SRCS_JOB_CONTROL        =       $(DIR_JOB_CONTROL)/add_job.c                    \
				$(DIR_JOB_CONTROL)/delete_job.c                 \
				$(DIR_JOB_CONTROL)/fill_job.c                   \
				$(DIR_JOB_CONTROL)/add_process.c                \
				$(DIR_JOB_CONTROL)/check_status.c               \
				$(DIR_JOB_CONTROL)/put_job_in_foreground.c      \
				$(DIR_JOB_CONTROL)/update_last_use.c		\
				$(DIR_JOB_CONTROL)/stop_job.c                   \
				$(DIR_JOB_CONTROL)/continue_job.c

SRCS			=	main.c				\
				$(SRCS_MEMORY)			\
				$(SRCS_EXECUTION)		\
				$(SRCS_BUILTINS)		\
				$(SRCS_JOB_CONTROL)		\
				$(SRCS_COMMANDLINE)		\
				$(SRCS_INITIALISATION)

##
## OBJECT FILES
##

OBJS			=	$(SRCS:.c=.o)

##
## INCLUDES
##

INCLUDES		=	-I$(DIR_LIBS)/my		\
				-I$(DIR_LIBS)/ll		\
				-I$(DIR_LIBS)/tc		\
				-I$(DIR_HEADERS)		\
				-I.

##
## LIBRARIES
##

LDFLAGS			=	-L$(DIR_LIBS)/tc		\
				-L$(DIR_LIBS)/my		\
				-L$(DIR_LIBS)/ll		\
				-ltc				\
				-lll				\
				-lmy				\
				-ltermcap

##
## COMPILATIONS FLAGS
##

CFLAGS			+=	-W -Wall -pedantic -ansi

##
## ALIASES
##

MAKE			=	make
MAKE_ERR		=	make re > /dev/null
RM			=	rm -f
ECHO			=	@echo


########################
## --------------------|
########################

$(NAME)		:	libs $(OBJS)
			$(CC) $(INCLUDES) -o $(NAME) $(OBJS) $(LDFLAGS)
			$(ECHO) ""
			$(ECHO) "[SUCCESS]"

all		:	$(NAME)

err		:
			$(MAKE_ERR)

libs		:
			@cd $(DIR_LIBS)/my && $(MAKE) -f Makefile
			@cd $(DIR_LIBS)/ll && $(MAKE) -f Makefile
			@cd $(DIR_LIBS)/tc && $(MAKE) -f Makefile

libs_clean	:
			@cd $(DIR_LIBS)/my && $(MAKE) clean -f Makefile
			@cd $(DIR_LIBS)/ll && $(MAKE) clean -f Makefile
			@cd $(DIR_LIBS)/tc && $(MAKE) clean -f Makefile

libs_fclean	:
			@cd $(DIR_LIBS)/my && $(MAKE) fclean -f Makefile
			@cd $(DIR_LIBS)/ll && $(MAKE) fclean -f Makefile
			@cd $(DIR_LIBS)/tc && $(MAKE) fclean -f Makefile

libs_re		:
			@cd $(DIR_LIBS)/my && $(MAKE) re -f Makefile
			@cd $(DIR_LIBS)/ll && $(MAKE) re -f Makefile
			@cd $(DIR_LIBS)/tc && $(MAKE) re -f Makefile

.c.o		:
			$(CC) $(INCLUDES) -c -o $@ $< $(CFLAGS)

clean		:	libs_clean
			$(RM) $(OBJS)

fclean		:	libs_fclean clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all .c.o clean fclean re libs libs_clean libs_fclean libs_re

########################
## --------------------|
########################
