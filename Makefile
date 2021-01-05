NAME	=	minishell

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./Libft/libft.a

INC		= 	-I ./includes

SRCS	=	./src/main.c \
			./src/utils/get_next_line.c	\
			./src/utils/get_next_line_utils.c \
			./src/utils/handler.c \
			./src/utils/utils.c \
			./src/env/init_env.c \
			./src/env/lstenv.c \
			./src/parse/read_line.c \
			./src/parse/lexer.c \
			./src/parse/lexer_2.c \
			./src/parse/init_cmd.c \
			./src/parse/lstcmd.c \
			./src/parse/parser.c \
			./src/parse/lst_rdir.c \
			./src/run/exec_command.c \
			./src/run/pipe_1.c \
			./src/run/pipe_2.c \
			./src/run/dollar_quotes.c \
			./src/run/check_rdir_dollar.c \
			./src/run/redirection.c \
			./src/run/exec_echo.c \
			./src/run/exec_cd.c \
			./src/run/exec_pwd.c \
			./src/run/exec_export.c \
			./src/run/exec_unset.c \
			./src/run/exec_env.c \
			./src/run/exec_exit.c \
			./src/run/exec_non_btin.c \
			./src/utils/quit.c \
			./src/utils/free_1.c \
			./src/utils/free_2.c \
			./src/utils/error_1.c \
			./src/utils/error_2.c \

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE)	-s	-C	./Libft

clean:
	rm	-f	$(OBJS)
	$(MAKE)	clean	-C	./Libft

fclean:	clean
	rm	-f	$(NAME)
	rm -f	$(LIBFT)

re:	fclean	all

.PHONY:	all	clean	fclean	re