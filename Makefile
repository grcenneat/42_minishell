NAME	=	minishell

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./Libft/libft.a

INC	=	-I./includes

SRCS	=	main.c	\
	./get_next_line/get_next_line.c	\
	./get_next_line/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC)	-o	$(NAME)	$(SRCS)	$(LIBFT)	$(INC)	$(CFLAGS)

$(LIBFT)	:
	$(MAKE)	-s	-C	./Libft
	$(MAKE)	clean	-C	./Libft

clean:
	rm	-f	$(OBJS)

fclean:	clean
	rm	-f	$(NAME)
	rm -f	$(LIBFT)

re:	fclean	all

.PHONY:	all	clean	fclean	re