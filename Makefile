ESC		= KEY_ESC=65307
W		= KEY_W=119
A		= KEY_A=97
S		= KEY_S=115
D		= KEY_D=100
UP		= KEY_UP=65362
DOWN	= KEY_DOWN=65364
LEFT	= KEY_LEFT=65361
RIGHT	= KEY_RIGHT=65363
R		= KEY_R=114
Q		= KEY_Q=113

NAME	=	so_long

SRCS	=	srcs/main.c srcs/parser/parser.c \
			srcs/error/error.c \
			srcs/utils.c \
			srcs/move.c \
			srcs/legal_move.c \
			srcs/parser/pathfinder.c \
			srcs/game.c

CC		= gcc


%.o: %.c libft/libft.a  minilibx-linux/libmlx.a Makefile
	$(CC) -c $< -o $@

all:	libft $(NAME)

libft:
		@if [ ! -d libft ]; then \
			git clone https://github.com/hdmzz/libft.git; \
		fi
		@make -C libft

minilib:
		@make -C minilibx-linux

$(NAME):	$(SRCS:.c=.o)
			$(CC) -g $(SRCS) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			rm -drf $(SRCS:.c=.o)
			@make clean -C libft

fclean:	clean
		rm -drf $(NAME)
		@make fclean -C libft
		@make fclean -C mlx_linux

re:		fclean all

.PHONY:	all libft fclean re
