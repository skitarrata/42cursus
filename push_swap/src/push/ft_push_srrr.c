/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_srrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:54:53 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 17:37:34 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ss(t_swap *swap)
{
	ft_sa(swap, 1);
	ft_sb(swap, 1);
	ft_message(swap, "ss\n");
}

void	ft_rr(t_swap *swap)
{
	ft_ra(swap, 1);
	ft_rb(swap, 1);
	ft_message(swap, "rr\n");
}

void	ft_rrr(t_swap *swap)
{
	ft_rra(swap, 1);
	ft_rrb(swap, 1);
	ft_message(swap, "rrr\n");
}
