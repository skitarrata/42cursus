NAME		= libftprintf.a
CC			= gcc
LIBFT		= libft/libft.a

SRCS		= ft_printf_check.c \
			  ft_printf_utils.c \
			  ft_printf_mixcheck.c \
			  ft_print_str.c \
			  ft_print_char.c \
			  ft_printable.c \
			  ft_printf.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra -c

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $^

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
