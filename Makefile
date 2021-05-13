NAME = cub3D
MAP = maps/big.cu

LIBFT = ./libft.a
MLX = libmlx.dylib

FLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

SRCS = 	$(shell find . -path ./src/header/minilibx_mms_20200219 -prune -false -o -name '*.c')
FILES = $(shell find . -path ./src/header/minilibx_mms_20200219 -prune -false -o -name '*.c' -o -name '*.h' ! -name 'mlx.h')

OBJ = $(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	@echo "[Removing last version...]"
	@rm -rf Cub3D
	@echo "[Cub3D compilation...]"
	@$(MAKE) bonus -C ./libft
	@gcc $(SRCS) $(FLAGS) $(MLX)  $(LIBFT) -o $(NAME) -g
	@echo "[Done!]"
	@$(MAKE) clean
#-fsanitize=address

$(LIBFT):
	@echo "[compiling libft...]"
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@mv libft/libft.a .

$(MLX):
	@echo "[compiling mlx...]"
	@$(MAKE) -C src/header/minilibx_mms_20200219
	@mv src/header/minilibx_mms_20200219/libmlx.dylib .

all : $(NAME)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME) $(MAP)

run: $(MAKE) re
	@./$(NAME) $(MAP)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(NAME) $(LIBFT) $(MLX)
	@$(MAKE) fclean -C ./libft

re : fclean all
