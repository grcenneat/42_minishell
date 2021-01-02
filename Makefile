NAME	=	minishell

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./Libft/libft.a

INC	=	-I./includes/

SRCS	=	main.c	\
	./src/get_next_line.c	\
	./src/utils/get_next_line_utils.c \
	./src/utils/handler.c \

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC)	-o	$(NAME)	$(SRCS)	$(LIBFT)	$(INC)	$(CFLAGS)

$(LIBFT)	:
	$(MAKE)	-s	-C	./Libft

clean:
	rm	-f	$(OBJS)
	$(MAKE)	clean	-C	./Libft

fclean:	clean
	rm	-f	$(NAME)
	rm -f	$(LIBFT)

re:	fclean	all

.PHONY:	all	clean	fclean	re