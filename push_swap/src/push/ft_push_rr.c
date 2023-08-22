/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:54:40 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 20:09:29 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_message(t_swap *swap, char *txt)
{
	ft_putstr(txt);
	swap->mov++;
}

void	ft_ra(t_swap *swap, int c)
{
	int	tmp;
	int	i;

	if (!swap->veta)
		ft_error(swap, ERR);
	i = -1;
	tmp = swap->veta[0];
	while (++i < swap->lena - 1)
		swap->veta[i] = swap->veta[i + 1];
	swap->veta[i] = tmp;
	if (!c)
		ft_message(swap, "ra\n");
}

void	ft_rb(t_swap *swap, int c)
{
	int	tmp;
	int	i;

	if (!swap->vetb)
		ft_error(swap, ERR);
	i = -1;
	tmp = swap->vetb[0];
	while (++i < swap->lenb - 1)
		swap->vetb[i] = swap->vetb[i + 1];
	swap->vetb[i] = tmp;
	if (!c)
		ft_message(swap, "rb\n");
}

void	ft_rra(t_swap *swap, int c)
{
	int	tmp;
	int	i;

	if (!swap->veta)
		ft_error(swap, ERR);
	i = swap->lena;
	tmp = swap->veta[i - 1];
	while (--i > 0)
		swap->veta[i] = swap->veta[i - 1];
	swap->veta[i] = tmp;
	if (!c)
		ft_message(swap, "rra\n");
}

void	ft_rrb(t_swap *swap, int c)
{
	int	tmp;
	int	i;

	if (!swap->vetb)
		ft_error(swap, ERR);
	i = swap->lenb;
	tmp = swap->vetb[i - 1];
	while (--i > 0)
		swap->vetb[i] = swap->vetb[i - 1];
	swap->vetb[i] = tmp;
	if (!c)
		ft_message(swap, "rrb\n");
}
