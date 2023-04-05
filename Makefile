O		= objs/
S		= srcs/

NAME	=	so_long

SRC	=	srcs/main.c srcs/parser/parser.c \
			srcs/parser/parser2.c \
			srcs/parser/pathfinder.c \
			srcs/parser/pathfinder_collectibles.c \
			srcs/error/error.c \
			srcs/utils.c \
			srcs/move.c \
			srcs/legal_move.c \
			srcs/game.c

OBJ = $(SRC:$S%=$O%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBFLAGS =  libft/libft.a -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.PHONY:	all libft fclean re

all:	minilibx libft $(NAME)

$O:
	@mkdir -p $@
	@mkdir -p $@parser
	@mkdir -p $@error

$(OBJ): | $O

$(OBJ): $O%.o: $S% Makefile include/so_long.h
	$(CC) -g3 $(CFLAGS) -c $< -o $@
$D:
	@mkdir $@
	@mkdir -p $@parser
	@mkdir -p $@error

$(DEP): | $D

$(DEP): $D%.d: $S%
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CC) $^ $(LIBFLAGS) -o $@

minilibx:
	@if [ ! -d minilibx-linux ]; then \
		git clone git@github.com:42Paris/minilibx-linux.git; \
	fi
	@make -C minilibx-linux

libft:
	@if [ ! -d libft ]; then \
		git clone https://github.com/hdmzz/libft.git; \
	fi
	@make -C libft

clean:
	rm -drf $(wildcard $(OBJ))
	@make clean -C libft

fclean:	clean
	rm -drf $(NAME)
	@make fclean -C libft
	@make fclean -C minilibx-linux

re:	fclean all  

