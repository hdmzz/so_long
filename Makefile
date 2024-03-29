O = objs/
S = src/

NAME =	so_long

SRC =	$Smain.c $Sparser/parser.c \
			$Sparser/parser2.c \
			$Sparser/parser3.c \
			$Sparser/map_playable.c \
			$Serror/error.c \
			$Sutils.c \
			$Smove.c \
			$Slegal_move.c \
			$Sgame.c

OBJ = $(SRC:$S%=$O%.o)

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS =  libft/libft.a minilibx-linux/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.PHONY: all libft fclean re

all: minilibx libft $(NAME)

$O:
	@mkdir -p $@
	@mkdir -p $@parser
	@mkdir -p $@error

$(OBJ): | $O

$(OBJ): $O%.o: $S% Makefile include/so_long.h libft/libft.a
	$(CC) -g3 $(CFLAGS) -c $< -o $@

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

$(NAME): $(OBJ)
	$(CC) $^ $(LIBFLAGS) -o $@

clean:
	rm -rf $(SRC:$S%=$O%.o)
	rm -rf $(SRC:$S%=$D%.d)
	@make clean -C libft

fclean:	clean
	rm -rf $(NAME)
	rm -rf $O
	rm -rf $D
	@make fclean -C libft

re:	fclean all  
