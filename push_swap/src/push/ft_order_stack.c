/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:54:33 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 17:38:10 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_bring_back(t_swap *swap)
{
	int		half_len;
	int		i;
	long	check;

	i = -1;
	half_len = swap->lenb / 2;
	check = ft_find_max(swap);
	while (++i < swap->lenb)
		if (swap->vetb[i] == check)
			break ;
	while (swap->vetb[0] < check)
	{
		if (i == 1)
			ft_sb(swap, 0);
		else if (i <= half_len)
			ft_rb(swap, 0);
		else if (i > half_len)
			ft_rrb(swap, 0);
	}
}

static int	ft_count_min(t_swap *swap, long check)
{
	int	i;

	i = -1;
	while (++i < swap->lena)
		if (swap->veta[i] < check)
			return (1);
	return (0);
}

static void	ft_move_to_top(t_swap *swap, int i, int half_len)
{
	if (i <= half_len)
	{
		if (swap->lenb > 1 && swap->vetb[0] != ft_find_max(swap))
			ft_rr(swap);
		else
			ft_ra(swap, 0);
	}
	else if (i > half_len)
	{
		if (swap->lenb > 1 && swap->vetb[0] != ft_find_max(swap))
			ft_rrr(swap);
		else
			ft_rra(swap, 0);
	}
}

static void	ft_sort2(t_swap *swap, int min, int c_size, int c_num)
{
	int	half_len;
	int	i;

	while (ft_count_min(swap, min + c_size * c_num) > 0)
	{
		i = -1;
		half_len = swap->lena / 2;
		while (++i < swap->lena)
			if (swap->veta[i] < min + c_size * c_num)
				break ;
		while (swap->veta[0] >= min + c_size * c_num)
			ft_move_to_top(swap, i, half_len);
		if (swap->lena == 0)
			break ;
		ft_pb(swap);
	}
}

void	ft_sort(t_swap *swap, int div)
{
	int		min;
	int		max;
	int		c_size;
	int		c_num;

	if (swap->lena <= 5)
		ft_check(swap);
	min = ft_find_min(swap);
	max = ft_find_max_a(swap);
	c_size = ((max - min) / div) + 1;
	c_num = 1;
	while (c_num <= div)
	{
		ft_sort2(swap, min, c_size, c_num);
		c_num++;
	}
	while (swap->lenb > 0)
	{
		ft_bring_back(swap);
		ft_pa(swap);
	}
}
