/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:46:57 by grusso            #+#    #+#             */
/*   Updated: 2021/10/16 15:03:34 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

long int	ft_time(void)
{
	struct timeval	sec;

	gettimeofday(&sec, NULL);
	return (sec.tv_sec * 1000 + sec.tv_usec / 1000);
}

void	ft_usleep(int length)
{
	long int	time;

	time = ft_time();
	while (ft_time() < time + length)
		usleep(length);
}

void	ft_print(t_rules *rules, int phil, char *str)
{
	long int	nb;

	nb = ft_time() - rules->start;
	if (!rules->dieded)
		printf("%ld           philosopher %d: %s\n", nb, phil, str);
}
