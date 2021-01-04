NAME	=	minishell

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./Libft/libft.a

INC		= -I ./includes

SRCS	=	main.c	\
			./src/utils/get_next_line.c	\
			./src/utils/get_next_line_utils.c \
			./src/utils/handler.c \
			./src/utils/utils.c \
			./src/env/init_env.c \
			./src/env/lstenv.c \
			./src/parse/read_line.c \
			./src/parse/lexer.c \
			./src/parse/lexer2.c \
			./src/parse/init_cmd.c \
			./src/parse/lstcmd.c \
			./src/parse/parser.c \
			./src/parse/lst_rdir.c \
			./src/utils/quit.c \
			./src/utils/free.c \
			./src/utils/error_1.c \

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