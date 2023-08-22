/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:58:44 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 16:59:00 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_three(t_swap *swap)
{
	int		first;
	int		second;
	int		third;

	first = swap->veta[0];
	second = swap->veta[1];
	third = swap->veta[2];
	if ((first > second) && (second > third) && (third < first))
	{
		ft_sa(swap, 0);
		ft_rra(swap, 0);
	}
	else if ((first > second) && (second < third) && (third < first))
		ft_ra(swap, 0);
	else if ((first > second) && (second < third) && (third > first))
		ft_sa(swap, 0);
	else if ((first < second) && (second > third) && (third < first))
		ft_rra(swap, 0);
	else if ((first < second) && (second > third) && (third > first))
	{
		ft_rra(swap, 0);
		ft_sa(swap, 0);
	}
}
