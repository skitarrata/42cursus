NAME = Account

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRC = Account.cpp \
		tests.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


.cpp.o:
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all re clean fclean