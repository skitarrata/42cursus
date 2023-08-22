NAME1 = server
NAME2 = client

all :
	gcc -Wall -Wextra -Werror server.c utils.c -o $(NAME1)
	gcc -Wall -Wextra -Werror client.c utils.c -o $(NAME2)

clean :
	rm -rf client.o server.o utils.o

fclean : clean
	rm -rf $(NAME1) $(NAME2)

re : fclean all
