SRCS = src/main.c src/utils.c src/map_proc/valid.c src/map_proc/arg_check.c src/map_proc/init_map.c src/map_proc/init_xpm.c src/map_proc/map_check.c src/map_proc/print_map.c src/map_proc/movement.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF_PATH = ./printf
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

MLX = $(MLX_PATH)/libmlx.a
MLX_PATH = ./Mlx

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iincludes
LINKS = -framework OpenGL -framework AppKit

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LINKS) -o $(NAME) $(LIBFTPRINTF) $(MLX)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFTPRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re