/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:24:13 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 19:12:22 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int argc, char *argv[])
{
	t_swap	*swap;

	swap = (t_swap *)ft_calloc(1, sizeof(t_swap));
	if (!swap)
		ft_error(swap, ERR);
	ft_parse_arg(swap, argc, argv);
	ft_init_vet(swap, argv);
	swap->vetb = NULL;
	if (swap->lena == 1)
	{
		ft_free_swap(swap);
		exit(0);
	}
	ft_which_combination(swap);
	ft_free_swap(swap);
	exit(0);
}
