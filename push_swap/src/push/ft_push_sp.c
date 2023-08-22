/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:46:48 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 20:10:16 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sa(t_swap *swap, int c)
{
	int	tmp;

	if (!swap->veta)
		ft_error(swap, ERR);
	tmp = swap->veta[0];
	swap->veta[0] = swap->veta[1];
	swap->veta[1] = tmp;
	if (!c)
		ft_message(swap, "sa\n");
}

void	ft_sb(t_swap *swap, int c)
{
	int	tmp;

	if (!swap->vetb)
		ft_error(swap, ERR);
	tmp = swap->vetb[0];
	swap->vetb[0] = swap->vetb[1];
	swap->vetb[1] = tmp;
	if (!c)
		ft_message(swap, "sb\n");
}

void	ft_pa(t_swap *swap)
{
	long	*a;

	if (!swap->vetb)
		return ;
	a = swap->veta;
	swap->veta = ft_intjoin(swap, swap->veta, swap->lena);
	free(a);
	swap->lena += 1;
	swap->veta[0] = swap->vetb[0];
	a = swap->vetb;
	swap->vetb = ft_intremove(swap, swap->vetb, swap->lenb);
	free(a);
	swap->lenb -= 1;
	ft_putstr("pa\n");
	swap->mov++;
}

void	ft_pb(t_swap *swap)
{
	long	*a;

	if (!swap->veta)
		return ;
	a = swap->vetb;
	swap->vetb = ft_intjoin(swap, swap->vetb, swap->lenb);
	free(a);
	swap->lenb += 1;
	swap->vetb[0] = swap->veta[0];
	a = swap->veta;
	swap->veta = ft_intremove(swap, swap->veta, swap->lena);
	free(a);
	swap->lena -= 1;
	ft_putstr("pb\n");
	swap->mov++;
}
