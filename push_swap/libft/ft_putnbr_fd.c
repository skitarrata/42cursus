/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:56:24 by grusso            #+#    #+#             */
/*   Updated: 2021/01/15 12:31:43 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	c;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		c = (unsigned int)(nb * -1);
	}
	else
		c = (unsigned int)nb;
	if (c > 9)
		ft_putnbr_fd(c / 10, fd);
	ft_putchar_fd((char)(c % 10 + '0'), fd);
}
