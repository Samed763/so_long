NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext
GNLDIR = ./get_next_line
SRCS = $(GNLDIR)/get_next_line.c $(GNLDIR)/get_next_line_utils.c main.c set_values.c \
    utils_one.c utils_two.c utils_three.c find_things.c free_all.c check_map.c \
    render_utils.c movement_utils.c
OBJS = $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)

clean:
	rm -f $(OBJS)

fclean: clean
	@make clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
