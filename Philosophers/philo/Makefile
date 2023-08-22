NAME =	philo

PAR =	1 800 200 200
FLAGS =	-Wall -Werror -Wextra

SRCS =	$(shell find . -name '*.c')
FILES =	$(shell find . -name '*.c' -name '*.h')

OBJ =	$(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ)
	@echo "[Removing last version...]"
	@rm -rf philo
	@echo "[philo compilation...]"
	@$(CC) $(SRCS) -o $(NAME) -lpthread
	@echo "[Done!]"
	@$(MAKE) clean

all : $(NAME)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME) $(PAR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all
