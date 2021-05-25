NAME = push_swap
VET = 1 3 5 7

LIBFT = ./libft.a
FLAGS = -Wall -Wextra -Werror

SRCS = 	$(shell find . -name '*.c')
FILES = $(shell find . -name '*.c' -name '*.h')

OBJ = $(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ) $(LIBFT)
	@echo "[Removing last version...]"
	@rm -rf push_swap
	@echo "[push_swap compilation...]"
	@$(MAKE) bonus -C ./libft
	@$(CC) $(SRCS) $(FLAGS) $(LIBFT) -o $(NAME) -g
	@echo "[Done!]"
	@$(MAKE) clean
#-fsanitize=address

$(LIBFT):
	@echo "[compiling libft...]"
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@mv libft/libft.a .

all : $(NAME)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME) $(VET)

run: $(MAKE) re
	@./$(NAME) $(VET)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(NAME) $(LIBFT)
	@$(MAKE) fclean -C ./libft

re : fclean all
