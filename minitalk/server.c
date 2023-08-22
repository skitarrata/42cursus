#include "minitalk.h"

static t_serv	serv;

void	ft_bit_char(int bit)
{
	int	i;
	//printf("%d\n", bit);
	if (SIGUSR2 == bit)
		i = 1;
	else
		i = 0;
	serv.c += ((i & 1) << serv.len);
	serv.len++;
	if (serv.len == 7)
	{
		ft_putchar(serv.c);
		if (!serv.c)
			ft_putchar('\n');
		serv.c = 0;
		serv.len = 0;
	}
}

int	main(void)
{
	serv.c = 0;
	serv.len = 0;
	ft_putstr("server pid :");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, ft_bit_char);
		signal(SIGUSR2, ft_bit_char);
		pause();
	}
}