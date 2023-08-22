#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

typedef struct	s_serv
{
	char	c;
	int		len;
}				t_serv;

void	ft_putchar(int c);
void	ft_putstr(char *text);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_putnbr(int nb);
size_t	ft_strlen(const char *s);
void	ft_error(char *text);

#endif