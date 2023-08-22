/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:54:08 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 16:43:41 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_free_swap(t_swap *swap)
{
	if (swap->veta)
		free(swap->veta);
	if (swap->vetb)
		free(swap->vetb);
	if (swap)
		free(swap);
}
