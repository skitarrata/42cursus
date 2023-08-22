#include "minitalk.h"

void	ft_error(char *text)
{
	ft_putstr(text);
	exit(0);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *text)
{
	int i;

	i = -1;
	if (!text)
		exit(0);
	while (text[++i])
		write(1, &text[i], 1);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i++] - '0'));
		if (res > 2147483648)
			break ;
	}
	if ((res == 2147483648 && s == -1) || res <= 2147483648)
		return (res * s);
	return (s == 1 ? -1 : 0);
}

void	ft_putnbr(int nb)
{
	char		arr[12];
	int			c;
	long	int	nbim;

	c = 0;
	nbim = nb;
	if (nbim == 0)
		ft_putchar('0');
	if (nbim < 0)
	{
		ft_putchar('-');
		nbim *= (-1);
	}
	while (nbim != 0)
	{
		arr[c] = ((nbim % 10) + '0');
		nbim /= 10;
		c++;
	}
	while ((c - 1) >= 0)
	{
		ft_putchar(arr[c - 1]);
		c--;
	}
}
