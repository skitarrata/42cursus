/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:53:43 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 20:11:29 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_putstr(char *text)
{
	int	i;

	i = -1;
	if (!text)
		exit(0);
	while (text[++i])
		write(1, &text[i], 1);
}

long	*ft_intjoin(t_swap *swap, long const *vet, int dim)
{
	long	*nvet;
	int		i;

	i = 0;
	dim += 1;
	nvet = (long *)ft_calloc(dim, sizeof(long));
	if (!nvet)
		ft_error(swap, ERR);
	while (++i < dim)
		nvet[i] = vet[i - 1];
	return (nvet);
}

long	*ft_intremove(t_swap *swap, long const *vet, int dim)
{
	long	*nvet;
	int		i;

	i = -1;
	dim -= 1;
	nvet = (long *)ft_calloc(dim, sizeof(long));
	if (!nvet)
		ft_error(swap, ERR);
	while (++i < dim)
		nvet[i] = vet[i + 1];
	return (nvet);
}

int	ft_check_order2(t_swap *swap, int n)
{
	if (n == 1 || n == 0)
		return (1);
	if (swap->veta[n - 1] < swap->veta[n - 2])
		return (0);
	return (ft_check_order2(swap, n - 1));
}

void	ft_which_combination(t_swap *swap)
{
	if (ft_check_order2(swap, swap->lena))
	{
		ft_free_swap(swap);
		exit (0);
	}
	if (swap->lena <= 3)
		ft_sort_three(swap);
	else if (swap->lena > 3 && swap->lena < 500)
		ft_sort(swap, 5);
	else if (swap->lena >= 500)
		ft_sort(swap, 11);
}
