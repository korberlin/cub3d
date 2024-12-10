NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

SRCS = src/main.c src/free.c src/parser/parse.c src/init.c src/error.c src/hook.c \
		src/loop.c src/minimap.c src/utils.c src/raycast.c src/raycast_utils.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		src/parser/extract.c src/parser/parse_utils.c src/parser/texture.c src/parser/extract_utils.c\
		src/parser/validate.c src/parser/validate_utils.c src/parser/flood_fill.c \

LIBFT_PATH = libft/

LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

OBJ_DIR = obj

COMPILE_FLAGS = -I/usr/include -I$(MLX_PATH) -I$(LIBFT_PATH) -Ignl -O3

LINK_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJECTS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: libraries $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $< -o $@
libraries:
	@echo Compiling libraries...
	make -C $(MLX_PATH) all
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINK_FLAGS) -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libraries
