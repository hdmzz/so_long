NAME	=	so_long
SRCS	=	srcs/main.c srcs/parser/parser.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c so_long.h libft/libft.a Makefile
	$(CC) -I. $< -c -o $@

all:	libft $(NAME)

libft:
		@make -C libft

$(NAME):	$(SRCS:.c=.o) include/so_long.h
			$(CC) -g -I. $(SRCS) libft/libft.a -o $(NAME)

clean:
			rm -drf $(SRCS:.c=.o)
			@make clean -C libft

fclean:	clean
		rm -drf $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:	all libft fclean re
