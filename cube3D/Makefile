NAME			= cub3D
SRCS			= cub3d.c textures.c press_button.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I
LIBS			= /usr/X11/include -g -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${OBJS} ${LIBS}

clean:
				@$(MAKE) -C clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re