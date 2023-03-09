ESC		= KEY_ESC=65307
W		= KEY_W=119
A		= KEY_A=97
S		= KEY_S=115
D		= KEY_D=100
UP		= KEY_UP=65362
DOWN	= KEY_DOWN=65364
LEFT	= KEY_LEFT=65361
RIGHT	= KEY_RIG=65363
R		= KEY_R=114
Q		= KEY_Q=113

NAME	=	so_long
SRCS	=	srcs/main.c srcs/parser/parser.c \
			srcs/error/error.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c libft/libft.a Makefile
	$(CC) -I./include $< -c -o $@

all:	libft $(NAME)

libft:
		@make -C libft

$(NAME):	$(SRCS:.c=.o)
			$(CC) -I./include -g $(SRCS) -lmlx -lXext -lX11 libft/libft.a -o $(NAME)

clean:
			rm -drf $(SRCS:.c=.o)
			@make clean -C libft

fclean:	clean
		rm -drf $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:	all libft fclean re
