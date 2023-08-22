NAME = minishell

LIBFT = ./libft.a

FLAGS =

SRCS = 	$(shell find . -path ./src/header/minilibx_mms_20200219 -prune -false -o -name '*.c')
FILES = $(shell find . -path ./src/header/minilibx_mms_20200219 -prune -false -o -name '*.c' -o -name '*.h' ! -name 'mlx.h')

OBJ = $(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ) $(LIBFT)
	@echo "[Removing last version...]"
	@rm -rf minishell
	@echo "[minishell compilation...]"
	@$(MAKE) bonus -C ./libft
	@gcc $(SRCS) $(FLAGS) $(LIBFT) -o $(NAME) -g
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
	@leaks --atExit -- ./$(NAME)

run: $(MAKE) re
	@./$(NAME)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(NAME) $(LIBFT) $(MLX)
	@$(MAKE) fclean -C ./libft

re : fclean all
