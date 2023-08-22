#include "minitalk.h"

void	ft_send_bit(int pid, char *str, size_t len)
{
	int	shf;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shf = 0;
		while (shf < 7)
		{
			if ((str[i] >> shf) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shf++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	size_t	len;
	int	pid;

	if (argc != 3)
		ft_error("arguments error\n");
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	ft_send_bit(pid, argv[2], len);
	ft_error("the end\n");
}