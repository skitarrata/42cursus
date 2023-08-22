/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:23:15 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 18:55:05 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_check_num(t_swap *swap, char *argv)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(argv);
	if (!len)
		ft_error(swap, ERR);
	while (argv[++i])
	{
		if ((argv[i] < 48 || argv[i] > 57)
			&& (argv[i] != ' ' && argv[i] != '-' && argv[i] != '+'))
			ft_error(swap, ERR);
		if ((argv[i] == '-' || argv[i] == '+')
			&& (argv[i + 1] == ' ' || !argv[i + 1]))
			ft_error(swap, ERR);
		if ((argv[i] >= 48 && argv[i] <= 57)
			&& (argv[i + 1] == '-' || argv[i + 1] == '+'))
			ft_error(swap, ERR);
	}
}

void	ft_check_double(t_swap *swap)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= swap->lena)
	{
		j = i;
		while (++j < swap->lena)
			if (swap->veta[i] == swap->veta[j])
				ft_error(swap, ERR);
	}
}

void	ft_check_int(t_swap *swap)
{
	int	i;

	i = -1;
	while (++i < swap->lena)
	{
		if (swap->veta[i] > 2147483647)
			ft_error(swap, ERR);
		else if (swap->veta[i] < -2147483648)
			ft_error(swap, ERR);
	}
}

int	ft_check_order(t_swap *swap, int b)
{
	int	i;

	i = -1 + b;
	while (++i < swap->lena - 1)
		if (swap->veta[i] > swap->veta[i + 1])
			return (1);
	return (0);
}

int	ft_check_three(long *vet, int dim)
{
	int	i;

	i = dim;
	if (vet[0] > vet[1] || vet[1] > vet[i - 1])
		return (1);
	return (0);
}
