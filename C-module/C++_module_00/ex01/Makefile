NAME = phonebook

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror

SRC = phonebook.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all re clean fclean