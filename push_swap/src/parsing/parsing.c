/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:23:32 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 18:24:07 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_parse_arg(t_swap *swap, int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc >= 2)
		while (argv[++i])
			ft_check_num(swap, argv[i]);
	else
	{
		ft_free_swap(swap);
		exit(0);
	}
}
